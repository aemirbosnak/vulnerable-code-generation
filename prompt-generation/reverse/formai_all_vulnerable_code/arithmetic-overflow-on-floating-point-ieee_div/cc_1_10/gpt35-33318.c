//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>
#include <signal.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define DEFAULT_PORT 5001
#define DEFAULT_DELAY 1000000
#define DEFAULT_RETRIES 10

volatile sig_atomic_t should_stop = 0;

void handle_signal(int sig) {
    should_stop = 1;
}

void print_error(char *msg) {
    fprintf(stderr, "Error: %s (%s)\n", msg, strerror(errno));
}

int main(int argc, char **argv) {
    int sockfd, port, retries, delay, i;
    char buffer[BUFFER_SIZE];
    struct hostent *host;
    struct sockaddr_in addr;
    struct sigaction sa;
    fd_set readfds;
    struct timeval timeout;
    time_t start, end;
    double elapsed_time, speed;

    if(argc < 2) {
        fprintf(stderr, "Usage: %s <hostname> [options]\n", argv[0]);
        fprintf(stderr, "Options:\n");
        fprintf(stderr, "    -p, --port <port>      : Port number to use (default: %d)\n", DEFAULT_PORT);
        fprintf(stderr, "    -d, --delay <microsec> : Delay between retries (default: %d microseconds)\n", DEFAULT_DELAY);
        fprintf(stderr, "    -r, --retries <count>  : Number of retries (default: %d)\n", DEFAULT_RETRIES);
        return 1;
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;

    host = gethostbyname(argv[1]);
    if(host == NULL) {
        print_error("Could not resolve hostname");
        return 2;
    }

    memcpy(&addr.sin_addr, host->h_addr, host->h_length);

    for(i = 2; i < argc; i++) {
        if(strcmp(argv[i], "-p") == 0 || strcmp(argv[i], "--port") == 0) {
            if(i == argc - 1) {
                fprintf(stderr, "Error: Missing port number\n");
                return 3;
            }
            port = atoi(argv[i + 1]);
            if(port <= 0 || port >= 65536) {
                fprintf(stderr, "Error: Invalid port number: %s\n", argv[i + 1]);
                return 4;
            }
            addr.sin_port = htons(port);
            i++;
        } else if(strcmp(argv[i], "-d") == 0 || strcmp(argv[i], "--delay") == 0) {
            if(i == argc - 1) {
                fprintf(stderr, "Error: Missing delay value\n");
                return 5;
            }
            delay = atoi(argv[i + 1]);
            if(delay <= 0) {
                fprintf(stderr, "Error: Invalid delay value: %s\n", argv[i + 1]);
                return 6;
            }
            i++;
        } else if(strcmp(argv[i], "-r") == 0 || strcmp(argv[i], "--retries") == 0) {
            if(i == argc - 1) {
                fprintf(stderr, "Error: Missing retry count\n");
                return 7;
            }
            retries = atoi(argv[i + 1]);
            if(retries <= 0) {
                fprintf(stderr, "Error: Invalid retry count: %s\n", argv[i + 1]);
                return 8;
            }
            i++;
        } else {
            fprintf(stderr, "Error: Invalid option: %s\n", argv[i]);
            return 9;
        }
    }

    if(addr.sin_port == 0) {
        addr.sin_port = htons(DEFAULT_PORT);
    }
    if(delay == 0) {
        delay = DEFAULT_DELAY;
    }
    if(retries == 0) {
        retries = DEFAULT_RETRIES;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        print_error("Could not create socket");
        return 10;
    }

    if(connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        print_error("Could not connect");
        close(sockfd);
        return 11;
    }

    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = handle_signal;
    sa.sa_flags = SA_RESTART;
    sigaction(SIGINT, &sa, NULL);

    time(&start);
    printf("Testing network quality...\n");
    for(i = 0; i < retries && !should_stop; i++) {
        sprintf(buffer, "PING %d\n", i);
        if(write(sockfd, buffer, strlen(buffer)) < 0) {
            print_error("Could not write to socket");
            close(sockfd);
            return 12;
        }

        FD_ZERO(&readfds);
        FD_SET(sockfd, &readfds);
        timeout.tv_sec = 0;
        timeout.tv_usec = delay;

        if(select(sockfd + 1, &readfds, NULL, NULL, &timeout) < 0) {
            print_error("Could not select");
            close(sockfd);
            return 13;
        }

        if(FD_ISSET(sockfd, &readfds)) {
            if(read(sockfd, buffer, BUFFER_SIZE) < 0) {
                print_error("Could not read from socket");
                close(sockfd);
                return 14;
            }
            buffer[BUFFER_SIZE - 1] = '\0';
            printf("Received: %s", buffer);
        } else {
            printf("Timeout\n");
        }
    }
    time(&end);

    elapsed_time = difftime(end, start);
    speed = (double)(retries / elapsed_time);

    printf("Test complete:\n");
    printf("    Total time: %.2f seconds\n", elapsed_time);
    printf("    Average speed: %.2f pings/second\n", speed);

    close(sockfd);
    return 0;
}