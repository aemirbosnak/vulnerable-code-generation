//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char username[50];
    char password[50];
    char hostname[100];
    int port;
    char buffer[BUFFER_SIZE];
    int nbytes;
    int i;

    // Get user input for hostname, port, username, and password
    printf("Enter hostname: ");
    scanf("%s", hostname);
    printf("Enter port: ");
    scanf("%d", &port);
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Set up server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    // Send username and password
    sprintf(buffer, "USER %s\r\n", username);
    send(sockfd, buffer, strlen(buffer), 0);
    nbytes = recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("Received: %s\n", buffer);

    sprintf(buffer, "PASS %s\r\n", password);
    send(sockfd, buffer, strlen(buffer), 0);
    nbytes = recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("Received: %s\n", buffer);

    // Send LIST command
    sprintf(buffer, "LIST\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    nbytes = recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("Received: %s\n", buffer);

    // Close socket
    close(sockfd);

    return 0;
}