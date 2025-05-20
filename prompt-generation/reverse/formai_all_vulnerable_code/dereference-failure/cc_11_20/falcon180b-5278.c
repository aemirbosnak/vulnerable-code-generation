//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sockfd, ret, opt = 1, timeout = 5;
    struct sockaddr_in dest_addr;
    char *ip_address = argv[1];
    char *dest_ip;
    int dest_port = atoi(argv[2]);
    char buffer[1024];

    if (argc!= 4) {
        printf("Usage:./ping_test <destination_ip> <destination_port>\n");
        return 1;
    }

    dest_ip = strdup(ip_address);
    if (dest_ip == NULL) {
        printf("Error: Invalid IP address.\n");
        return 1;
    }

    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(dest_port);
    inet_pton(AF_INET, dest_ip, &dest_addr.sin_addr);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: Failed to create socket.\n");
        return 1;
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout))) {
        printf("Error: Failed to set receive timeout.\n");
        close(sockfd);
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *)&dest_addr, sizeof(dest_addr))!= 0) {
        if (errno == ECONNREFUSED) {
            printf("Destination unreachable.\n");
        } else if (errno == ETIMEDOUT) {
            printf("Request timed out.\n");
        } else {
            printf("Error: Failed to connect to destination.\n");
        }
        close(sockfd);
        return 1;
    }

    if (send(sockfd, "PING", strlen("PING"), 0) == -1) {
        printf("Error: Failed to send PING message.\n");
        close(sockfd);
        return 1;
    }

    ret = recv(sockfd, buffer, sizeof(buffer), 0);
    if (ret == -1) {
        printf("Error: Failed to receive response.\n");
        close(sockfd);
        return 1;
    } else if (ret == 0) {
        printf("Destination unreachable.\n");
    } else {
        buffer[ret] = '\0';
        if (strcmp(buffer, "PONG") == 0) {
            printf("PONG received.\n");
        } else {
            printf("Unexpected response received: %s\n", buffer);
        }
    }

    close(sockfd);
    return 0;
}