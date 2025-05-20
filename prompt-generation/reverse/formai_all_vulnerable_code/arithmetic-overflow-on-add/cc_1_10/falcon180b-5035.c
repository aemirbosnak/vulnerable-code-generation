//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>

#define BUFFER_SIZE 1024
#define NUM_PINGS 5
#define PING_INTERVAL 1

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage:./ping <IP address>\n");
        return 1;
    }

    char *ip_address = argv[1];
    struct sockaddr_in server_addr;
    int sockfd, numbytes;
    struct timeval tv;
    fd_set readfds;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error opening socket\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(7);
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        close(sockfd);
        return 1;
    }

    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);

    tv.tv_sec = 0;
    tv.tv_usec = PING_INTERVAL * 1000;

    for (int i = 0; i < NUM_PINGS; i++) {
        if (select(sockfd + 1, &readfds, NULL, NULL, &tv) == -1) {
            printf("Error with select()\n");
            close(sockfd);
            return 1;
        }

        if (FD_ISSET(sockfd, &readfds)) {
            char buffer[BUFFER_SIZE];
            numbytes = recv(sockfd, buffer, BUFFER_SIZE, 0);
            if (numbytes <= 0) {
                printf("Error receiving data\n");
                close(sockfd);
                return 1;
            }
            printf("Ping %d received: %s\n", i + 1, buffer);
        } else {
            printf("Ping %d timed out\n", i + 1);
        }
    }

    close(sockfd);
    return 0;
}