//GPT-4o-mini DATASET v1.0 Category: Simple Web Server ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <signal.h>
#include <time.h>

#define PORT 8080
#define MAX_CONN 10
#define BUFFER_SIZE 2048

void handle_sigint(int sig) {
    printf("\nCyberpunk Web Server shutting down...\n");
    exit(0);
}

void format_time(char *buffer, size_t size) {
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    strftime(buffer, size, "%Y-%m-%d %H:%M:%S", tm_info);
}

void send_response(int client_socket, const char *status, const char *content) {
    char response[BUFFER_SIZE];
    snprintf(response, sizeof(response), 
             "HTTP/1.1 %s\r\n"
             "Content-Type: text/html\r\n"
             "Connection: close\r\n"
             "\r\n"
             "<html><body><h1>%s</h1><p> %s </p></body></html>",
             status, status, content);
    send(client_socket, response, strlen(response), 0);
}

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        perror("recv");
        close(client_socket);
        return;
    }
    
    buffer[bytes_received] = '\0';
    
    printf("Request received:\n%s\n", buffer);
    
    if (strstr(buffer, "GET /time") != NULL) {
        char time_buffer[30];
        format_time(time_buffer, sizeof(time_buffer));
        send_response(client_socket, "200 OK", time_buffer);
    } else if (strstr(buffer, "GET /") != NULL) {
        send_response(client_socket, "200 OK", "Welcome to the Cyberpunk Web Server!");
    } else {
        send_response(client_socket, "404 Not Found", "The page you are looking for is in another dimension.");
    }

    close(client_socket);
}

int main() {
    signal(SIGINT, handle_sigint);

    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, MAX_CONN) < 0) {
        perror("listen");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Cyberpunk Web Server is running on port %d...\n", PORT);

    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_socket < 0) {
            perror("accept");
            close(server_socket);
            exit(EXIT_FAILURE);
        }

        printf("Client connection accepted...\n");
        handle_client(client_socket);
    }

    close(server_socket);
    return 0;
}