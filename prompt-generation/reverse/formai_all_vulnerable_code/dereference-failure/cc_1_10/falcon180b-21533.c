//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n, addrlen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX_SIZE];
    struct hostent *server;

    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Port Number>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);
    addrlen = sizeof(struct sockaddr_in);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(1);
    }

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        printf("Error getting host by name\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr = *(struct in_addr *)server->h_addr;

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    while (1) {
        bzero(buffer, MAX_SIZE);

        n = recv(sockfd, buffer, MAX_SIZE, 0);

        if (n <= 0) {
            printf("Error receiving data\n");
            exit(1);
        }

        printf("Received data: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}