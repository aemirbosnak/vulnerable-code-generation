//GPT-4o-mini DATASET v1.0 Category: Simple Web Server ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define BACKLOG 10

void *handle_client(void *client_socket);
void send_response(int client_socket, const char *status, const char *content_type, const char *body);

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    printf("Server socket created successfully.\n");

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }
    printf("Server bound to port %d.\n", PORT);

    if (listen(server_socket, BACKLOG) < 0) {
        perror("Listening failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }
    printf("Server is listening...\n");

    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_socket < 0) {
            perror("Client connection failed");
            continue;
        }
        printf("Client connected.\n");

        pthread_t tid;
        if (pthread_create(&tid, NULL, handle_client, (void *)(intptr_t)client_socket) != 0) {
            perror("Thread creation failed");
            close(client_socket);
            continue;
        }
        pthread_detach(tid);
    }

    close(server_socket);
    return 0;
}

void *handle_client(void *client_socket) {
    int sock = (intptr_t)client_socket;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    bytes_read = recv(sock, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_read < 0) {
        perror("Recv failed");
        close(sock);
        return NULL;
    }
    buffer[bytes_read] = '\0';

    printf("Received request:\n%s\n", buffer);

    const char *response_body = "<html><body><h1>Welcome!</h1><p>This is a simple C web server.</p></body></html>";
    send_response(sock, "HTTP/1.1 200 OK", "text/html", response_body);

    close(sock);
    printf("Client disconnected.\n");
    return NULL;
}

void send_response(int client_socket, const char *status, const char *content_type, const char *body) {
    char response[BUFFER_SIZE];
    int body_length = strlen(body);

    snprintf(response, sizeof(response), "%s\r\n"
                                          "Content-Type: %s\r\n"
                                          "Content-Length: %d\r\n"
                                          "Connection: close\r\n"
                                          "\r\n"
                                          "%s", status, content_type, body_length, body);
    
    send(client_socket, response, strlen(response), 0);
}