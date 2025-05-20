//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024
#define PORT 143
#define SERVER "imap.gmail.com"

int main() {
    int sockfd, newsockfd, portno, clilen, i, n;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in serv_addr, cli_addr;
    char username[100], password[100];

    printf("Welcome to the IMAP client!\n");
    printf("Please enter your username: ");
    scanf("%s", username);
    printf("Please enter your password: ");
    scanf("%s", password);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set up the server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(SERVER);
    serv_addr.sin_port = htons(PORT);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Send username and password
    sprintf(buffer, "A001 LOGIN \"%s\" \"%s\"\r\n", username, password);
    send(sockfd, buffer, strlen(buffer), 0);

    // Read server response
    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    buffer[n] = '\0';
    printf("Server response: %s\n", buffer);

    // Check if login was successful
    if (strstr(buffer, "OK") == NULL) {
        printf("Login failed\n");
        exit(1);
    }

    printf("Login successful!\n");

    // Close the socket
    close(sockfd);

    return 0;
}