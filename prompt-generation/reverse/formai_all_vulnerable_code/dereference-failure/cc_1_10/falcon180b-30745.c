//Falcon-180B DATASET v1.0 Category: Networking ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(1);
    }

    server = gethostbyname("localhost");

    if (server == NULL) {
        printf("Error getting hostname\n");
        exit(1);
    }

    bzero(&serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    portno = 8080;

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    while (1) {
        fgets(buffer, BUFFER_SIZE, stdin);
        n = write(sockfd, buffer, strlen(buffer));

        if (n < 0) {
            printf("Error writing to socket\n");
            exit(1);
        }

        bzero(buffer, BUFFER_SIZE);
        n = read(sockfd, buffer, BUFFER_SIZE);

        if (n < 0) {
            printf("Error reading from socket\n");
            exit(1);
        }

        printf("Server response: %s", buffer);
    }

    close(sockfd);
    return 0;
}