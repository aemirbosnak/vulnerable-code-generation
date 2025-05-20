//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char command[BUFFER_SIZE];
    char username[BUFFER_SIZE];
    char password[BUFFER_SIZE];
    int n;
    int port = 110;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set up server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, "localhost", &server_addr.sin_addr);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Authenticate with server
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    sprintf(command, "USER %s\r\n", username);
    send(sockfd, command, strlen(command), 0);
    sprintf(command, "PASS %s\r\n", password);
    send(sockfd, command, strlen(command), 0);
    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (n <= 0) {
        printf("Error receiving response\n");
        exit(1);
    }
    buffer[n] = '\0';
    if (strncmp(buffer, "+OK", 3)!= 0) {
        printf("Error authenticating with server\n");
        exit(1);
    }

    // Retrieve messages
    printf("Enter command (STAT, LIST, RETR, DELE, QUIT): ");
    scanf("%s", command);
    send(sockfd, command, strlen(command), 0);
    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (n <= 0) {
        printf("Error receiving response\n");
        exit(1);
    }
    buffer[n] = '\0';
    printf("Response: %s", buffer);

    // Close socket
    close(sockfd);
    return 0;
}