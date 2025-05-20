//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define SERVER_PORT 993
#define MAXLINE 1024
#define IMAP_COMMAND_LEN 128

// IMAP client class
typedef struct {
    char *host;
    int port;
    int sockfd;
} IMAPClient;

// Function to create and initialize IMAPClient
IMAPClient *create_imap_client(const char *host, int port) {
    IMAPClient *client = (IMAPClient *)malloc(sizeof(IMAPClient));
    client->host = strdup(host);
    client->port = port;
    client->sockfd = -1;
    return client;
}

// Function to connect to the IMAP server
int connect_to_server(IMAPClient *client) {
    struct sockaddr_in server_addr;

    if ((client->sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        return -1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(client->port);

    if (inet_pton(AF_INET, client->host, &server_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        return -1;
    }

    if (connect(client->sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection Failed");
        return -1;
    }

    return 0;
}

// Function to send command to IMAP server
void send_command(IMAPClient *client, const char *command) {
    send(client->sockfd, command, strlen(command), 0);
    send(client->sockfd, "\r\n", 2, 0);
}

// Function to read server's response
void read_response(IMAPClient *client) {
    char buffer[MAXLINE];
    int bytes_read;

    while ((bytes_read = recv(client->sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_read] = '\0';
        printf("%s", buffer);
    }
}

// Function to authenticate
void authenticate(IMAPClient *client, const char *username, const char *password) {
    char command[IMAP_COMMAND_LEN];
    snprintf(command, sizeof(command), "A001 LOGIN %s %s", username, password);
    send_command(client, command);
    read_response(client);
}

// Function to fetch email list
void fetch_email_list(IMAPClient *client) {
    send_command(client, "A002 LIST \"\" \"*\"");
    read_response(client);
}

// Function to cleanup
void cleanup(IMAPClient *client) {
    close(client->sockfd);
    free(client->host);
    free(client);
}

// Main function to run the futuristic IMAP client
int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <IMAP server> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *host = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    // Initialize IMAP Client
    IMAPClient *client = create_imap_client(host, SERVER_PORT);
    if (connect_to_server(client) != 0) {
        cleanup(client);
        return EXIT_FAILURE;
    }

    // Authenticate the user
    authenticate(client, username, password);

    // Fetch email list after authentication
    fetch_email_list(client);

    // Cleanup resources
    cleanup(client);
    return EXIT_SUCCESS;
}