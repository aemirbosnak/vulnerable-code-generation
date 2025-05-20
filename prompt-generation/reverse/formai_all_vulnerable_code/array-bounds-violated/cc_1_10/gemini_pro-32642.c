//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 80
#define MAX_CONTENT_LENGTH 10000

typedef struct ClientConnection {
    int socket;
    char *request;
} ClientConnection;

bool parse_request(ClientConnection *client) {
    char buffer[1024];
    int bytes_received = recv(client->socket, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received <= 0) {
        return false;
    }

    buffer[bytes_received] = '\0';
    client->request = strdup(buffer);
    return true;
}

bool handle_request(ClientConnection *client) {
    char *method = strtok(client->request, " ");
    char *path = strtok(NULL, " ");
    char *http_version = strtok(NULL, "\r\n");

    if (strcmp(method, "GET") != 0) {
        return false;
    }

    char response[1024];
    if (strcmp(path, "/") == 0) {
        sprintf(response, "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><head><title>My Web Server</title></head><body><h1>Hello World!</h1></body></html>");
    } else {
        sprintf(response, "HTTP/1.1 404 Not Found\nContent-Type: text/plain\n\nNot found");
    }

    int bytes_sent = send(client->socket, response, strlen(response), 0);
    if (bytes_sent <= 0) {
        return false;
    }

    return true;
}

void close_client_connection(ClientConnection *client) {
    close(client->socket);
    free(client->request);
    free(client);
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Could not create server socket");
        return EXIT_FAILURE;
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Could not bind server socket");
        close(server_socket);
        return EXIT_FAILURE;
    }

    if (listen(server_socket, 10) < 0) {
        perror("Could not listen on server socket");
        close(server_socket);
        return EXIT_FAILURE;
    }

    while (true) {
        struct sockaddr_in client_address;
        socklen_t client_address_length = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_length);
        if (client_socket < 0) {
            perror("Could not accept client connection");
            continue;
        }

        ClientConnection *client = malloc(sizeof(ClientConnection));
        client->socket = client_socket;
        client->request = NULL;

        if (!parse_request(client)) {
            close_client_connection(client);
            continue;
        }

        if (!handle_request(client)) {
            close_client_connection(client);
            continue;
        }

        close_client_connection(client);
    }

    close(server_socket);
    return EXIT_SUCCESS;
}