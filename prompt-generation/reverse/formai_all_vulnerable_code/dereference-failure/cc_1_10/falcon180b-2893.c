//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define MAX_THREADS 100
#define BUFFER_SIZE 1024

int scan_port(int sockfd, struct sockaddr_in *address, int port);
void *thread_scan_port(void *arg);

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Port Range>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    int port_range = atoi(argv[2]);

    struct addrinfo hints, *result, *rp;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(ip_address, NULL, &hints, &result)!= 0) {
        printf("Failed to resolve IP address: %s\n", gai_strerror(errno));
        return 1;
    }

    int num_threads = 0;
    pthread_t threads[MAX_THREADS];

    for (rp = result; rp!= NULL; rp = rp->ai_next) {
        if (rp->ai_family == AF_INET) {
            struct sockaddr_in *address = (struct sockaddr_in *) rp->ai_addr;
            address->sin_port = htons(port_range);

            if (pthread_create(&threads[num_threads], NULL, thread_scan_port, (void *) address)!= 0) {
                printf("Failed to create thread: %s\n", strerror(errno));
                return 1;
            }

            num_threads++;
        }
    }

    for (int i = 0; i < num_threads; i++) {
        if (pthread_join(threads[i], NULL)!= 0) {
            printf("Failed to join thread: %s\n", strerror(errno));
            return 1;
        }
    }

    freeaddrinfo(result);

    return 0;
}

int scan_port(int sockfd, struct sockaddr_in *address, int port) {
    if (connect(sockfd, (struct sockaddr *) address, sizeof(struct sockaddr_in)) == 0) {
        close(sockfd);
        printf("Port %d is open\n", port);
        return 1;
    } else if (errno == ECONNREFUSED) {
        close(sockfd);
        printf("Port %d is closed\n", port);
        return 0;
    } else {
        close(sockfd);
        printf("Failed to connect to port %d: %s\n", port, strerror(errno));
        return -1;
    }
}

void *thread_scan_port(void *arg) {
    struct sockaddr_in *address = (struct sockaddr_in *) arg;
    int port = address->sin_port;

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Failed to create socket: %s\n", strerror(errno));
        return NULL;
    }

    scan_port(sockfd, address, port);

    close(sockfd);
    return NULL;
}