//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_DATA 1024

// Function to print error message and exit
void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Port>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    int port = atoi(argv[2]);

    // Create socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        error("socket");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, ip_address, &server_addr.sin_addr) <= 0) {
        error("inet_pton");
    }

    // Connect to server
    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        error("connect");
    }

    char send_buffer[MAX_DATA];
    char recv_buffer[MAX_DATA];

    while (1) {
        // Send data to server
        sprintf(send_buffer, "QoS Request");
        if (send(socket_fd, send_buffer, strlen(send_buffer), 0) == -1) {
            error("send");
        }

        // Receive data from server
        int bytes_received = recv(socket_fd, recv_buffer, MAX_DATA, 0);
        if (bytes_received <= 0) {
            error("recv");
        }

        printf("Received data: %s\n", recv_buffer);
    }

    close(socket_fd);
    return 0;
}