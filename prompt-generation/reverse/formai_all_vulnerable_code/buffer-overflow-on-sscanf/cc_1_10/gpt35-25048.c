//FormAI DATASET v1.0 Category: Simple Web Server ; Style: active
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_REQUEST_SIZE 2048
#define SERVER_PORT 8000
#define WEB_ROOT "./"

void handle_connection(int conn_fd)
{
    char request[MAX_REQUEST_SIZE];
    int bytes_read = recv(conn_fd, request, MAX_REQUEST_SIZE, 0);
    if (bytes_read < 1)
    {
        close(conn_fd);
        return;
    }
    request[bytes_read] = 0;
    char filename[MAX_REQUEST_SIZE];
    sscanf(request, "GET %s HTTP/1.", filename);
    if (strlen(filename) < 2)
    {
        close(conn_fd);
        return;
    }
    char full_path[MAX_REQUEST_SIZE];
    snprintf(full_path, MAX_REQUEST_SIZE, "%s%s", WEB_ROOT, filename+1);
    FILE* file = fopen(full_path, "rb");
    if (file == NULL)
    {
        const char* error_msg = "HTTP/1.0 404 Not Found\r\n\r\n";
        send(conn_fd, error_msg, strlen(error_msg), 0);
        close(conn_fd);
        return;
    }
    const char* ok_msg = "HTTP/1.0 200 OK\r\n\r\n";
    send(conn_fd, ok_msg, strlen(ok_msg), 0);
    while (!feof(file))
    {
        char buffer[MAX_REQUEST_SIZE];
        int bytes_read = fread(buffer, 1, MAX_REQUEST_SIZE, file);
        send(conn_fd, buffer, bytes_read, 0);
    }
    fclose(file);
    close(conn_fd);
}

int main()
{
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd <= 0)
    {
        fprintf(stderr, "Failed to create socket\n");
        return 1;
    }

    int yes = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1)
    {
        fprintf(stderr, "Failed to set socket options\n");
        return 1;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(SERVER_PORT);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_fd, (struct sockaddr*)&addr, sizeof(addr)) < 0)
    {
        fprintf(stderr, "Failed to bind socket\n");
        return 1;
    }

    if (listen(server_fd, 10) < 0)
    {
        fprintf(stderr, "Failed to listen on the socket\n");
        return 1;
    }

    printf("Server ready on port %d\n", SERVER_PORT);

    while (1)
    {
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int conn_fd = accept(server_fd, (struct sockaddr*)&client_addr, &client_len);
        if (conn_fd < 0)
        {
            fprintf(stderr, "Failed to accept connection\n");
            continue;
        }
        char client_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, INET_ADDRSTRLEN);
        printf("Accepted connection from %s\n", client_ip);
        handle_connection(conn_fd);
    }
    return 0;
}