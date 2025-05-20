//FormAI DATASET v1.0 Category: Simple Web Server ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8080
#define MAX_REQUEST_SIZE 4096

void handle_request(int client_sock)
{
    char request_buf[MAX_REQUEST_SIZE];
    char response_buf[MAX_REQUEST_SIZE];
    int request_size = recv(client_sock, request_buf, MAX_REQUEST_SIZE, 0);

    if (request_size <= 0) {
        close(client_sock);
        return;
    }

    char method[16];
    char path[128];
    char http_version[16];
    sscanf(request_buf, "%s %s %s", method, path, http_version);

    if (strcmp(method, "GET") == 0) {
        FILE* file = fopen(path + 1, "rb");
        if (file != NULL) {
            sprintf(response_buf, "HTTP/1.0 200 OK\r\n"
                                   "Server: RecursiveSimpleWebServer\r\n"
                                   "Content-Type: text/html\r\n"
                                   "\r\n");
            send(client_sock, response_buf, strlen(response_buf), 0);

            while (!feof(file)) {
                size_t bytes_read = fread(response_buf, 1, MAX_REQUEST_SIZE, file);
                send(client_sock, response_buf, bytes_read, 0);
            }

            fclose(file);
        } else {
            sprintf(response_buf, "HTTP/1.0 404 Not Found\r\n"
                                   "Server: RecursiveSimpleWebServer\r\n"
                                   "Content-Type: text/html\r\n"
                                   "\r\n"
                                   "<h1>404 Not Found</h1>");
            send(client_sock, response_buf, strlen(response_buf), 0);
        }
    }

    close(client_sock);
}

void accept_connections(int server_sock)
{
    struct sockaddr_in client_addr;
    int client_sock;
    socklen_t client_size = sizeof client_addr;

    while ((client_sock = accept(server_sock, (struct sockaddr*) &client_addr, &client_size)) > 0) {
        switch (fork()) {
            case -1: // fork error
                perror("fork");
                break;

            case 0: // child process
                close(server_sock);
                handle_request(client_sock);
                exit(0);

            default: // parent process
                close(client_sock);
                break;
        }
    }
}

int main()
{
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);

    if (server_sock < 0) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(server_sock, (struct sockaddr*) &server_addr, sizeof server_addr) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(server_sock, SOMAXCONN) < 0) {
        perror("listen");
        exit(1);
    }

    accept_connections(server_sock);

    return 0;
}