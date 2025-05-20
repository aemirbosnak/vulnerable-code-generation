//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080    // The port we listen on for the requests
#define BUFFER_SIZE 4096
#define MAX_CLIENTS 10

// Function headers
void serve_client(int client_socket);
void farewell(const char *msg);
void star_crossed_lovers();
void send_response(int client_socket, const char *response);

// The play begins
int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    // Create the socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        farewell("Alas! The socket could not be created.\n");
        return 1;
    }

    // Set up the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        farewell("The binding hath failed, dear friend.\n");
        close(server_socket);
        return 1;
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        farewell("To listen is a sorrowful plight.\n");
        close(server_socket);
        return 1;
    }

    printf("Oh, fair Verona! The Proxy awaiteth thy requests on port %d.\n", PORT);
    
    // The play unfolds
    while (1) {
        client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &addr_len);
        if (client_socket < 0) {
            farewell("Ah! Another heartbreak in the night.\n");
            break;
        }
        
        serve_client(client_socket);
    }

    close(server_socket);
    return 0;
}

// When love meets pain, the youth shall serve
void serve_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
    
    if (bytes <= 0) {
        farewell("The response hath betray'd the heart.\n");
        close(client_socket);
        return;
    }
    
    buffer[bytes] = '\0';
    
    // A simple HTTP request parsing
    if (strstr(buffer, "GET") != NULL) {
        char *url_start = strchr(buffer, ' ') + 1;
        char *url_end = strchr(url_start, ' ');

        if (url_end == NULL) {
            farewell("Oh cruel fate! The URL escapes us.\n");
            close(client_socket);
            return;
        }

        *url_end = '\0'; // Null-terminate the URL for us to use
        printf("Doth seek thy beloved: %s\n", url_start);

        // Send a response back to the client
        const char *response = "HTTP/1.1 200 OK\nContent-Type: text/plain\n\nThou hast reached the proxy, sweet lover.";
        send_response(client_socket, response);
    } else {
        farewell("What dost thine heart desire, if not a noble GET?\n");
    }

    close(client_socket);
}

// The fateful goodbye
void farewell(const char *msg) {
    fprintf(stderr, "%s", msg);
    exit(EXIT_FAILURE);
}

// The connection forged in passion
void send_response(int client_socket, const char *response) {
    send(client_socket, response, strlen(response), 0);
    printf("Thus was the message sent, like love's first kiss.\n");
}