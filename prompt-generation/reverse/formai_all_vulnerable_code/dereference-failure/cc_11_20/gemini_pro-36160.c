//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main() {
    int listening_socket, client_socket, remote_socket;
    struct sockaddr_in listening_address, client_address, remote_address;
    unsigned int client_address_length, remote_address_length;
    char buffer[BUFFER_SIZE];
    int bytes_received, bytes_sent;

    // create listening socket
    listening_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listening_socket < 0) {
        perror("socket");
        exit(1);
    }

    // set up listening address
    memset(&listening_address, 0, sizeof(listening_address));
    listening_address.sin_family = AF_INET;
    listening_address.sin_port = htons(8080); // listen on port 8080
    listening_address.sin_addr.s_addr = htonl(INADDR_ANY); // listen on all interfaces

    // bind listening socket to listening address
    if (bind(listening_socket, (struct sockaddr *) &listening_address, sizeof(listening_address)) < 0) {
        perror("bind");
        exit(1);
    }

    // listen for incoming connections
    if (listen(listening_socket, 5) < 0) { // allow up to 5 pending connections
        perror("listen");
        exit(1);
    }

    // main loop: accept incoming connections and handle requests
    while (1) {
        // accept incoming connection
        client_address_length = sizeof(client_address);
        client_socket = accept(listening_socket, (struct sockaddr *) &client_address, &client_address_length);
        if (client_socket < 0) {
            perror("accept");
            continue;
        }

        // parse HTTP request
        bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received < 0) {
            perror("recv");
            close(client_socket);
            continue;
        }
        char *request_method = strtok(buffer, " ");
        char *request_uri = strtok(NULL, " ");
        char *http_version = strtok(NULL, "\r\n");

        // handle GET requests only
        if (strcmp(request_method, "GET") != 0) {
            close(client_socket);
            continue;
        }

        // connect to remote server
        remote_address_length = sizeof(remote_address);
        if (strcmp(request_uri, "/") == 0) {
            remote_address.sin_family = AF_INET;
            remote_address.sin_port = htons(80); // connect to port 80 of the remote server
            remote_address.sin_addr.s_addr = inet_addr("127.0.0.1"); // connect to localhost
        } else {
            char *hostname = strtok(request_uri, "/");
            remote_address.sin_family = AF_INET;
            remote_address.sin_port = htons(80); // connect to port 80 of the remote server
            remote_address.sin_addr.s_addr = inet_addr(hostname); // connect to the specified hostname
        }
        remote_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (remote_socket < 0) {
            perror("socket");
            close(client_socket);
            continue;
        }
        if (connect(remote_socket, (struct sockaddr *) &remote_address, remote_address_length) < 0) {
            perror("connect");
            close(client_socket);
            close(remote_socket);
            continue;
        }

        // forward request to remote server
        bytes_sent = send(remote_socket, buffer, bytes_received, 0);
        if (bytes_sent < 0) {
            perror("send");
            close(client_socket);
            close(remote_socket);
            continue;
        }

        // receive response from remote server
        bytes_received = recv(remote_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received < 0) {
            perror("recv");
            close(client_socket);
            close(remote_socket);
            continue;
        }

        // forward response to client
        bytes_sent = send(client_socket, buffer, bytes_received, 0);
        if (bytes_sent < 0) {
            perror("send");
            close(client_socket);
            close(remote_socket);
            continue;
        }

        // close connections
        close(client_socket);
        close(remote_socket);
    }

    // close listening socket
    close(listening_socket);

    return 0;
}