//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define POP3_PORT 110

int main(int argc, char **argv) {

    if (argc != 3) {
        printf("Usage: %s hostname username\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int sockfd;
    struct sockaddr_in servaddr;

    char buffer[BUFFER_SIZE];

    // Creating socket file descriptor
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Socket creation failed...\n");
        exit(EXIT_FAILURE);
    }
    else {
        printf("Socket successfully created..\n");
    }

    bzero(&servaddr, sizeof(servaddr));

    // Filling server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(POP3_PORT);
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);

    // Connect the client socket to server socket
    if (connect(sockfd, (struct sockaddr*) &servaddr, sizeof(servaddr)) != 0) {
        printf("Connection with the server failed...\n");
        exit(EXIT_FAILURE);
    }
    else {
        printf("Connected to the server..\n");
    }

    // Read the server welcome message
    bzero(&buffer, BUFFER_SIZE);
    read(sockfd, buffer, BUFFER_SIZE);
    printf("%s\n", buffer);

    // Send USER command
    bzero(&buffer, BUFFER_SIZE);
    sprintf(buffer, "USER %s\r\n", argv[2]);
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, BUFFER_SIZE);
    printf("%s\n", buffer);

    // Send PASS command
    char password[BUFFER_SIZE];
    printf("Enter password: ");
    scanf("%s", password);
    bzero(&buffer, BUFFER_SIZE);
    sprintf(buffer, "PASS %s\r\n", password);
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, BUFFER_SIZE);
    printf("%s\n", buffer);

    // Send STAT command
    bzero(&buffer, BUFFER_SIZE);
    sprintf(buffer, "STAT\r\n");
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, BUFFER_SIZE);
    printf("%s\n", buffer);

    // Send LIST command
    bzero(&buffer, BUFFER_SIZE);
    sprintf(buffer, "LIST\r\n");
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, BUFFER_SIZE);
    printf("%s\n", buffer);

    // Send RETR command
    int mail_id;
    printf("Enter mail id to retrieve: ");
    scanf("%d", &mail_id);
    bzero(&buffer, BUFFER_SIZE);
    sprintf(buffer, "RETR %d\r\n", mail_id);
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, BUFFER_SIZE);
    printf("%s\n", buffer);

    // Send QUIT command
    bzero(&buffer, BUFFER_SIZE);
    sprintf(buffer, "QUIT\r\n");
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, BUFFER_SIZE);
    printf("%s\n", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}