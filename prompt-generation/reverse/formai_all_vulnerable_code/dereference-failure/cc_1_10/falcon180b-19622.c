//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024
#define TRUE 1
#define FALSE 0

int main(int argc, char *argv[]) {
    int sockfd, port, protocol, opt = TRUE;
    struct sockaddr_in server;
    char buffer[BUFFER_SIZE];

    if (argc!= 4) {
        printf("Usage: %s <IP Address> <Port Range> <TCP/UDP>\n", argv[0]);
        return 1;
    }

    strcpy(server.sin_zero, "");
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    server.sin_addr.s_addr = inet_addr(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    if (strcmp(argv[3], "TCP") == 0) {
        protocol = IPPROTO_TCP;
    } else if (strcmp(argv[3], "UDP") == 0) {
        protocol = IPPROTO_UDP;
    } else {
        printf("Invalid protocol\n");
        close(sockfd);
        return 1;
    }

    for (port = 1; port <= MAX_PORTS; port++) {
        if (opt) {
            setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt));
            opt = FALSE;
        }

        if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) == -1) {
            if (errno == ECONNREFUSED) {
                printf("%d - Port is closed\n", port);
            } else if (errno == ETIMEDOUT) {
                printf("%d - Connection timed out\n", port);
            } else {
                printf("%d - Error connecting to port\n", port);
            }
        } else {
            printf("%d - Port is open\n", port);
            close(sockfd);
            return 0;
        }

        close(sockfd);
        sockfd = socket(AF_INET, SOCK_STREAM, protocol);
    }

    printf("All ports are closed\n");
    close(sockfd);
    return 0;
}