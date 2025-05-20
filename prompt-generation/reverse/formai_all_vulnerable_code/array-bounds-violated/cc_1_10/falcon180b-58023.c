//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define POP3_PORT 110
#define USERNAME "your_username"
#define PASSWORD "your_password"

int main(int argc, char *argv[]) {
    int sockfd, retval;
    struct sockaddr_in server_addr;
    char *host = "pop.gmail.com";
    char buffer[BUFFER_SIZE];
    int nbytes, bytes_read;
    char username[50];
    char password[50];
    char command[50];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Connect to server
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    inet_pton(AF_INET, host, &server_addr.sin_addr);

    retval = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (retval == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Send username and password
    sprintf(command, "USER %s\r\n", USERNAME);
    send(sockfd, command, strlen(command), 0);

    sprintf(command, "PASS %s\r\n", PASSWORD);
    send(sockfd, command, strlen(command), 0);

    // Receive server response
    nbytes = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (nbytes <= 0) {
        printf("Error receiving data from server\n");
        exit(1);
    }

    printf("Server response: %s", buffer);

    // Send LIST command
    sprintf(command, "LIST\r\n");
    send(sockfd, command, strlen(command), 0);

    // Receive server response
    nbytes = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (nbytes <= 0) {
        printf("Error receiving data from server\n");
        exit(1);
    }

    printf("Server response: %s", buffer);

    // Send RETR command
    sprintf(command, "RETR 1\r\n");
    send(sockfd, command, strlen(command), 0);

    // Receive server response
    nbytes = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (nbytes <= 0) {
        printf("Error receiving data from server\n");
        exit(1);
    }

    printf("Server response: %s", buffer);

    // Receive email message
    bytes_read = 0;
    while ((nbytes = recv(sockfd, buffer + bytes_read, BUFFER_SIZE - bytes_read, 0)) > 0) {
        bytes_read += nbytes;
        buffer[bytes_read] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}