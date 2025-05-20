//Code Llama-13B DATASET v1.0 Category: TCP/IP Programming ; Style: decentralized
// TCP/IP Decentralized Programming Example
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// Define constants
#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_CLIENTS 10

// Define structs
typedef struct {
    int client_socket;
    struct sockaddr_in client_address;
    char client_ip[INET_ADDRSTRLEN];
    int client_port;
} client_info_t;

typedef struct {
    int server_socket;
    struct sockaddr_in server_address;
    char server_ip[INET_ADDRSTRLEN];
    int server_port;
} server_info_t;

// Define functions
void error(const char *msg) {
    perror(msg);
    exit(1);
}

int create_socket() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        error("Failed to create socket");
    }
    return sock;
}

int bind_socket(int sock, int port) {
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = INADDR_ANY;
    if (bind(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        error("Failed to bind socket");
    }
    return sock;
}

int listen_socket(int sock) {
    if (listen(sock, MAX_CLIENTS) < 0) {
        error("Failed to listen on socket");
    }
    return sock;
}

int accept_connection(int sock, client_info_t *client_info) {
    struct sockaddr_in client_address;
    socklen_t client_address_len = sizeof(client_address);
    client_info->client_socket = accept(sock, (struct sockaddr *)&client_address, &client_address_len);
    if (client_info->client_socket < 0) {
        error("Failed to accept connection");
    }
    client_info->client_port = ntohs(client_address.sin_port);
    inet_ntop(AF_INET, &client_address.sin_addr, client_info->client_ip, INET_ADDRSTRLEN);
    return client_info->client_socket;
}

void send_message(int client_socket, const char *message) {
    if (send(client_socket, message, strlen(message), 0) < 0) {
        error("Failed to send message");
    }
}

void receive_message(int client_socket, char *buffer) {
    int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (bytes_received < 0) {
        error("Failed to receive message");
    }
    buffer[bytes_received] = '\0';
}

void close_connection(int client_socket) {
    if (close(client_socket) < 0) {
        error("Failed to close connection");
    }
}

void handle_client(int client_socket, client_info_t *client_info) {
    char buffer[BUFFER_SIZE];
    while (1) {
        receive_message(client_socket, buffer);
        if (strcmp(buffer, "exit") == 0) {
            break;
        }
        send_message(client_socket, "Hello, client!");
    }
    close_connection(client_socket);
}

void start_server(server_info_t *server_info) {
    int sock = create_socket();
    sock = bind_socket(sock, PORT);
    sock = listen_socket(sock);
    while (1) {
        client_info_t client_info;
        int client_socket = accept_connection(sock, &client_info);
        handle_client(client_socket, &client_info);
    }
}

int main(void) {
    server_info_t server_info;
    server_info.server_socket = create_socket();
    server_info.server_port = PORT;
    start_server(&server_info);
    return 0;
}