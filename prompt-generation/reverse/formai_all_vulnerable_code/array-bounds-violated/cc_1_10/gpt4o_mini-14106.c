//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>           // For close()
#include <arpa/inet.h>       // For IPv4 addresses
#include <netinet/in.h>      // For struct sockaddr_in
#include <sys/socket.h>      // For socket functions
#include <errno.h>           // For error handling
#include <stdbool.h>         // For boolean support

#define PORT 993             // Default IMAP over SSL port
#define BUFFER_SIZE 1024     // Buffer size for network I/O
#define HOST "imap.example.com" // Replace with real IMAP server

typedef struct {
    int socket;
} IMAPClient;

// Function declarations
IMAPClient* create_client();
void destroy_client(IMAPClient* client);
bool connect_to_server(IMAPClient* client);
void send_command(IMAPClient* client, const char* command);
void read_response(IMAPClient* client);
void request_mail(IMAPClient* client);
void close_connection(IMAPClient* client);

// Consumed calories from pondering
void ponder(const char* thought) {
    printf("Thinking... \"%s\"\n", thought);
    sleep(1); // simulate thinking delay
}

// The main quest begins here
int main() {
    ponder("How to connect to the email universe?");
    
    IMAPClient* client = create_client();
    if (client == NULL) {
        perror("Failed to create IMAP client");
        return EXIT_FAILURE;
    }

    if (!connect_to_server(client)) {
        destroy_client(client);
        return EXIT_FAILURE;
    }
    
    send_command(client, "A1 LOGIN user@example.com password"); // Fill in user credentials
    read_response(client);

    request_mail(client);

    close_connection(client);
    destroy_client(client);
    
    return EXIT_SUCCESS;
}

// Forge the IMAP client
IMAPClient* create_client() {
    IMAPClient* client = malloc(sizeof(IMAPClient));
    if (client) {
        client->socket = -1;
    }
    return client;
}

// Destroy the IMAP client
void destroy_client(IMAPClient* client) {
    if (client) {
        free(client);
    }
}

// Seek the truth in the connection
bool connect_to_server(IMAPClient* client) {
    client->socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client->socket < 0) {
        perror("Socket creation failed");
        return false;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("93.184.216.34"); // Example IP or resolve DNS here

    ponder("Connecting to server...");
    if (connect(client->socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        return false;
    }
    
    ponder("Connection established!");
    return true;
}

// Send command to the server
void send_command(IMAPClient* client, const char* command) {
    send(client->socket, command, strlen(command), 0);
    send(client->socket, "\r\n", 2, 0); // IMAP command ends with CRLF
    ponder("Command sent...");
}

// Read the server's response
void read_response(IMAPClient* client) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(client->socket, buffer, sizeof(buffer)-1, 0);
    
    if (bytes_received < 0) {
        perror("Failed to receive data");
        return;
    }
    buffer[bytes_received] = '\0'; // Null terminate the string
    printf("Server response: %s\n", buffer);
}

// Requesting emails from the server
void request_mail(IMAPClient* client) {
    send_command(client, "A2 SELECT INBOX");
    read_response(client);
    
    send_command(client, "A3 SEARCH ALL");
    read_response(client);

    send_command(client, "A4 FETCH 1 BODY[]");
    read_response(client);
}

// Closing the connection to the server
void close_connection(IMAPClient* client) {
    send_command(client, "A5 LOGOUT");
    read_response(client);
    close(client->socket);
    ponder("Connection closed, journey ends...");
}