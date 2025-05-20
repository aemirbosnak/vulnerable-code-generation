//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXSIZE 1024

// Statistical information variables
static int num_messages = 0;
static int total_bytes = 0;
static int num_deleted = 0;

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char message[MAXSIZE], response[MAXSIZE];
    int bytes_received;

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Failed to create socket.");
        exit(EXIT_FAILURE);
    }

    // Set up server address
    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_family = AF_INET;
    server.sin_port = htons( 110 );

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Failed to connect to server.");
        exit(EXIT_FAILURE);
    }

    // Receive server response
    bytes_received = recv(sock, response, MAXSIZE, 0);
    response[bytes_received] = '\0';
    printf("%s\n", response);

    // Send user credentials
    printf("Enter username: ");
    scanf("%s", message);
    strcat(message, "\r\n");
    send(sock, message, strlen(message), 0);
    memset(message, 0, sizeof(message));

    printf("Enter password: ");
    scanf("%s", message);
    strcat(message, "\r\n");
    send(sock, message, strlen(message), 0);
    memset(message, 0, sizeof(message));

    // Receive server response
    bytes_received = recv(sock, response, MAXSIZE, 0);
    response[bytes_received] = '\0';
    printf("%s\n", response);

    // Send command to list messages
    sprintf(message, "LIST\r\n");
    send(sock, message, strlen(message), 0);
    memset(message, 0, sizeof(message));

    // Receive server response
    bytes_received = recv(sock, response, MAXSIZE, 0);
    response[bytes_received] = '\0';
    
    // Parse message list
    char *token = strtok(response, "\r\n");
    while (token != NULL) {
        if (token[0] >= '0' && token[0] <= '9') {
            num_messages++;
            total_bytes += atoi(strtok(token, " "));
        }
        token = strtok(NULL, "\r\n");
    }

    printf("You have %d messages (%d bytes).\n", num_messages, total_bytes);

    // Prompt user for which message to retrieve
    printf("Enter message number to retrieve: ");
    scanf("%s", message);
    strcat(message, "\r\n");
    send(sock, message, strlen(message), 0);
    memset(message, 0, sizeof(message));

    // Receive server response
    bytes_received = recv(sock, response, MAXSIZE, 0);
    response[bytes_received] = '\0';

    // Check for error in response
    if (response[0] == '-') {
        printf("%s\n", response);
        close(sock);
        exit(EXIT_FAILURE);
    }

    // Parse message content
    char *data = strstr(response, "\r\n\r\n") + 4;
    printf("%s\n", data);

    // Delete message
    sprintf(message, "DELE %s\r\n", message);
    send(sock, message, strlen(message), 0);
    memset(message, 0, sizeof(message));

    // Receive server response
    bytes_received = recv(sock, response, MAXSIZE, 0);
    response[bytes_received] = '\0';

    // Check for error in response
    if (response[0] == '-') {
        printf("%s\n", response);
        close(sock);
        exit(EXIT_FAILURE);
    }

    num_deleted++;

    // Send command to quit
    sprintf(message, "QUIT\r\n");
    send(sock, message, strlen(message), 0);
    memset(message, 0, sizeof(message));

    // Receive server response
    bytes_received = recv(sock, response, MAXSIZE, 0);
    response[bytes_received] = '\0';
    printf("%s\n", response);

    // Statistical Summary
    printf("Server statistics:\n");
    printf("Number of messages: %d\n", num_messages);
    printf("Total bytes: %d\n", total_bytes);
    printf("Number of deleted messages: %d\n", num_deleted);

    // Close socket
    close(sock);
    return 0;
}