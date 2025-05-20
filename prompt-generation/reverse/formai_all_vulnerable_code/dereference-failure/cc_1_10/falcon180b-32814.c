//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in serv_addr;
    char *hostname;
    char buffer[BUF_SIZE];
    int portno;
    int addrlen;
    struct hostent *server;

    if (argc!= 3) {
        printf("Usage: %s <hostname/IP> <port number>\n", argv[0]);
        return 1;
    }

    hostname = argv[1];
    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error opening socket\n");
        return 1;
    }

    server = gethostbyname(hostname);
    if (server == NULL) {
        printf("Error getting hostname\n");
        return 1;
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy(server->h_addr, &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        return 1;
    }

    printf("Connected to server\n");

    while (1) {
        bzero(buffer, BUF_SIZE);
        fgets(buffer, BUF_SIZE, stdin);

        if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
            printf("Error sending data\n");
            return 1;
        }

        addrlen = sizeof(serv_addr);
        if (recv(sockfd, buffer, BUF_SIZE, 0) < 0) {
            printf("Error receiving data\n");
            return 1;
        }

        printf("Received from server: %s", buffer);
    }

    close(sockfd);
    return 0;
}