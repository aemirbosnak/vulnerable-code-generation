//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#define POP3_PORT 110
#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server> <username>\n", argv[0]);
        return 1;
    }

    char *server = argv[1];
    char *username = argv[2];

    // Resolve the server's address
    struct hostent *host = gethostbyname(server);
    if (host == NULL) {
        fprintf(stderr, "Error resolving server address: %s\n", server);
        return 1;
    }

    // Create a socket to connect to the server
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Error creating socket");
        return 1;
    }

    // Connect to the server
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(POP3_PORT);
    addr.sin_addr = *(struct in_addr *)host->h_addr;
    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("Error connecting to server");
        close(sock);
        return 1;
    }

    // Read the server's welcome message
    char buffer[MAX_BUFFER_SIZE];
    if (recv(sock, buffer, MAX_BUFFER_SIZE - 1, 0) == -1) {
        perror("Error receiving welcome message");
        close(sock);
        return 1;
    }
    buffer[MAX_BUFFER_SIZE - 1] = '\0';
    printf("%s", buffer);

    // Authenticate with the server
    char command[MAX_BUFFER_SIZE];
    snprintf(command, MAX_BUFFER_SIZE, "USER %s\r\n", username);
    if (send(sock, command, strlen(command), 0) == -1) {
        perror("Error sending USER command");
        close(sock);
        return 1;
    }
    if (recv(sock, buffer, MAX_BUFFER_SIZE - 1, 0) == -1) {
        perror("Error receiving USER response");
        close(sock);
        return 1;
    }
    buffer[MAX_BUFFER_SIZE - 1] = '\0';
    printf("%s", buffer);

    // Get the number of messages on the server
    snprintf(command, MAX_BUFFER_SIZE, "STAT\r\n");
    if (send(sock, command, strlen(command), 0) == -1) {
        perror("Error sending STAT command");
        close(sock);
        return 1;
    }
    if (recv(sock, buffer, MAX_BUFFER_SIZE - 1, 0) == -1) {
        perror("Error receiving STAT response");
        close(sock);
        return 1;
    }
    buffer[MAX_BUFFER_SIZE - 1] = '\0';
    printf("%s", buffer);

    // Retrieve the first message
    snprintf(command, MAX_BUFFER_SIZE, "RETR 1\r\n");
    if (send(sock, command, strlen(command), 0) == -1) {
        perror("Error sending RETR command");
        close(sock);
        return 1;
    }

    // Read the message header
    memset(buffer, 0, MAX_BUFFER_SIZE);
    while (recv(sock, buffer, MAX_BUFFER_SIZE - 1, 0) > 0) {
        if (strstr(buffer, "\r\n\r\n") != NULL) {
            break;
        }
        printf("%s", buffer);
        memset(buffer, 0, MAX_BUFFER_SIZE);
    }

    // Read the message body
    memset(buffer, 0, MAX_BUFFER_SIZE);
    while (recv(sock, buffer, MAX_BUFFER_SIZE - 1, 0) > 0) {
        if (strstr(buffer, "\r\n.\r\n") != NULL) {
            break;
        }
        printf("%s", buffer);
        memset(buffer, 0, MAX_BUFFER_SIZE);
    }

    // Close the connection
    close(sock);

    return 0;
}