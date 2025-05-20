//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

void scan_ports(int sockfd, const char* hostname, int start_port, int end_port) {
    int port;
    for (port = start_port; port <= end_port; ++port) {
        int client_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (client_socket == -1) {
            perror("socket");
            exit(1);
        }

        struct sockaddr_in server_addr;
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);
        inet_pton(AF_INET, hostname, &server_addr.sin_addr);

        if (connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == 0) {
            char buffer[BUFFER_SIZE];
            int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
            if (bytes_received > 0) {
                printf("Port %d is open on %s\n", port, hostname);
            } else {
                printf("Port %d is closed on %s\n", port, hostname);
            }
            close(client_socket);
        } else {
            printf("Port %d is closed on %s\n", port, hostname);
        }
    }
}

int main(int argc, char** argv) {
    if (argc < 4) {
        printf("Usage: %s hostname start_port end_port\n", argv[0]);
        return 1;
    }

    const char* hostname = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(start_port);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    scan_ports(sockfd, hostname, start_port, end_port);

    close(sockfd);
    return 0;
}