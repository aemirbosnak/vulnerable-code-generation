//GPT-4o-mini DATASET v1.0 Category: Simple Web Server ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BACKLOG 10
#define BUFFER_SIZE 1024

void render_response(int client_socket, const char *response) {
    send(client_socket, response, strlen(response), 0);
}

void process_request(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        perror("Failed to receive the message from ye traveler");
        return;
    }

    buffer[bytes_received] = '\0';

    if (strstr(buffer, "GET / HTTP/1.1") != NULL) {
        const char *http_response = 
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/html\r\n"
            "Connection: close\r\n"
            "\r\n"
            "<html><body><h1>Welcome to the Medieval Web Server!</h1>"
            "<p>Lo! Thou hast reached the realm of simple HTTP requests.</p>"
            "</body></html>";
        render_response(client_socket, http_response);
    } else {
        const char *http_response = 
            "HTTP/1.1 404 Not Found\r\n"
            "Content-Type: text/html\r\n"
            "Connection: close\r\n"
            "\r\n"
            "<html><body><h1>404 Not Found</h1>"
            "<p>Alas! The page thou seekest doth not exist.</p>"
            "</body></html>";
        render_response(client_socket, http_response);
    }
}

int main(void) {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Failed to forge the socket, good sirs");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding of the socket hath failed");
        close(server_socket);
        return 1;
    }

    if (listen(server_socket, BACKLOG) < 0) {
        perror("Alas! The server could not listen to the pleas of travelers");
        close(server_socket);
        return 1;
    }

    printf("Hearken! The Medieval Web Server is alive upon port %d!\n\n", PORT);

    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_len);
        if (client_socket < 0) {
            perror("An unfortunate error hath beset the connection, good sirs");
            continue;
        }

        printf("A traveler hath entered the domain.\n");
        process_request(client_socket);
        close(client_socket);
        printf("The traveler hath been sent forth once more.\n\n");
    }

    close(server_socket);
    return 0;
}