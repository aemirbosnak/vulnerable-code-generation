//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <ctype.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 110
#define SERVER_ADDRESS "localhost"

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char username[50];
    char password[50];
    char command[50];
    int n;

    // Initialize socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: could not create socket\n");
        exit(1);
    }

    // Set up server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_ADDRESS);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: could not connect to server\n");
        exit(1);
    }

    // Authenticate with server
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    sprintf(command, "USER %s\r\n", username);
    send(sockfd, command, strlen(command), 0);
    memset(buffer, 0, BUFFER_SIZE);
    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    buffer[n] = '\0';
    printf("Server response: %s\n", buffer);
    sprintf(command, "PASS %s\r\n", password);
    send(sockfd, command, strlen(command), 0);
    memset(buffer, 0, BUFFER_SIZE);
    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    buffer[n] = '\0';
    printf("Server response: %s\n", buffer);

    // Retrieve messages from server
    printf("Retrieving messages...\n");
    memset(buffer, 0, BUFFER_SIZE);
    while (1) {
        n = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (n <= 0) {
            printf("No more messages\n");
            break;
        }
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    // Close connection
    close(sockfd);
    return 0;
}