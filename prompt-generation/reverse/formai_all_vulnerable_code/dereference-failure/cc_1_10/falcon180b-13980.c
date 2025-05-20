//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define MAX_RETRIES 3
#define RETRY_DELAY_MS 100

int ping_host(const char* hostname, int port, int retries) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: failed to create socket.\n");
        return -1;
    }

    struct addrinfo hints, *servinfo = NULL;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    if ((getaddrinfo(hostname, NULL, &hints, &servinfo))!= 0) {
        printf("Error: failed to resolve hostname.\n");
        close(sockfd);
        return -1;
    }

    struct sockaddr* addr = servinfo->ai_addr;
    int addrlen = servinfo->ai_addrlen;

    if (connect(sockfd, addr, addrlen) == -1) {
        if (errno == ECONNREFUSED) {
            printf("Host is down.\n");
        } else if (errno == EHOSTUNREACH) {
            printf("No route to host.\n");
        } else if (errno == ETIMEDOUT) {
            printf("Connection timed out.\n");
        } else {
            printf("Error: failed to connect to host.\n");
        }

        close(sockfd);
        return -1;
    }

    char buffer[BUFFER_SIZE];
    while (1) {
        int bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            if (bytes_received == 0) {
                printf("Host is down.\n");
            } else if (errno == ECONNRESET) {
                printf("Connection reset by peer.\n");
            } else if (errno == EPIPE) {
                printf("Broken pipe.\n");
            } else {
                printf("Error: failed to receive data from host.\n");
            }

            close(sockfd);
            return -1;
        }

        if (retries > 0 && strstr(buffer, "PONG") == NULL) {
            retries--;
            usleep(RETRY_DELAY_MS * 1000);
            continue;
        }

        printf("PONG received.\n");
        close(sockfd);
        return 0;
    }
}

int main() {
    char* hostname = "example.com";
    int port = 80;
    int retries = MAX_RETRIES;

    int result = ping_host(hostname, port, retries);
    if (result == 0) {
        printf("Ping successful.\n");
    } else {
        printf("Ping failed.\n");
    }

    return 0;
}