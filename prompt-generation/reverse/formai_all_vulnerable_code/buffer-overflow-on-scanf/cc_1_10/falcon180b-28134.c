//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char username[50];
    char password[50];
    char command[MAX_LINE];
    char response[MAX_LINE];
    int n;

    // Get user input for username and password
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    // Connect to POP3 server
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(110);
    inet_pton(AF_INET, "localhost", &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Send USER command
    sprintf(command, "USER %s\r\n", username);
    write(sockfd, command, strlen(command));

    // Receive server response
    memset(response, 0, MAX_LINE);
    n = read(sockfd, response, MAX_LINE);
    printf("Server response: %s", response);

    // Send PASS command
    sprintf(command, "PASS %s\r\n", password);
    write(sockfd, command, strlen(command));

    // Receive server response
    memset(response, 0, MAX_LINE);
    n = read(sockfd, response, MAX_LINE);
    printf("Server response: %s", response);

    // Send STAT command
    sprintf(command, "STAT\r\n");
    write(sockfd, command, strlen(command));

    // Receive server response
    memset(response, 0, MAX_LINE);
    n = read(sockfd, response, MAX_LINE);
    printf("Server response: %s", response);

    // Close socket
    close(sockfd);

    return 0;
}