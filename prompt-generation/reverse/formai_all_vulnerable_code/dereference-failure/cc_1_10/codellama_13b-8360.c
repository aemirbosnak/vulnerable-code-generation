//Code Llama-13B DATASET v1.0 Category: TCP/IP Programming ; Style: modular
/*
 * A modular TCP/IP programming example program
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Modular functions
void error(char *msg) {
    perror(msg);
    exit(1);
}

int create_socket() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        error("Error creating socket");
    }
    return sock;
}

int bind_socket(int sock, int port) {
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = INADDR_ANY;
    if (bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        error("Error binding socket");
    }
    return sock;
}

int listen_socket(int sock) {
    if (listen(sock, 3) < 0) {
        error("Error listening on socket");
    }
    return sock;
}

int accept_connection(int sock) {
    struct sockaddr_in client;
    socklen_t client_len = sizeof(client);
    int client_sock = accept(sock, (struct sockaddr *)&client, &client_len);
    if (client_sock < 0) {
        error("Error accepting connection");
    }
    return client_sock;
}

int send_data(int sock, char *data) {
    if (send(sock, data, strlen(data), 0) < 0) {
        error("Error sending data");
    }
    return sock;
}

int receive_data(int sock, char *data, int data_len) {
    int len = recv(sock, data, data_len, 0);
    if (len < 0) {
        error("Error receiving data");
    }
    data[len] = '\0';
    return len;
}

int close_socket(int sock) {
    if (close(sock) < 0) {
        error("Error closing socket");
    }
    return sock;
}

// Main function
int main() {
    int sock = create_socket();
    sock = bind_socket(sock, 8080);
    sock = listen_socket(sock);
    int client_sock = accept_connection(sock);
    char data[1024];
    int len = receive_data(client_sock, data, sizeof(data));
    printf("Received: %s\n", data);
    send_data(client_sock, "Hello, client!");
    close_socket(client_sock);
    close_socket(sock);
    return 0;
}