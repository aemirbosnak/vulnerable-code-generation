//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT_MIN 0
#define PORT_MAX 65535
#define DEFAULT_HOST "127.0.0.1"
#define DEFAULT_PORT 80
#define BACKLOG 5
#define MAX_CONNECTIONS 10
#define BUFFER_SIZE 1024

char *BANNER = "Port Scanner v1.0\n";

int main(int argc, char *argv[]) {
    // Parse command line arguments.
    if (argc < 2) {
        printf("Usage: %s <host> [<port>]\n", argv[0]);
        return EXIT_FAILURE;
    }
    char *host = argv[1];
    int port = DEFAULT_PORT;
    if (argc >= 3) {
        port = atoi(argv[2]);
    }
    // Create a socket.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }
    // Set the socket options.
    int reuseaddr = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &reuseaddr, sizeof(reuseaddr)) == -1) {
        perror("setsockopt");
        close(sockfd);
        return EXIT_FAILURE;
    }
    // Bind the socket to the host and port.
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(host);
    addr.sin_port = htons(port);
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        close(sockfd);
        return EXIT_FAILURE;
    }
    // Listen for incoming connections.
    if (listen(sockfd, BACKLOG) == -1) {
        perror("listen");
        close(sockfd);
        return EXIT_FAILURE;
    }
    // Accept incoming connections.
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    fd_set read_fds;
    int max_fd = sockfd;
    int clients[MAX_CONNECTIONS];
    int num_clients = 0;
    while (1) {
        // Set the read file descriptors.
        FD_ZERO(&read_fds);
        FD_SET(sockfd, &read_fds);
        for (int i = 0; i < num_clients; i++) {
            FD_SET(clients[i], &read_fds);
            if (clients[i] > max_fd) {
                max_fd = clients[i];
            }
        }
        // Select the ready file descriptors.
        if (select(max_fd + 1, &read_fds, NULL, NULL, NULL) == -1) {
            perror("select");
            close(sockfd);
            return EXIT_FAILURE;
        }
        // Accept new connections.
        if (FD_ISSET(sockfd, &read_fds)) {
            int client_fd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
            if (client_fd == -1) {
                perror("accept");
                continue;
            }
            if (num_clients >= MAX_CONNECTIONS) {
                printf("Too many connections, closing new connection\n");
                close(client_fd);
                continue;
            }
            clients[num_clients] = client_fd;
            num_clients++;
        }
        // Read data from clients.
        for (int i = 0; i < num_clients; i++) {
            if (FD_ISSET(clients[i], &read_fds)) {
                char buffer[BUFFER_SIZE];
                int bytes_read = read(clients[i], buffer, BUFFER_SIZE);
                if (bytes_read == -1) {
                    perror("read");
                    close(clients[i]);
                    clients[i] = clients[num_clients - 1];
                    num_clients--;
                    continue;
                } else if (bytes_read == 0) {
                    close(clients[i]);
                    clients[i] = clients[num_clients - 1];
                    num_clients--;
                    continue;
                }
                // Process the data.
                printf("Received %d bytes from client %s:%d\n", bytes_read, inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
                // Send the data back to the client.
                if (write(clients[i], buffer, bytes_read) == -1) {
                    perror("write");
                }
            }
        }
    }
    // Close the socket.
    close(sockfd);
    return EXIT_SUCCESS;
}