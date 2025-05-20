//Falcon-180B DATASET v1.0 Category: Networking ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <IP address> <port number>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    int port_number = atoi(argv[2]);

    int sockfd;
    struct sockaddr_in server_addr;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: socket creation failed: %s\n", strerror(errno));
        return 1;
    }

    printf("Socket created successfully\n");

    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);
    server_addr.sin_port = htons(port_number);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: connection failed: %s\n", strerror(errno));
        close(sockfd);
        return 1;
    }

    printf("Connected to server\n");

    // Send data to server
    char send_buffer[BUFFER_SIZE];
    memset(send_buffer, 0, BUFFER_SIZE);
    strcat(send_buffer, "Hello, World!");
    send(sockfd, send_buffer, strlen(send_buffer), 0);

    // Receive data from server
    char recv_buffer[BUFFER_SIZE];
    memset(recv_buffer, 0, BUFFER_SIZE);
    int bytes_received = recv(sockfd, recv_buffer, BUFFER_SIZE, 0);

    if (bytes_received <= 0) {
        printf("Error: failed to receive data from server\n");
        close(sockfd);
        return 1;
    }

    printf("Received data from server: %s\n", recv_buffer);

    // Close socket
    close(sockfd);

    return 0;
}