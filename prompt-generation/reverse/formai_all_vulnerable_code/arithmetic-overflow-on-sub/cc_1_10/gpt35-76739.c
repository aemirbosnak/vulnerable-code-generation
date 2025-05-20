//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

#define MAX_PACKET_SIZE 4096
#define DEFAULT_PING_INTERVAL 1000
#define DEFAULT_PING_TIMEOUT 1000

struct hostent *hname;
struct sockaddr_in target;
int s;
bool running = true;

void sigint_handler(int sig);

double get_signal_strength();

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Usage: %s <hostname or IP address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Initialize SIGINT handler
    struct sigaction sa;
    sa.sa_handler = sigint_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    // Get host information
    if ((hname = gethostbyname(argv[1])) == NULL) {
        printf("Could not resolve hostname: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    memcpy(&target.sin_addr.s_addr, hname->h_addr, hname->h_length);

    // Create socket
    if ((s = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set socket to non-blocking mode
    int flags = fcntl(s, F_GETFL, 0);
    fcntl(s, F_SETFL, flags | O_NONBLOCK);

    // Connect to target
    target.sin_family = AF_INET;
    target.sin_port = htons(80);
    if (connect(s, (struct sockaddr *) &target, sizeof(target)) < 0) {
        if (errno != EINPROGRESS) {
            perror("connect");
            exit(EXIT_FAILURE);
        }
    }

    // Initialize ping variables
    int interval_ms = DEFAULT_PING_INTERVAL;
    int timeout_ms = DEFAULT_PING_TIMEOUT;
    int num_packets = 0;
    double min_rtt = 0.0, max_rtt = 0.0, avg_rtt = 0.0;

    // Print header
    printf("\nWi-Fi Signal Strength Analyzer\n"
           "------------------------------\n"
           "Target: %s\n"
           "Interval: %d ms\n"
           "Timeout: %d ms\n"
           "Press Ctrl+C to stop measuring...\n\n", argv[1], interval_ms, timeout_ms);

    while (running) {
        // Calculate ping delay
        struct timeval start_time, end_time;
        gettimeofday(&start_time, NULL);
        usleep(interval_ms * 1000);
        gettimeofday(&end_time, NULL);
        double delay_ms = (end_time.tv_sec - start_time.tv_sec) * 1000.0 +
                          (end_time.tv_usec - start_time.tv_usec) / 1000.0;

        // Check if connection established
        fd_set write_fds;
        FD_ZERO(&write_fds);
        FD_SET(s, &write_fds);
        struct timeval timeout;
        timeout.tv_sec = timeout_ms / 1000;
        timeout.tv_usec = (timeout_ms % 1000) * 1000;
        int ret = select(s + 1, NULL, &write_fds, NULL, &timeout);
        if (ret < 0) {
            perror("select");
            running = false;
        } else if (ret == 0) {
            printf("Connection timed out.\n");
        } else {
            // Socket connected, measure round-trip time
            double rtt_ms = -1.0;
            FD_ZERO(&write_fds);
            FD_SET(s, &write_fds);
            if (send(s, "PING", 4, 0) == -1) {
                perror("send");
            } else {
                struct timeval start_time, end_time;
                gettimeofday(&start_time, NULL);

                FD_ZERO(&write_fds);
                FD_SET(s, &write_fds);
                struct timeval timeout;
                timeout.tv_sec = timeout_ms / 1000;
                timeout.tv_usec = (timeout_ms % 1000) * 1000;
                int ret = select(s + 1, &write_fds, NULL, NULL, &timeout);
                if (ret < 0) {
                    perror("select");
                    running = false;
                } else if (ret == 0) {
                    printf("Connection timed out.\n");
                } else {
                    char buf[MAX_PACKET_SIZE];
                    int len = 0;
                    if ((len = recv(s, buf, MAX_PACKET_SIZE, 0)) == -1) {
                        perror("recv");
                    } else {
                        gettimeofday(&end_time, NULL);
                        rtt_ms = (end_time.tv_sec - start_time.tv_sec) * 1000.0 +
                                 (end_time.tv_usec - start_time.tv_usec) / 1000.0;
                        printf("Packet size: %d bytes, ", len);
                        printf("RTT: %.2f ms\n", rtt_ms);
                    }
                }
            }

            // Update ping statistics
            if (rtt_ms > 0) {
                num_packets++;
                if (num_packets == 1) {
                    min_rtt = max_rtt = avg_rtt = rtt_ms;
                } else {
                    if (rtt_ms < min_rtt) {
                        min_rtt = rtt_ms;
                    }
                    if (rtt_ms > max_rtt) {
                        max_rtt = rtt_ms;
                    }
                    avg_rtt = ((num_packets - 1) * avg_rtt + rtt_ms) / num_packets;
                }
            }
        }

        // Get signal strength and print statistics
        double signal_strength = get_signal_strength();
        if (signal_strength != -1.0) {
            printf("Signal strength: %.2f dBm, ", signal_strength);
        }
        printf("Packets sent: %d, ", num_packets);
        if (num_packets > 0) {
            printf("Min RTT: %.2f ms, Max RTT: %.2f ms, Avg RTT: %.2f ms\n", min_rtt, max_rtt, avg_rtt);
        } else {
            printf("\n");
        }
    }

    // Close socket
    close(s);

    return 0;
}

void sigint_handler(int sig) {
    running = false;
}

double get_signal_strength() {
    FILE *fp;
    char buf[1024];
    double signal_strength = -1.0;

    fp = popen("iwconfig wlan0 | grep Signal | cut -d'=' -f3 | cut -d' ' -f1", "r");
    if (fp != NULL) {
        if (fgets(buf, sizeof(buf), fp) != NULL) {
            signal_strength = atof(buf);
        }
        pclose(fp);
    } else {
        perror("popen");
    }

    return signal_strength;
}