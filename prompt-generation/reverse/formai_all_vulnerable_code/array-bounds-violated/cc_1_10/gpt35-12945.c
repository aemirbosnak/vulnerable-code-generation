//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: asynchronous
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <netdb.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int listen_sock_fd, conn_sock_fd;

void init_socket() {
    struct sockaddr_in addr;
    int reuse = 1;
    listen_sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock_fd < 0) {
        perror("Error opening socket");
        exit(EXIT_FAILURE);
    }
    if (setsockopt(listen_sock_fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) < 0) {
        perror("Error setting socket options");
        exit(EXIT_FAILURE);
    }
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);
    if (bind(listen_sock_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }
    if (listen(listen_sock_fd, 10) < 0) {
        perror("Error listening socket");
        exit(EXIT_FAILURE);
    }
}

void signal_handler(int signal) {
    printf("Received signal %d, shutting down\n", signal);
    close(listen_sock_fd);
    close(conn_sock_fd);
    exit(EXIT_SUCCESS);
}

void set_signal_handler() {
    struct sigaction sa;
    sa.sa_handler = signal_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGINT, &sa, NULL);
    sigaction(SIGTERM, &sa, NULL);
}

void handle_connection() {
    char buffer[BUFFER_SIZE];
    int n;
    while ((n = recv(conn_sock_fd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[n] = '\0';
        printf("Received message: %s", buffer);
    }
    if (n < 0) {
        perror("Error receiving message");
    }
    close(conn_sock_fd);
}

void accept_connection() {
    struct sockaddr_in addr;
    socklen_t addrlen = sizeof(addr);
    conn_sock_fd = accept(listen_sock_fd, (struct sockaddr *)&addr, &addrlen);
    if (conn_sock_fd < 0) {
        perror("Error accepting connection");
    } else {
        printf("Accepted connection from %s:%d\n", inet_ntoa(addr.sin_addr), ntohs(addr.sin_port));
        handle_connection();
    }
}

int main() {
    set_signal_handler();
    init_socket();
    while (1) {
        accept_connection();
    }
    return 0;
}