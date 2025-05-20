//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFSIZE 4096

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <local-ip> <local-port> <remote-ip>\n", argv[0]);
        exit(1);
    }

    int local_sock, remote_sock;
    struct sockaddr_in local_addr, remote_addr;
    char buf[BUFSIZE];
    int bytes_read, bytes_sent;

    // Create a local socket for listening to client connections
    local_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (local_sock == -1) {
        perror("socket");
        exit(1);
    }

    // Set up the local address and port
    memset(&local_addr, 0, sizeof(local_addr));
    local_addr.sin_family = AF_INET;
    local_addr.sin_addr.s_addr = inet_addr(argv[1]);
    local_addr.sin_port = htons(atoi(argv[2]));

    // Bind the local socket to the address and port
    if (bind(local_sock, (struct sockaddr *)&local_addr, sizeof(local_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    // Start listening for client connections
    if (listen(local_sock, 5) == -1) {
        perror("listen");
        exit(1);
    }

    // Accept a client connection
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    remote_sock = accept(local_sock, (struct sockaddr *)&client_addr, &client_addr_len);
    if (remote_sock == -1) {
        perror("accept");
        exit(1);
    }

    // Set up the remote address and port
    memset(&remote_addr, 0, sizeof(remote_addr));
    remote_addr.sin_family = AF_INET;
    remote_addr.sin_addr.s_addr = inet_addr(argv[3]);
    remote_addr.sin_port = htons(80);

    // Connect to the remote server
    if (connect(remote_sock, (struct sockaddr *)&remote_addr, sizeof(remote_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    // Loop forever, reading data from the client and writing it to the server, and vice versa
    while (1) {
        // Read data from the client
        bytes_read = recv(remote_sock, buf, BUFSIZE, 0);
        if (bytes_read == -1) {
            perror("recv");
            exit(1);
        } else if (bytes_read == 0) {
            // Client has closed the connection
            break;
        }

        // Write the data to the server
        bytes_sent = send(local_sock, buf, bytes_read, 0);
        if (bytes_sent == -1) {
            perror("send");
            exit(1);
        }
    }

    // Close the sockets
    close(local_sock);
    close(remote_sock);

    return 0;
}