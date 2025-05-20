//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 1024

void error_handling(char *message) {
    perror(message);
    exit(1);
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s <IP address> <Port number>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    int port_number = atoi(argv[2]);

    int socket_fd, new_socket_fd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUF_SIZE];

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1)
        error_handling("socket failed");

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip_address);
    server_addr.sin_port = htons(port_number);

    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
        error_handling("connect failed");

    printf("Connected to server\n");

    while (1) {
        bzero(buffer, BUF_SIZE);
        int bytes_received = recv(socket_fd, buffer, BUF_SIZE, 0);
        if (bytes_received <= 0) {
            printf("Disconnected from server\n");
            break;
        }
        buffer[bytes_received] = '\0';
        printf("Received message: %s\n", buffer);
    }

    close(socket_fd);
    return 0;
}