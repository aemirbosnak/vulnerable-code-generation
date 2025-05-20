//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAX_EMAIL_SIZE 1024
#define MAX_COMMAND_SIZE 256
#define SERVER_PORT 993

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

// Function to send a command to the IMAP server
void send_command(int sockfd, const char *command) {
    char buffer[MAX_COMMAND_SIZE];
    snprintf(buffer, sizeof(buffer), "%s\r\n", command);
    send(sockfd, buffer, strlen(buffer), 0);
}

// Function to read the server response
void read_response(int sockfd) {
    char buffer[MAX_EMAIL_SIZE];
    int n;

    // Read response from server
    while ((n = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
        if (strstr(buffer, "OK") || strstr(buffer, "NO") || strstr(buffer, "BYE")) break;
    }

    if (n < 0) {
        error("Error reading response from server");
    }
}

// Function to open a connection to the IMAP server
int connect_to_imap_server(const char *hostname) {
    int sockfd;
    struct sockaddr_in server_addr;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    // Set up server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Error connecting to server");
    }

    return sockfd;
}

void login_to_imap(int sockfd, const char *username, const char *password) {
    char command[MAX_COMMAND_SIZE];

    // Sending LOGIN command
    snprintf(command, sizeof(command), "A001 LOGIN %s %s", username, password);
    send_command(sockfd, command);
    read_response(sockfd);
}

void fetch_emails(int sockfd) {
    // Send FETCH command to get list of emails
    send_command(sockfd, "A002 SELECT INBOX");
    read_response(sockfd);

    send_command(sockfd, "A003 SEARCH ALL");
    read_response(sockfd);
}

void logout_from_imap(int sockfd) {
    // Send LOGOUT command
    send_command(sockfd, "A004 LOGOUT");
    read_response(sockfd);
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    // Connect to the IMAP server
    int sockfd = connect_to_imap_server(hostname);
    printf("Connected to IMAP server at %s\n", hostname);

    // Login to the server
    login_to_imap(sockfd, username, password);
    printf("Logged in as %s\n", username);

    // Fetch emails
    printf("Fetching emails...\n");
    fetch_emails(sockfd);

    // Log out from the server
    logout_from_imap(sockfd);
    printf("Logged out successfully. Goodbye!\n");

    return EXIT_SUCCESS;
}