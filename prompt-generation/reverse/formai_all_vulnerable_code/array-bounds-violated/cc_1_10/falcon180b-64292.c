//Falcon-180B DATASET v1.0 Category: Networking ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 8080
#define BACKLOG 10
#define BUFFER_SIZE 1024

void error(char* msg) {
    perror(msg);
    exit(1);
}

int create_socket(int domain, int type, int protocol) {
    int sockfd;

    if ((sockfd = socket(domain, type, protocol)) == -1) {
        error("socket failed");
    }

    return sockfd;
}

int bind_socket(int sockfd, struct sockaddr* addr, socklen_t addrlen) {
    if (bind(sockfd, addr, addrlen) == -1) {
        error("bind failed");
    }

    return 0;
}

int listen_socket(int sockfd) {
    if (listen(sockfd, BACKLOG) == -1) {
        error("listen failed");
    }

    return 0;
}

int accept_socket(int sockfd, struct sockaddr* addr, socklen_t* addrlen) {
    int connfd;

    if ((connfd = accept(sockfd, addr, addrlen)) == -1) {
        error("accept failed");
    }

    return connfd;
}

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Received message: %s\n", buffer);

        if (strstr(buffer, "exit")) {
            break;
        }
    }

    close(client_socket);
}

int main() {
    int server_socket;
    struct sockaddr_in server_addr;
    int opt = 1;

    if ((server_socket = create_socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        return 1;
    }

    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        error("setsockopt");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    if (bind_socket(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        return 1;
    }

    if (listen_socket(server_socket) == -1) {
        return 1;
    }

    printf("Server started on port %d\n", PORT);

    while (1) {
        int client_socket;

        if ((client_socket = accept_socket(server_socket, (struct sockaddr*)&server_addr, NULL)) == -1) {
            error("accept");
        }

        printf("Client connected: %s:%d\n", inet_ntoa(server_addr.sin_addr), ntohs(server_addr.sin_port));

        handle_client(client_socket);
    }

    return 0;
}