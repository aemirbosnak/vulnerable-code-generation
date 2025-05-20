//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <time.h>
#include <errno.h>

#define PACKET_SIZE 64
#define PING_COUNT 10
#define TIMEOUT 1

// Function to ping a host and measure round-trip time
double ping(const char *host) {
    struct sockaddr_in addr;
    struct timeval start, end;
    int sock, n;
    double rtt;
    char command[100];
    sprintf(command, "ping -c 1 -W %d %s > /dev/null", TIMEOUT, host);

    gettimeofday(&start, NULL);
    n = system(command);
    gettimeofday(&end, NULL);

    if (n == 0) {
        rtt = ((end.tv_sec - start.tv_sec) * 1000.0) + ((end.tv_usec - start.tv_usec) / 1000.0);
        return rtt;
    } else {
        return -1.0; // Indicate that the ping failed
    }
}

// Function to calculate average RTT
double average_rtt(const char *host) {
    double total_rtt = 0.0;
    int successful_pings = 0;

    for (int i = 0; i < PING_COUNT; i++) {
        double rtt = ping(host);
        if (rtt != -1) {
            total_rtt += rtt;
            successful_pings++;
            printf("Ping %d: RTT = %.2f ms\n", i + 1, rtt);
        } else {
            printf("Ping %d: Failed to reach %s\n", i + 1, host);
        }
        sleep(1); // Wait for a second before next ping
    }

    if (successful_pings > 0) {
        return total_rtt / successful_pings;
    } else {
        return -1.0; // Indicate that all pings failed
    }
}

// Function to check packet loss
double packet_loss(const char *host) {
    int lost_packets = 0;

    for (int i = 0; i < PING_COUNT; i++) {
        if (ping(host) == -1.0) {
            lost_packets++;
        }
        sleep(1); // Wait for a second before next ping
    }

    return ((double)lost_packets / PING_COUNT) * 100; // Return % of packet loss
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *host = argv[1];
    double avg_rtt = average_rtt(host);
    double loss = packet_loss(host);

    if (avg_rtt != -1.0) {
        printf("Average RTT to %s: %.2f ms\n", host, avg_rtt);
    } else {
        printf("All pings failed to %s.\n", host);
    }

    printf("Packet Loss to %s: %.2f%%\n", host, loss);

    return 0;
}