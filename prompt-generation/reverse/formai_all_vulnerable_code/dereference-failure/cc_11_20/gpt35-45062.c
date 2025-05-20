//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 30
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <ip> <port>\n", argv[0]);
        exit(1);
    }

    char *ip = argv[1];
    int port = atoi(argv[2]);
    int server_fd, client_fds[MAX_CLIENTS], activity, valread, sd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];

    // Create server socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(1);
    }

    // Set server address structure
    memset(&server_addr, '0', sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip);
    server_addr.sin_port = htons(port);

    // Bind server socket to defined address
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        exit(1);
    }

    // Accept incoming connections
    int addrlen = sizeof(client_addr);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        client_fds[i] = 0;
    }
    while (1) {
        fd_set read_fds;
        FD_ZERO(&read_fds);
        FD_SET(server_fd, &read_fds);
        int max_sd = server_fd;
        for (int i = 0; i < MAX_CLIENTS; i++) {
            sd = client_fds[i];
            if (sd > 0) {
                FD_SET(sd, &read_fds);
            }
            if (sd > max_sd) {
                max_sd = sd;
            }
        }
        activity = select(max_sd + 1, &read_fds, NULL, NULL, NULL);
        if (activity < 0) {
            perror("Select failed");
            exit(1);
        }
        if (FD_ISSET(server_fd, &read_fds)) {
            int new_socket;
            if ((new_socket = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t *)&addrlen)) < 0) {
                perror("Accept failed");
                exit(1);
            }
            printf("New connection: %s:%d, socket fd is %d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port), new_socket);
            for (int i = 0; i < MAX_CLIENTS; i++) {
                if (client_fds[i] == 0) {
                    client_fds[i] = new_socket;
                    break;
                }
            }
        }
        for (int i = 0; i < MAX_CLIENTS; i++) {
            sd = client_fds[i];
            if (FD_ISSET(sd, &read_fds)) {
                if ((valread = read(sd, buffer, BUFFER_SIZE)) == 0) {
                    getpeername(sd, (struct sockaddr *)&client_addr, (socklen_t *)&addrlen);
                    printf("Host disconnected: %s:%d, socket fd is %d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port), sd);
                    close(sd);
                    client_fds[i] = 0;
                } else {
                    buffer[valread] = '\0';
                    printf("Received message from %s:%d, socket fd is %d: %s", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port), sd, buffer);
                    write(sd, buffer, strlen(buffer));
                }
            }
        }
    }
    return 0;
}