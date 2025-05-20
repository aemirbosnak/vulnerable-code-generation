//Code Llama-13B DATASET v1.0 Category: Building a POP3 Client ; Style: Romeo and Juliet
// Romeo and Juliet POP3 Client

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <ctype.h>

#define POP3_PORT 110
#define MAX_BUFFER_SIZE 1024
#define MAX_EMAIL_SIZE 1024

int main(int argc, char **argv) {
    // Check arguments
    if (argc != 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    // Parse arguments
    char *hostname = argv[1];
    int port = atoi(argv[2]);

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Create address structure
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    // Resolve hostname
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "Failed to resolve hostname: %s\n", hostname);
        return 1;
    }

    // Copy host address to server address structure
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return 1;
    }

    // Send greeting to server
    char buffer[MAX_BUFFER_SIZE];
    snprintf(buffer, MAX_BUFFER_SIZE, "HELO %s\r\n", hostname);
    send(sock, buffer, strlen(buffer), 0);

    // Wait for response
    char response[MAX_BUFFER_SIZE];
    recv(sock, response, MAX_BUFFER_SIZE, 0);

    // Check response
    if (strncmp(response, "+OK", 3) != 0) {
        fprintf(stderr, "Invalid response from server: %s\n", response);
        return 1;
    }

    // Send username
    snprintf(buffer, MAX_BUFFER_SIZE, "USER %s\r\n", hostname);
    send(sock, buffer, strlen(buffer), 0);

    // Wait for response
    recv(sock, response, MAX_BUFFER_SIZE, 0);

    // Check response
    if (strncmp(response, "+OK", 3) != 0) {
        fprintf(stderr, "Invalid response from server: %s\n", response);
        return 1;
    }

    // Send password
    snprintf(buffer, MAX_BUFFER_SIZE, "PASS %s\r\n", hostname);
    send(sock, buffer, strlen(buffer), 0);

    // Wait for response
    recv(sock, response, MAX_BUFFER_SIZE, 0);

    // Check response
    if (strncmp(response, "+OK", 3) != 0) {
        fprintf(stderr, "Invalid response from server: %s\n", response);
        return 1;
    }

    // Send LIST command
    snprintf(buffer, MAX_BUFFER_SIZE, "LIST\r\n");
    send(sock, buffer, strlen(buffer), 0);

    // Wait for response
    recv(sock, response, MAX_BUFFER_SIZE, 0);

    // Check response
    if (strncmp(response, "+OK", 3) != 0) {
        fprintf(stderr, "Invalid response from server: %s\n", response);
        return 1;
    }

    // Parse response
    int num_emails = atoi(response + 4);
    printf("Number of emails: %d\n", num_emails);

    // Send RETR command for each email
    for (int i = 0; i < num_emails; i++) {
        snprintf(buffer, MAX_BUFFER_SIZE, "RETR %d\r\n", i + 1);
        send(sock, buffer, strlen(buffer), 0);

        // Wait for response
        recv(sock, response, MAX_BUFFER_SIZE, 0);

        // Check response
        if (strncmp(response, "+OK", 3) != 0) {
            fprintf(stderr, "Invalid response from server: %s\n", response);
            return 1;
        }

        // Parse response
        char *email = response + 4;
        int email_len = strlen(email);
        printf("Email %d: %.*s\n", i + 1, email_len, email);
    }

    // Send QUIT command
    snprintf(buffer, MAX_BUFFER_SIZE, "QUIT\r\n");
    send(sock, buffer, strlen(buffer), 0);

    // Wait for response
    recv(sock, response, MAX_BUFFER_SIZE, 0);

    // Check response
    if (strncmp(response, "+OK", 3) != 0) {
        fprintf(stderr, "Invalid response from server: %s\n", response);
        return 1;
    }

    // Close socket
    close(sock);

    return 0;
}