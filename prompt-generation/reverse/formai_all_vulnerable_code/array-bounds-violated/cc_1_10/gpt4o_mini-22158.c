//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>

#define MAX_LINE 1024
#define SERVER_PORT 993
#define IMAP_COMMAND_BUFFER 2048

void send_command(int sockfd, const char *command);
void read_response(int sockfd);

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host;
    char *server_name = "imap.example.com"; // replace with your IMAP server
    char command[IMAP_COMMAND_BUFFER];

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Resolve the server address
    if ((host = gethostbyname(server_name)) == NULL) {
        perror("gethostbyname failed");
        exit(EXIT_FAILURE);
    }

    // Set up server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);
    server_addr.sin_port = htons(SERVER_PORT);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Connected to IMAP server %s\n", server_name);
    read_response(sockfd);

    // Send LOGIN command
    snprintf(command, sizeof(command), "A001 LOGIN %s %s\r\n", argv[1], argv[2]);
    send_command(sockfd, command);
    read_response(sockfd);

    // Send LIST command to fetch mailboxes
    snprintf(command, sizeof(command), "A002 LIST \"\" \"*\"\r\n");
    send_command(sockfd, command);
    read_response(sockfd);

    // Send LOGOUT command
    snprintf(command, sizeof(command), "A003 LOGOUT\r\n");
    send_command(sockfd, command);
    read_response(sockfd);

    // Close the socket
    close(sockfd);
    printf("Disconnected from IMAP server\n");
    return 0;
}

void send_command(int sockfd, const char *command) {
    if (send(sockfd, command, strlen(command), 0) < 0) {
        perror("Send command failed");
        exit(EXIT_FAILURE);
    }
}

void read_response(int sockfd) {
    char buffer[MAX_LINE];
    int n;

    while ((n = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[n] = '\0'; // Null-terminate the buffer
        printf("%s", buffer); // Print the response
        if (strstr(buffer, "Bye") != NULL) break; // Break if the server says bye
    }
    if (n < 0) {
        perror("Receive failed");
        exit(EXIT_FAILURE);
    }
}