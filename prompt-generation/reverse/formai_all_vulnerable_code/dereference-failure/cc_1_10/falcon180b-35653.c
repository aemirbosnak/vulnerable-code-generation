//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        exit(1);
    }

    char *ip_address = argv[1];
    struct sockaddr_in target_addr;
    int sockfd, retval;
    char buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Socket creation failed: %s\n", strerror(errno));
        exit(1);
    }

    memset(&target_addr, 0, sizeof(target_addr));
    target_addr.sin_family = AF_INET;
    target_addr.sin_port = htons(7);

    retval = inet_pton(AF_INET, ip_address, &target_addr.sin_addr);
    if (retval == 0) {
        printf("Invalid IP address: %s\n", ip_address);
        exit(1);
    }

    retval = connect(sockfd, (struct sockaddr *)&target_addr, sizeof(target_addr));
    if (retval == -1) {
        printf("Connection failed: %s\n", strerror(errno));
        exit(1);
    }

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        retval = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (retval == 0) {
            printf("Connection closed by server\n");
            break;
        } else if (retval == -1) {
            printf("Recv failed: %s\n", strerror(errno));
            break;
        }

        printf("Received data: %s", buffer);
    }

    close(sockfd);
    return 0;
}