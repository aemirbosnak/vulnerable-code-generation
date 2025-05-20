//FormAI DATASET v1.0 Category: Socket programming ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
    int sockfd, newsockfd, portno, clilen;

    struct sockaddr_in serv_addr, cli_addr;

    char buffer[256];

    int n;

    printf("Welcome to the Socket Programming Puzzler!\n");

    printf("First we need a port number. Enter a number between 1024 to 65535 to use: \n");
    scanf("%d", &portno);

    printf("Creating a socket...\n");

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Socket creation failed.\n");
        exit(1);
    }

    printf("Socket created successfully.\n");

    printf("Binding socket to port %d...\n", portno);

    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("Binding failed.\n");
        exit(1);
    }

    printf("Binding successful.\n");

    printf("Listening for incomming connections...\n");

    listen(sockfd, 5);

    clilen = sizeof(cli_addr);

    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

    if (newsockfd < 0) {
        printf("Error accepting connection.\n");
        exit(1);
    }

    printf("Connection accepted.\n");

    printf("Enter the secret code to begin the challenge:\n");
    scanf("%s", buffer);

    n = write(newsockfd, buffer, strlen(buffer));

    if (n < 0) {
        printf("Error writing to socket.\n");
        exit(1);
    }

    printf("Waiting for response...\n");

    memset(&buffer, 0, sizeof(buffer));

    n = read(newsockfd, buffer, sizeof(buffer));

    if (n < 0) {
        printf("Error reading from socket.\n");
        exit(1);
    }

    printf("Received response: %s\n", buffer);

    if (!strcmp(buffer, "The Answer is: 42")) {
        printf("Congratulations! You solved the Socket Programming Puzzler!\n");
    } else {
        printf("Sorry, incorrect. Better luck next time.\n");
    }

    return 0;
}