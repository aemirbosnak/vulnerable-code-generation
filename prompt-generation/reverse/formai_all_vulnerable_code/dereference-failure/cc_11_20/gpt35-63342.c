//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUFF_SIZE 4096

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <listen-port> <target-address:target-port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int listen_port = atoi(argv[1]);
    char* target_address = strtok(argv[2], ":");
    int target_port = atoi(strtok(NULL, ":"));

    struct sockaddr_in listen_addr, target_addr;

    // Set up the listening address
    memset(&listen_addr, 0, sizeof(listen_addr));
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    listen_addr.sin_port = htons(listen_port);

    // Set up the target address
    memset(&target_addr, 0, sizeof(target_addr));
    target_addr.sin_family = AF_INET;
    target_addr.sin_addr.s_addr = inet_addr(target_address);
    target_addr.sin_port = htons(target_port);

    // Create the socket
    int listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock < 0) {
        perror("Error creating listening socket");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to the listening address
    if (bind(listen_sock, (struct sockaddr*)&listen_addr, sizeof(listen_addr)) < 0) {
        perror("Error binding listening socket");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(listen_sock, 5) < 0) {
        perror("Error listening");
        exit(EXIT_FAILURE);
    }

    while (1) {
        // Accept incoming connection
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sock = accept(listen_sock, (struct sockaddr*)&client_addr, &client_addr_len);
        if (client_sock < 0) {
            perror("Error accepting incoming connection");
            continue;
        }

        // Connect to target server
        int target_sock = socket(AF_INET, SOCK_STREAM, 0);
        if (target_sock < 0) {
            perror("Error creating target socket");
            close(client_sock);
            continue;
        }

        if (connect(target_sock, (struct sockaddr*)&target_addr, sizeof(target_addr)) < 0) {
            perror("Error connecting to target server");
            close(client_sock);
            close(target_sock);
            continue;
        }

        // Set up the file descriptors for select()
        fd_set read_fds;
        FD_ZERO(&read_fds);
        FD_SET(client_sock, &read_fds);
        FD_SET(target_sock, &read_fds);

        // Run the select loop to forward data between client and target
        while (1) {
            // Perform select()
            int max_fd = (client_sock > target_sock) ? client_sock : target_sock;
            int ready = select(max_fd + 1, &read_fds, NULL, NULL, NULL);
            if (ready < 0) {
                perror("Error in select()");
                break;
            }

            // Forward any available data from client to target
            if (FD_ISSET(client_sock, &read_fds)) {
                char buffer[MAX_BUFF_SIZE];
                int bytes_read = recv(client_sock, buffer, MAX_BUFF_SIZE, 0);
                if (bytes_read <= 0) {
                    break;
                }
                send(target_sock, buffer, bytes_read, 0);
            }

            // Forward any available data from target to client
            if (FD_ISSET(target_sock, &read_fds)) {
                char buffer[MAX_BUFF_SIZE];
                int bytes_read = recv(target_sock, buffer, MAX_BUFF_SIZE, 0);
                if (bytes_read <= 0) {
                    break;
                }
                send(client_sock, buffer, bytes_read, 0);
            }
        }

        // Close the sockets
        close(client_sock);
        close(target_sock);
    }

    return 0;
}