//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define POP3_PORT 110
#define USER "testuser"
#define PASSWORD "password"

int main() {
    int sockfd, n;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char username[20] = "testuser";
    char password[20] = "password";
    char response[BUFFER_SIZE];
    char *c;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket.\n");
        exit(1);
    }

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    server_addr.sin_addr.s_addr = inet_addr("localhost");

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server.\n");
        exit(1);
    }

    // Send USER command
    sprintf(buffer, "USER %s\r\n", username);
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive response
    n = recv(sockfd, response, BUFFER_SIZE, 0);
    if (n <= 0) {
        printf("Error receiving response.\n");
        exit(1);
    }
    response[n] = '\0';
    printf("Response: %s\n", response);

    // Send PASS command
    sprintf(buffer, "PASS %s\r\n", password);
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive response
    n = recv(sockfd, response, BUFFER_SIZE, 0);
    if (n <= 0) {
        printf("Error receiving response.\n");
        exit(1);
    }
    response[n] = '\0';
    printf("Response: %s\n", response);

    // Send LIST command
    sprintf(buffer, "LIST\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive response
    n = recv(sockfd, response, BUFFER_SIZE, 0);
    if (n <= 0) {
        printf("Error receiving response.\n");
        exit(1);
    }
    response[n] = '\0';
    printf("Response: %s\n", response);

    // Close socket
    close(sockfd);
    return 0;
}