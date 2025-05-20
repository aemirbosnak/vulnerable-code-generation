//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define BACKLOG 10

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int create_socket(int domain, int type, int protocol) {
    int sockfd;

    if ((sockfd = socket(domain, type, protocol)) == -1) {
        die("socket failed");
    }

    return sockfd;
}

int bind_socket(int sockfd, const struct sockaddr *addr, socklen_t addrlen) {
    if (bind(sockfd, addr, addrlen) == -1) {
        die("bind failed");
    }

    return TRUE;
}

int listen_socket(int sockfd, int backlog) {
    if (listen(sockfd, backlog) == -1) {
        die("listen failed");
    }

    return TRUE;
}

int accept_socket(int sockfd, struct sockaddr *addr, socklen_t *addrlen) {
    int new_socket;

    if ((new_socket = accept(sockfd, addr, addrlen)) == -1) {
        die("accept failed");
    }

    return new_socket;
}

void handle_client(int client_socket) {
    char buffer[1024];
    ssize_t bytes_received;

    while ((bytes_received = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Client sent: %s\n", buffer);
    }

    if (bytes_received == -1) {
        die("recv failed");
    }

    close(client_socket);
}

int main() {
    int server_socket;
    struct sockaddr_in server_addr;
    int opt = TRUE;
    int addrlen = sizeof(struct sockaddr_in);

    if ((server_socket = create_socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        return EXIT_FAILURE;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt)) == -1) {
        die("setsockopt failed");
    }

    if (bind_socket(server_socket, (struct sockaddr *)&server_addr, sizeof(struct sockaddr_in)) == FALSE) {
        return EXIT_FAILURE;
    }

    if (listen_socket(server_socket, BACKLOG) == FALSE) {
        return EXIT_FAILURE;
    }

    printf("Server is listening on port %d...\n", PORT);

    while (TRUE) {
        int client_socket;

        if ((client_socket = accept_socket(server_socket, (struct sockaddr *)&server_addr, (socklen_t *)&addrlen)) == -1) {
            continue;
        }

        printf("Client connected with IP address: %s and port: %d\n", inet_ntoa(server_addr.sin_addr), ntohs(server_addr.sin_port));
        handle_client(client_socket);
    }

    close(server_socket);
    return EXIT_SUCCESS;
}