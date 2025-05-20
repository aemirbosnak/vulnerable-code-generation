//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char username[50];
    char password[50];
    char buffer[BUFFER_SIZE];
    int n;
    int connected = 0;
    int login_success = 0;
    int read_success = 0;

    // Get username and password from user
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    // Initialize server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(110);
    inet_pton(AF_INET, "localhost", &server_addr.sin_addr);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }
    connected = 1;

    // Send username and password
    sprintf(buffer, "USER %s\r\n", username);
    send(sockfd, buffer, strlen(buffer), 0);
    sprintf(buffer, "PASS %s\r\n", password);
    send(sockfd, buffer, strlen(buffer), 0);

    // Check for login success
    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (n > 0) {
        if (strstr(buffer, "+OK")) {
            login_success = 1;
        } else {
            printf("Login failed\n");
            exit(1);
        }
    }

    // Send LIST command
    sprintf(buffer, "LIST\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Read server response
    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (n > 0) {
        printf("Server response: %s", buffer);
        read_success = 1;
    } else {
        printf("Error reading from server\n");
        exit(1);
    }

    // Close socket
    close(sockfd);

    return 0;
}