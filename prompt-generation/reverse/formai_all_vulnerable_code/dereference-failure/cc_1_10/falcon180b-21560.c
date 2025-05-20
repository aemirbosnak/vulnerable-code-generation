//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define PORT 8080
#define MAX_REQUEST_SIZE 1024
#define RESPONSE_HEADER "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nConnection: close\r\nContent-Length: %d\r\n\r\n"

// Function to send HTTP response header and content
void send_response(int client_socket, char* content, int content_length) {
    char response[1024];
    sprintf(response, RESPONSE_HEADER, content_length);
    send(client_socket, response, strlen(response), 0);
    send(client_socket, content, content_length, 0);
    close(client_socket);
}

// Function to handle client requests
void handle_request(int client_socket) {
    char request[MAX_REQUEST_SIZE];
    memset(request, 0, MAX_REQUEST_SIZE);
    recv(client_socket, request, MAX_REQUEST_SIZE, 0);

    char* method = strtok(request, " ");
    char* path = strtok(NULL, " ");

    if (strcmp(method, "GET") == 0) {
        if (strcmp(path, "/") == 0) {
            char* html_content = "<html><body><h1>Welcome to my Simple Web Server!</h1></body></html>";
            send_response(client_socket, html_content, strlen(html_content));
        } else {
            char* not_found_html = "<html><body><h1>404 Not Found</h1></body></html>";
            send_response(client_socket, not_found_html, strlen(not_found_html));
        }
    } else {
        char* bad_request_html = "<html><body><h1>400 Bad Request</h1></body></html>";
        send_response(client_socket, bad_request_html, strlen(bad_request_html));
    }
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        return 1;
    }

    if (listen(server_socket, 5) == -1) {
        printf("Error listening on socket\n");
        return 1;
    }

    printf("Server started on port %d\n", PORT);

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        handle_request(client_socket);
    }

    close(server_socket);
    return 0;
}