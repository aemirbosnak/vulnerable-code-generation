//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

void handle_request(int client_socket) {
    char buffer[BUFFER_SIZE];
    char method[BUFFER_SIZE], path[BUFFER_SIZE], protocol[BUFFER_SIZE];
    int port = 80;

    recv(client_socket, buffer, BUFFER_SIZE, 0);

    sscanf(buffer, "%s %s %s", method, path, protocol);

    // parse host name and port number from path
    char *host_name = strtok(path, ":");
    char *port_str = strtok(NULL, "/");
    if (port_str != NULL)
        port = atoi(port_str);

    // remove http:// from host name
    if (strncmp(host_name, "http://", 7) == 0)
        host_name += 7;

    // resolve host name to an IP address
    struct hostent *he = gethostbyname(host_name);
    if (he == NULL) {
        printf("Error resolving host %s: %s\n", host_name, hstrerror(h_errno));
        return;
    }

    // create a socket for the new connection
    int server_socket = socket(PF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        printf("Error creating server socket: %s\n", strerror(errno));
        return;
    }

    // connect to the remote server
    struct sockaddr_in server_addr = {0};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr, he->h_addr_list[0], he->h_length);
    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) != 0) {
        printf("Error connecting to server %s:%d: %s\n", host_name, port, strerror(errno));
        return;
    }

    // forward the request to the remote server
    send(server_socket, buffer, strlen(buffer), 0);

    // receive the response from the remote server and forward it to the client
    int bytes_received;
    while ((bytes_received = recv(server_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        send(client_socket, buffer, bytes_received, 0);
    }

    close(server_socket);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    int port = atoi(argv[1]);

    int server_socket = socket(PF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        printf("Error creating server socket: %s\n", strerror(errno));
        exit(1);
    }

    struct sockaddr_in server_addr = {0};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error binding server socket to port %d: %s\n", port, strerror(errno));
        exit(1);
    }

    if (listen(server_socket, 100) < 0) {
        printf("Error listening on server socket: %s\n", strerror(errno));
        exit(1);
    }

    while (1) {
        struct sockaddr_in client_addr = {0};
        socklen_t client_addr_len = sizeof(client_addr);
        int client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);

        if (client_socket < 0) {
            printf("Error accepting client connection: %s\n", strerror(errno));
            continue;
        }

        handle_request(client_socket);
        close(client_socket);
    }

    close(server_socket);
    return 0;
}