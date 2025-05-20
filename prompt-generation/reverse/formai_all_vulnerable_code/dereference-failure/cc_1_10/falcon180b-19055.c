//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: funny
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
#define PORT "8080"
#define BACKLOG 10
#define MAX_CLIENTS 10

int main(int argc, char *argv[]) {
    int listen_fd, conn_fd, new_socket, valread, sd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[1024];
    int addrlen = sizeof(cli_addr);
    char *message = "HTTP/1.1 200 OK\r\nContent-Type: text/html; charset=UTF-8\r\n\r\n<!DOCTYPE html>\n<html>\n<head>\n<title>Funny Socket Programming Example</title>\n</head>\n<body>\n<h1>Welcome to the Funny Socket Programming Example!</h1>\n<p>This is a funny example of socket programming in C.</p>\n</body>\n</html>";
    char hostname[1024];

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <ip_address>\n", argv[0]);
        exit(1);
    }

    strcpy(hostname, argv[1]);

    // Create socket
    if ((listen_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(1);
    }

    puts("Socket created");

    // Set socket options
    int opt = TRUE;
    if (setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt))) {
        perror("setsockopt");
        exit(1);
    }

    puts("Socket options set");

    // Fill in the server address structure
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(atoi(PORT));

    // Bind the server socket to a local address and port
    if (bind(listen_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    puts("Server bound to port");

    // Listen for incoming connections
    if (listen(listen_fd, BACKLOG) < 0) {
        perror("listen");
        exit(1);
    }

    puts("Server is listening");

    // Accept a connection
    if ((conn_fd = accept(listen_fd, (struct sockaddr *)&cli_addr, (socklen_t*)&addrlen)) < 0) {
        perror("accept");
        exit(1);
    }

    puts("Connection accepted");

    // Send a message to the client
    send(conn_fd, message, strlen(message), 0);

    close(conn_fd);
    close(listen_fd);

    return 0;
}