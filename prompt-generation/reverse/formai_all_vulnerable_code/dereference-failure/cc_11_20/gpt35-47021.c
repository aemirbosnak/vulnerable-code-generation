//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: irregular
//An IMAP client in C
//Disclaimer: This code is not a safe and secure way to interact with an IMAP server. 
//It's meant purely as an example and should not be used in production without proper authentication and encryption.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024 //Max length of buffer
#define PORT 993 //IMAP port

int main(int argc, char **argv) {

    int sockfd;
    char buffer[BUFFER_SIZE];
    char command[BUFFER_SIZE];
    struct sockaddr_in server;

    //Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        return EXIT_FAILURE;
    }

    //Set socket timeout
    struct timeval timeout;
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char *)&timeout, sizeof(timeout)) < 0) {
        perror("Setsockopt error");
        return EXIT_FAILURE;
    }

    //Configure server address
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    if (inet_pton(AF_INET, "127.0.0.1", &server.sin_addr) <= 0) {
        perror("Invalid address or address not supported");
        return EXIT_FAILURE;
    }

    //Connect to server
    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Connection error");
        return EXIT_FAILURE;
    }

    //Read server greeting
    bzero(buffer, BUFFER_SIZE);
    if (read(sockfd, buffer, BUFFER_SIZE) < 0) {
        perror("Read error");
        return EXIT_FAILURE;
    }
    printf("%s", buffer);

    //Send login credentials
    sprintf(command, "tag login username password\r\n");
    if (send(sockfd, command, strlen(command), 0) < 0) {
        perror("Send error");
        return EXIT_FAILURE;
    }

    //Read server response
    bzero(buffer, BUFFER_SIZE);
    if (read(sockfd, buffer, BUFFER_SIZE) < 0) {
        perror("Read error");
        return EXIT_FAILURE;
    }
    printf("%s", buffer);

    //Send "list" command to list all mailboxes
    sprintf(command, "tag list \"\" *\r\n");
    if (send(sockfd, command, strlen(command), 0) < 0) {
        perror("Send error");
        return EXIT_FAILURE;
    }

    //Read server response
    bzero(buffer, BUFFER_SIZE);
    if (read(sockfd, buffer, BUFFER_SIZE) < 0) {
        perror("Read error");
        return EXIT_FAILURE;
    }
    printf("%s", buffer);

    //Send "select" command to select Inbox mailbox
    sprintf(command, "tag select Inbox\r\n");
    if (send(sockfd, command, strlen(command), 0) < 0) {
        perror("Send error");
        return EXIT_FAILURE;
    }

    //Read server response
    bzero(buffer, BUFFER_SIZE);
    if (read(sockfd, buffer, BUFFER_SIZE) < 0) {
        perror("Read error");
        return EXIT_FAILURE;
    }
    printf("%s", buffer);

    //Send "fetch" command to fetch messages in Inbox
    sprintf(command, "tag fetch 1:* (body[header.fields (subject from)])\r\n");
    if (send(sockfd, command, strlen(command), 0) < 0) {
        perror("Send error");
        return EXIT_FAILURE;
    }

    //Read server response
    bzero(buffer, BUFFER_SIZE);
    if (read(sockfd, buffer, BUFFER_SIZE) < 0) {
        perror("Read error");
        return EXIT_FAILURE;
    }
    printf("%s", buffer);

    //Send "logout" command to logout
    sprintf(command, "tag logout\r\n");
    if (send(sockfd, command, strlen(command), 0) < 0) {
        perror("Send error");
        return EXIT_FAILURE;
    }

    //Read server response
    bzero(buffer, BUFFER_SIZE);
    if (read(sockfd, buffer, BUFFER_SIZE) < 0) {
        perror("Read error");
        return EXIT_FAILURE;
    }
    printf("%s", buffer);

    //Close socket
    close(sockfd);

    return EXIT_SUCCESS;
}