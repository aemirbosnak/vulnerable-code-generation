//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>

#define BUFFER_SIZE 4096
#define PORT 8080

// Endless Looping - Welcome to Proxy Land
void *handle_client(void *client_socket);
void parse_request(const char *request, char *host, char *port, char *path);
void forward_request(int client_sock, const char *host, const char *port, const char *path);
void handle_error(const char *msg);

int main(void) {
    int opt = 1;
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    
    // Hey there! Let’s dance with sockets!
    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) handle_error("Socket creation failed");
    
    // Enable reuse of socket
    setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // Preparing the server’s dance floor
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the mystical ground
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        close(server_sock);
        handle_error("Binding failed");
    }

    // Listen to the sound of requests
    listen(server_sock, 5);
    printf("Proxy server listening on port %d...\n", PORT);

    // The Village of Clients Awaits!
    while (1) {
        // Here they come, the clients! Queue up!
        if ((client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_len)) < 0) {
            handle_error("Accepting connection failed");
        }
        
        // A thread to take care of each visitor
        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, handle_client, (void *)&client_sock) != 0) {
            fprintf(stderr, "Failed to create thread\n");
            close(client_sock);
        }
        pthread_detach(thread_id); // Let it go, the thread dances alone
    }

    close(server_sock);
    return 0;
}

// What’s in the request? Let’s unveil the mystery!
void *handle_client(void *client_socket) {
    int sock = *(int *)client_socket;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    // Reading the request from the client
    if ((bytes_read = recv(sock, buffer, sizeof(buffer) - 1, 0)) <= 0) {
        close(sock);
        return NULL; // No request? No dance!
    }
    buffer[bytes_read] = '\0'; // The final touch!

    char host[BUFFER_SIZE], port[6] = "80", path[BUFFER_SIZE];
    parse_request(buffer, host, port, path); // Let’s deconstruct the request

    printf("Forwarding request to: %s:%s%s\n", host, port, path);
    forward_request(sock, host, port, path); // Forwarding the request

    close(sock); // Client leaves, thank you!
    return NULL;
}

// Deconstructing the request - a puzzling endeavor
void parse_request(const char *request, char *host, char *port, char *path) {
    sscanf(request, "GET http://%[^:/]:%[^ ]%s", host, port, path);
    if (strlen(path) == 0) {
        strcpy(path, "/"); // Default path
    }
}

// Forwarding the request to the desired destination
void forward_request(int client_sock, const char *host, const char *port, const char *path) {
    int server_sock;
    struct sockaddr_in server_addr;
    
    // The connection to the realm beyond
    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        handle_error("Socket creation failed");
    }

    // Setting up the address of the distant land
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(port));
    struct hostent *server = gethostbyname(host);
    memcpy(&server_addr.sin_addr, server->h_addr, server->h_length);

    // Inviting the server to dance
    if (connect(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("Connection to server failed");
    }

    // Forwarding the request dearly
    char request[BUFFER_SIZE];
    snprintf(request, sizeof(request), "GET %s HTTP/1.0\r\nHost: %s\r\n\r\n", path, host);
    send(server_sock, request, strlen(request), 0);

    // Setting up the return voyage
    char response[BUFFER_SIZE];
    int bytes_received;
    while ((bytes_received = recv(server_sock, response, sizeof(response) - 1, 0)) > 0) {
        response[bytes_received] = '\0';
        send(client_sock, response, bytes_received, 0); // Back to the client!
    }

    close(server_sock);
}

// Oopsie daisy - handle errors the magical way!
void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE); // The end of the line!
}