//Code Llama-13B DATASET v1.0 Category: Building a IMAP Client ; Style: happy
// A simple IMAP client program in C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

// Define constants
#define PORT 143
#define BUFSIZE 1024
#define MAX_COMMAND_LEN 256
#define MAX_RESPONSE_LEN 1024

// Define data structures
struct imap_client {
    char *host;
    int port;
    int socket_fd;
    char *username;
    char *password;
};

struct imap_response {
    char *response;
    size_t len;
};

// Define functions
void imap_client_init(struct imap_client *client, const char *host, const char *username, const char *password);
void imap_client_connect(struct imap_client *client);
void imap_client_send_command(struct imap_client *client, const char *command);
void imap_client_receive_response(struct imap_client *client, struct imap_response *response);
void imap_client_close(struct imap_client *client);

// Implementation of functions
void imap_client_init(struct imap_client *client, const char *host, const char *username, const char *password) {
    client->host = strdup(host);
    client->port = PORT;
    client->username = strdup(username);
    client->password = strdup(password);
    client->socket_fd = -1;
}

void imap_client_connect(struct imap_client *client) {
    struct sockaddr_in server_addr;
    struct hostent *server;

    // Get host information
    server = gethostbyname(client->host);
    if (server == NULL) {
        printf("ERROR: Unable to get host information\n");
        exit(1);
    }

    // Create socket
    client->socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client->socket_fd < 0) {
        printf("ERROR: Unable to create socket\n");
        exit(1);
    }

    // Set up server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(client->port);
    server_addr.sin_addr = *((struct in_addr *) server->h_addr);
    bzero(&(server_addr.sin_zero), 8);

    // Connect to server
    if (connect(client->socket_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        printf("ERROR: Unable to connect to server\n");
        exit(1);
    }

    // Send username and password
    char *command = malloc(MAX_COMMAND_LEN);
    sprintf(command, "LOGIN %s %s\r\n", client->username, client->password);
    imap_client_send_command(client, command);
    free(command);
}

void imap_client_send_command(struct imap_client *client, const char *command) {
    if (send(client->socket_fd, command, strlen(command), 0) < 0) {
        printf("ERROR: Unable to send command\n");
        exit(1);
    }
}

void imap_client_receive_response(struct imap_client *client, struct imap_response *response) {
    char buffer[BUFSIZE];
    memset(buffer, 0, BUFSIZE);

    if (recv(client->socket_fd, buffer, BUFSIZE, 0) < 0) {
        printf("ERROR: Unable to receive response\n");
        exit(1);
    }

    response->response = strdup(buffer);
    response->len = strlen(buffer);
}

void imap_client_close(struct imap_client *client) {
    close(client->socket_fd);
}

int main(int argc, char **argv) {
    // Check arguments
    if (argc != 4) {
        printf("Usage: %s <host> <username> <password>\n", argv[0]);
        exit(1);
    }

    // Initialize client
    struct imap_client client;
    imap_client_init(&client, argv[1], argv[2], argv[3]);

    // Connect to server
    imap_client_connect(&client);

    // Send command
    imap_client_send_command(&client, "SELECT INBOX");

    // Receive response
    struct imap_response response;
    imap_client_receive_response(&client, &response);

    // Print response
    printf("Response: %s\n", response.response);

    // Close connection
    imap_client_close(&client);

    return 0;
}