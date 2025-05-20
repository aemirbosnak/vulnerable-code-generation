//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define MAX_DATA_SIZE 1024
#define PING_TIMEOUT 5 // In seconds

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Port Number>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    int port_number = atoi(argv[2]);

    // Create socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    // Set timeout for socket
    struct timeval timeout;
    timeout.tv_sec = PING_TIMEOUT;
    timeout.tv_usec = 0;
    setsockopt(socket_fd, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout));
    setsockopt(socket_fd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));

    // Resolve IP address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_number);
    if (inet_pton(AF_INET, ip_address, &server_addr.sin_addr) <= 0) {
        printf("Invalid IP address\n");
        close(socket_fd);
        return 1;
    }

    // Connect to server
    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        close(socket_fd);
        return 1;
    }

    // Send data to server
    char send_data[MAX_DATA_SIZE];
    memset(send_data, 'A', MAX_DATA_SIZE);
    int bytes_sent = send(socket_fd, send_data, MAX_DATA_SIZE, 0);
    if (bytes_sent == -1) {
        printf("Error sending data\n");
        close(socket_fd);
        return 1;
    }

    // Receive data from server
    char recv_data[MAX_DATA_SIZE];
    int bytes_received = recv(socket_fd, recv_data, MAX_DATA_SIZE, 0);
    if (bytes_received == -1) {
        printf("Error receiving data\n");
        close(socket_fd);
        return 1;
    }

    // Print received data
    printf("Received data: %s\n", recv_data);

    // Close socket
    close(socket_fd);
    return 0;
}