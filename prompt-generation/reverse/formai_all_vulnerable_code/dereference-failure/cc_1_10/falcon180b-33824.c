//Falcon-180B DATASET v1.0 Category: Networking ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void error_handling(char *message) {
    perror(message);
    exit(1);
}

int main() {
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];
    socklen_t clilen;
    struct hostent *server;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == 0)
        error_handling("socket failed");

    server = gethostbyname("localhost");
    if (server == NULL) {
        printf("No such host\n");
        exit(1);
    }

    // Fill server address structure
    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(8080);

    // Connect to remote server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error_handling("connect failed");

    printf("Connected to server\n");

    // Send data to server
    portno = 8080;
    while (1) {
        printf("Enter message: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        send(sockfd, buffer, strlen(buffer), 0);
    }

    // Receive data from server
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
    if (newsockfd < 0)
        error_handling("accept failed");

    printf("Connection accepted\n");

    while (1) {
        bzero(buffer, BUFFER_SIZE);
        read(newsockfd, buffer, BUFFER_SIZE);
        printf("Received message: %s", buffer);
    }

    return 0;
}