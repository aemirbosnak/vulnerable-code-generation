//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535

int main(int argc, char *argv[]) {
    int sockfd, numbytes;
    struct sockaddr_in serv_addr;
    int opt = 1;
    char buffer[1025];
    int port;

    if (argc!= 3) {
        printf("Usage:./portscanner <IP Address> <Port Range>\n");
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error: Could not create socket.\n");
        return 1;
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        printf("Error: Could not set socket option.\n");
        return 1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: Could not connect to %s:%s.\n", argv[1], argv[2]);
        return 1;
    }

    for (port = 1; port <= MAX_PORTS; port++) {
        if (port == atoi(argv[2]))
            continue;

        serv_addr.sin_port = htons(port);

        if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == 0) {
            printf("Port %d is open.\n", port);
        } else {
            printf("Port %d is closed.\n", port);
        }
    }

    close(sockfd);

    return 0;
}