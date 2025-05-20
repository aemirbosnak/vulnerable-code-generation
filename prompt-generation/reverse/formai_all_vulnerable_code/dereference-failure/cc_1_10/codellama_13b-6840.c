//Code Llama-13B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUF_SIZE 1024

struct client_info {
    int client_fd;
    struct sockaddr_in client_addr;
};

void error_handling(const char *message) {
    fprintf(stderr, "%s: %s\n", message, strerror(errno));
    exit(1);
}

void handle_client(int client_fd, struct sockaddr_in *client_addr) {
    char buf[BUF_SIZE];
    int read_bytes;
    int send_bytes;

    read_bytes = recv(client_fd, buf, BUF_SIZE, 0);
    if (read_bytes == -1) {
        error_handling("recv() error");
    }
    if (read_bytes == 0) {
        printf("Client disconnected\n");
        return;
    }

    printf("Received %d bytes from client %s:%d\n", read_bytes, inet_ntoa(client_addr->sin_addr), ntohs(client_addr->sin_port));

    send_bytes = send(client_fd, buf, read_bytes, 0);
    if (send_bytes == -1) {
        error_handling("send() error");
    }
}

void handle_clients(int server_fd, struct sockaddr_in *server_addr) {
    int client_fd;
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);

    while (1) {
        client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len);
        if (client_fd == -1) {
            error_handling("accept() error");
        }
        printf("Client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        handle_client(client_fd, &client_addr);

        close(client_fd);
    }
}

int main(int argc, char *argv[]) {
    int server_fd;
    struct sockaddr_in server_addr;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        error_handling("socket() error");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        error_handling("bind() error");
    }

    if (listen(server_fd, MAX_CLIENTS) == -1) {
        error_handling("listen() error");
    }

    handle_clients(server_fd, &server_addr);

    return 0;
}