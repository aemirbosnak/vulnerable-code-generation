//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define POP3_PORT 110

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char username[50];
    char password[50];
    char command[MAX_COMMAND_LENGTH];

    // Get user input for POP3 server address, username, and password
    printf("Enter POP3 server address: ");
    scanf("%s", &server_addr.sin_addr.s_addr);
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    // Authenticate with server
    sprintf(command, "USER %s\r\n", username);
    send(sockfd, command, strlen(command), 0);
    recv(sockfd, command, MAX_COMMAND_LENGTH, 0);

    sprintf(command, "PASS %s\r\n", password);
    send(sockfd, command, strlen(command), 0);
    recv(sockfd, command, MAX_COMMAND_LENGTH, 0);

    // Retrieve number of messages
    sprintf(command, "STAT\r\n");
    send(sockfd, command, strlen(command), 0);
    recv(sockfd, command, MAX_COMMAND_LENGTH, 0);

    // Retrieve message headers
    for (int i = 1; i <= atoi(command); i++) {
        sprintf(command, "LIST %d\r\n", i);
        send(sockfd, command, strlen(command), 0);
        recv(sockfd, command, MAX_COMMAND_LENGTH, 0);
        printf("%s", command);
    }

    // Close socket
    close(sockfd);

    return 0;
}