//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    if (argc < 4) {
        printf("Usage: %s <proxy_port> <remote_host> <remote_port>\n", argv[0]);
        return 0;
    }

    int proxy_port = atoi(argv[1]);
    char *remote_host = argv[2];
    int remote_port = atoi(argv[3]);

    // Create a TCP socket for the proxy server
    int proxy_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_socket < 0) {
        perror("Error creating proxy socket");
        return 1;
    }

    // Bind the TCP socket to the proxy port
    struct sockaddr_in proxy_address;
    memset(&proxy_address, 0, sizeof(proxy_address));
    proxy_address.sin_family = AF_INET;
    proxy_address.sin_addr.s_addr = htonl(INADDR_ANY);
    proxy_address.sin_port = htons(proxy_port);
    if (bind(proxy_socket, (struct sockaddr *) &proxy_address, sizeof(proxy_address)) < 0) {
        perror("Error binding proxy socket");
        return 1;
    }

    // Listen for incoming connections
    if (listen(proxy_socket, 128) < 0) {
        perror("Error listening for connections");
        return 1;
    }

    while (1) {

        // Accept a client connection
        struct sockaddr_in client_address;
        socklen_t client_address_length = sizeof(client_address);
        int client_socket = accept(proxy_socket, (struct sockaddr *) &client_address, &client_address_length);
        if (client_socket < 0) {
            perror("Error accepting client connection");
            continue;
        }

        // Connect to the remote server
        int remote_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (remote_socket < 0) {
            perror("Error creating remote socket");
            close(client_socket);
            continue;
        }
        struct sockaddr_in remote_address;
        memset(&remote_address, 0, sizeof(remote_address));
        remote_address.sin_family = AF_INET;
        remote_address.sin_addr.s_addr = inet_addr(remote_host);
        remote_address.sin_port = htons(remote_port);
        if (connect(remote_socket, (struct sockaddr *) &remote_address, sizeof(remote_address)) < 0) {
            perror("Error connecting to remote server");
            close(client_socket);
            close(remote_socket);
            continue;
        }

        // Relay data between client and remote server
        fd_set read_fds;
        FD_ZERO(&read_fds);
        FD_SET(client_socket, &read_fds);
        FD_SET(remote_socket, &read_fds);

        int max_fd = (client_socket > remote_socket) ? client_socket : remote_socket;
        char buffer[BUFFER_SIZE];
        int nbytes;
        while (1) {
            fd_set tmp_fds = read_fds;
            if (select(max_fd + 1, &tmp_fds, NULL, NULL, NULL) < 0) {
                perror("Error in select");
                break;
            }

            if (FD_ISSET(client_socket, &tmp_fds)) {
                nbytes = recv(client_socket, buffer, BUFFER_SIZE, 0);
                if (nbytes < 0) {
                    perror("Error receiving data from client");
                    break;
                } else if (nbytes == 0) {
                    break;
                }

                if (send(remote_socket, buffer, nbytes, 0) < 0) {
                    perror("Error sending data to remote server");
                    break;
                }
            }

            if (FD_ISSET(remote_socket, &tmp_fds)) {
                nbytes = recv(remote_socket, buffer, BUFFER_SIZE, 0);
                if (nbytes < 0) {
                    perror("Error receiving data from remote server");
                    break;
                } else if (nbytes == 0) {
                    break;
                }

                if (send(client_socket, buffer, nbytes, 0) < 0) {
                    perror("Error sending data to client");
                    break;
                }
            }
        }

        // Close sockets and clean up
        close(client_socket);
        close(remote_socket);

    }

    close(proxy_socket);
    return 0;
}