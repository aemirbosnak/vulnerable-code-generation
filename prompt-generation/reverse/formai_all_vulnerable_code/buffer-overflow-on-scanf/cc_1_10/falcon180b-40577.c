//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

#define MAX_COMMAND_LENGTH 512
#define MAX_RESPONSE_LENGTH 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in serveraddr;
    char username[64];
    char password[64];
    char command[MAX_COMMAND_LENGTH];
    char response[MAX_RESPONSE_LENGTH];
    int n;

    // Get user input for server address, port, username and password
    printf("Enter POP3 server address: ");
    scanf("%s", inet_ntoa(serveraddr.sin_addr));
    printf("Enter POP3 server port: ");
    scanf("%d", &(serveraddr.sin_port));
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket failed");
        exit(1);
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1) {
        perror("connect failed");
        exit(1);
    }

    // Authenticate with server
    sprintf(command, "USER %s\r\n", username);
    send(sockfd, command, strlen(command), 0);
    n = recv(sockfd, response, MAX_RESPONSE_LENGTH, 0);
    response[n] = '\0';
    printf("Server response: %s", response);

    sprintf(command, "PASS %s\r\n", password);
    send(sockfd, command, strlen(command), 0);
    n = recv(sockfd, response, MAX_RESPONSE_LENGTH, 0);
    response[n] = '\0';
    printf("Server response: %s", response);

    // Send commands to server and receive responses
    while (1) {
        printf("Enter POP3 command: ");
        scanf("%s", command);
        if (strcmp(command, "QUIT") == 0) {
            break;
        }
        send(sockfd, command, strlen(command), 0);
        n = recv(sockfd, response, MAX_RESPONSE_LENGTH, 0);
        response[n] = '\0';
        printf("Server response: %s", response);
    }

    // Close socket
    close(sockfd);
    return 0;
}