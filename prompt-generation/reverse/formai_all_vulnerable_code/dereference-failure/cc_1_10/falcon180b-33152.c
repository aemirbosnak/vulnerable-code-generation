//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX 65535
#define TRUE 1
#define FALSE 0
#define PORT_NOT_OPEN "Port is not open"

int main(int argc, char *argv[]) {
    int sockfd, portno, clilen, i;
    char buffer[1024];
    struct sockaddr_in server;
    struct sockaddr_in client;
    int opt = 1;
    int addrlen = sizeof(client);

    if (argc!= 3) {
        printf("Usage:./port_scanner <IP Address> <Port Range>\n");
        return 0;
    }

    if (inet_pton(AF_INET, argv[1], &server.sin_addr) <= 0) {
        printf("Invalid IP Address\n");
        return 0;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 0;
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    for (portno = atoi(argv[2]); portno <= MAX; portno++) {
        client.sin_family = AF_INET;
        client.sin_addr.s_addr = inet_addr(argv[1]);
        client.sin_port = htons(portno);

        if (connect(sockfd, (struct sockaddr *)&client, sizeof(client)) == -1) {
            if (errno == ECONNREFUSED) {
                printf("%d - Port is not open\n", portno);
            } else if (errno == ECONNRESET) {
                printf("%d - Port is closed\n", portno);
            } else if (errno == ETIMEDOUT) {
                printf("%d - Port is filtered\n", portno);
            } else {
                printf("%d - Error connecting to port\n", portno);
            }
        } else {
            printf("%d - Port is open\n", portno);
        }
    }

    close(sockfd);
    return 0;
}