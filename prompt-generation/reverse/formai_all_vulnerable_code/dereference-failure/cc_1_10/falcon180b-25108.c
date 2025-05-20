//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>

#define PORT_START 1
#define PORT_END 65535
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    int opt = 1;
    struct sockaddr_in server;
    char buffer[BUFFER_SIZE];
    int port;
    char *ip;
    int result;

    if (argc!= 3) {
        printf("Usage:./portscanner <IP Address> <Port Range>\n");
        exit(1);
    }

    ip = argv[1];
    port = atoi(argv[2]);

    if (port < PORT_START || port > PORT_END) {
        printf("Invalid port range\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(ip);
    server.sin_port = htons(port);

    result = connect(sockfd, (struct sockaddr *)&server, sizeof(server));

    if (result == -1) {
        printf("Port %d is closed\n", port);
        close(sockfd);
        exit(0);
    } else {
        printf("Port %d is open\n", port);
        close(sockfd);
        exit(0);
    }
}