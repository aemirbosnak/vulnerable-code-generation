//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 110
#define BUFFER_SIZE 1024

void handleError(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void receiveEmails(int sockfd) {
    char buffer[BUFFER_SIZE];
    int numBytes;

    // Send the USER command
    const char *user = "USER your_username\r\n"; // Replace with your actual username
    send(sockfd, user, strlen(user), 0);
    numBytes = recv(sockfd, buffer, sizeof(buffer)-1, 0);
    buffer[numBytes] = '\0'; // Null-terminate the buffer
    printf("%s", buffer);

    // Send the PASS command
    const char *pass = "PASS your_password\r\n"; // Replace with your actual password
    send(sockfd, pass, strlen(pass), 0);
    numBytes = recv(sockfd, buffer, sizeof(buffer)-1, 0);
    buffer[numBytes] = '\0'; // Null-terminate the buffer
    printf("%s", buffer);

    // Send the LIST command
    const char *list = "LIST\r\n";
    send(sockfd, list, strlen(list), 0);
    numBytes = recv(sockfd, buffer, sizeof(buffer)-1, 0);
    buffer[numBytes] = '\0'; // Null-terminate the buffer
    printf("%s", buffer);

    // Handle response for individual emails
    char *line = strtok(buffer, "\r\n");
    while (line != NULL) {
        if (strstr(line, "OK") != NULL) {
            printf("Email received: %s\n", line);
        }
        line = strtok(NULL, "\r\n");
    }

    // Send the QUIT command
    const char *quit = "QUIT\r\n";
    send(sockfd, quit, strlen(quit), 0);
    numBytes = recv(sockfd, buffer, sizeof(buffer)-1, 0);
    buffer[numBytes] = '\0'; // Null-terminate the buffer
    printf("%s", buffer);
}

int main() {
    int sockfd;
    struct sockaddr_in serv_addr;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        handleError("Could not create socket");
    }

    // Configure server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Replace with the server's IP address

    // Connect to the POP3 server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        handleError("Connection failed");
    }

    // Receive welcome message from the POP3 server
    char buffer[BUFFER_SIZE];
    int numBytes = recv(sockfd, buffer, sizeof(buffer)-1, 0);
    buffer[numBytes] = '\0'; // Null-terminate the buffer
    printf("Server: %s", buffer);

    // Function to retrieve emails
    receiveEmails(sockfd);

    // Close the socket
    close(sockfd);
    return 0;
}