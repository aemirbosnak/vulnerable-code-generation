//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#define DEFAULT_PORT 993
#define BUFFER_SIZE 1024

typedef struct {
    int socket_fd;
    struct sockaddr_in server_addr;
    char username[50];
    char password[50];
} IMAP_Client;

// Function prototypes
IMAP_Client* create_client(const char* server);
int connect_to_server(IMAP_Client* client);
int authenticate(IMAP_Client* client);
int fetch_emails(IMAP_Client* client);
void close_connection(IMAP_Client* client);
void clean_exit(IMAP_Client* client);

// Function to create a new IMAP client
IMAP_Client* create_client(const char* server) {
    IMAP_Client* client = (IMAP_Client*)malloc(sizeof(IMAP_Client));
    if (!client) {
        perror("Failed to allocate memory for client");
        exit(EXIT_FAILURE);
    }
    
    client->socket_fd = -1;
    memset(&client->server_addr, 0, sizeof(client->server_addr));
    client->server_addr.sin_family = AF_INET;
    client->server_addr.sin_port = htons(DEFAULT_PORT);

    struct hostent* host = gethostbyname(server);
    if (!host) {
        perror("Failed to resolve server address");
        free(client);
        exit(EXIT_FAILURE);
    }
    memcpy(&client->server_addr.sin_addr, host->h_addr, host->h_length);

    return client;
}

// Function to connect to the IMAP server
int connect_to_server(IMAP_Client* client) {
    client->socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client->socket_fd < 0) {
        perror("Socket creation failed");
        return -1;
    }

    if (connect(client->socket_fd, (struct sockaddr*)&client->server_addr, sizeof(client->server_addr)) < 0) {
        perror("Failed to connect to the server");
        close(client->socket_fd);
        return -1;
    }

    return 0;
}

// Function for user authentication
int authenticate(IMAP_Client* client) {
    printf("Enter username: ");
    scanf("%s", client->username);
    printf("Enter password: ");
    scanf("%s", client->password);

    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "A001 LOGIN %s %s\r\n", client->username, client->password);
    send(client->socket_fd, command, strlen(command), 0);

    // Read server response
    char response[BUFFER_SIZE];
    recv(client->socket_fd, response, sizeof(response) - 1, 0);
    response[BUFFER_SIZE - 1] = '\0';
    printf("Server Response: %s\n", response);

    if (strstr(response, "OK") == NULL) {
        printf("Authentication failed.\n");
        return -1;
    }
    
    return 0;
}

// Function to fetch emails
int fetch_emails(IMAP_Client* client) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "A002 SELECT INBOX\r\n");
    send(client->socket_fd, command, strlen(command), 0);
    
    char response[BUFFER_SIZE];
    recv(client->socket_fd, response, sizeof(response) - 1, 0);
    response[BUFFER_SIZE - 1] = '\0';
    printf("Select Response: %s\n", response);

    if (strstr(response, "OK") == NULL) {
        printf("Failed to select inbox.\n");
        return -1;
    }

    snprintf(command, sizeof(command), "A003 FETCH 1:* (UID)\r\n");
    send(client->socket_fd, command, strlen(command), 0);
    
    recv(client->socket_fd, response, sizeof(response) - 1, 0);
    response[BUFFER_SIZE - 1] = '\0';
    printf("Fetch Response: %s\n", response);

    if (strstr(response, "OK") == NULL) {
        printf("Failed to fetch emails.\n");
        return -1;
    }

    return 0;
}

// Function to close the connection cleanly
void close_connection(IMAP_Client* client) {
    char command[BUFFER_SIZE];
    
    snprintf(command, sizeof(command), "A004 LOGOUT\r\n");
    send(client->socket_fd, command, strlen(command), 0);
    close(client->socket_fd);
    free(client);
}

// Function to clean exit
void clean_exit(IMAP_Client* client) {
    if (client != NULL) {
        if (client->socket_fd >= 0) {
            close(client->socket_fd);
        }
        free(client);
    }
    exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <imap-server>\n", argv[0]);
        return EXIT_FAILURE;
    }

    IMAP_Client* client = create_client(argv[1]);
    
    if (connect_to_server(client) < 0) {
        clean_exit(client);
    }

    if (authenticate(client) < 0) {
        clean_exit(client);
    }

    if (fetch_emails(client) < 0) {
        clean_exit(client);
    }

    close_connection(client);
    return EXIT_SUCCESS;
}