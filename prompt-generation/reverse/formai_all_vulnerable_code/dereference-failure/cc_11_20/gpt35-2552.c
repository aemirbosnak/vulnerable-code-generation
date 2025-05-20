//FormAI DATASET v1.0 Category: Simple Web Server ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFSIZE 1024
#define BACKLOG 10

int main(int argc, char *argv[]) {
    int server_sock, client_sock, port;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    char buf[BUFSIZE];
    FILE *file;
    char *f_content;
    long f_size;
    int bytes_sent;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    port = atoi(argv[1]);

    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(port);

    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(server_sock, BACKLOG) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (true) {
        client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_sock < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        memset(buf, 0, sizeof(buf));
        if (recv(client_sock, buf, sizeof(buf), 0) < 0) {
            perror("recv");
            close(client_sock);
            continue;
        }
        printf("Received request:\n%s\n", buf);

        const char *file_path;
        strtok(buf, " ");
        file_path = strtok(NULL, " ");
        if (file_path == NULL || strcmp(file_path, "/") == 0) {
            file_path = "index.html";
        } else {
            file_path++;
        }

        printf("Requested file: %s\n", file_path);

        file = fopen(file_path, "r");
        if (file == NULL) {
            send(client_sock, "HTTP/1.0 404 NOT FOUND\r\nContent-Type: text/plain\r\n\r\n404 Not Found", 67, 0);
            printf("File not found!\n");
            close(client_sock);
            continue;
        }

        fseek(file, 0, SEEK_END);
        f_size = ftell(file);
        fseek(file, 0, SEEK_SET);

        f_content = malloc(f_size + 1);
        fread(f_content, 1, f_size, file);
        fclose(file);

        f_content[f_size] = '\0';

        char response_headers[BUFSIZE];
        sprintf(response_headers,
            "HTTP/1.0 200 OK\r\n"
            "Server: SimpleHTTPServer/0.1.0\r\n"
            "Content-Length: %ld\r\n"
            "Content-Type: text/html\r\n"
            "\r\n",
            f_size
        );

        bytes_sent = send(client_sock, response_headers, strlen(response_headers), 0);
        if (bytes_sent < 0) {
            perror("send");
            free(f_content);
            close(client_sock);
            continue;
        }
        printf("Sent response headers:\n%s\n", response_headers);

        bytes_sent = send(client_sock, f_content, f_size, 0);
        if (bytes_sent < 0) {
            perror("send");
        }
        printf("Sent response body:\n%s\n", f_content);

        free(f_content);
        close(client_sock);
    }

    close(server_sock);
    return 0;
}