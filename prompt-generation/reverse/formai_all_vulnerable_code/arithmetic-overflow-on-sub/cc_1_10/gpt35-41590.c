//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <ip address> <port number>\n", argv[0]);
        return -1;
    }

    char *ip_address = argv[1];
    int port_number = atoi(argv[2]);

    // Creating socket file descriptor
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        printf("Error: Creating Socket file descriptor failed. %s\n", strerror(errno));
        return -1;
    }

    printf("Socket file descriptor created successfully.\n");

    // Set address information
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(ip_address);
    server_address.sin_port = htons(port_number);

    // Connect to server
    if (connect(socket_fd, (struct sockaddr*)&server_address, sizeof(server_address)) != 0) {
        printf("Error: Connection to server failed. %s\n", strerror(errno));
        return -1;
    }

    printf("Connected to the server successfully.\n");

    // Prepare message
    char buffer[MAX_BUFFER_SIZE] = {0};
    snprintf(buffer, MAX_BUFFER_SIZE, "GET / HTTP/1.1\r\nHost:%s\r\n\r\n", ip_address);

    // Start time
    struct timeval start, end;
    gettimeofday(&start, NULL);

    // Send message
    if (send(socket_fd, buffer, strlen(buffer), 0) < 0) {
        printf("Error: Could not send message. %s\n", strerror(errno));
        return -1;
    }

    printf("Message sent successfully.\n");

    // Receive response
    char response_buffer[MAX_BUFFER_SIZE] = {0};
    int num_bytes = recv(socket_fd, response_buffer, MAX_BUFFER_SIZE, 0);
    if (num_bytes < 0) {
        printf("Error: Could not receive response. %s\n", strerror(errno));
        return -1;
    }

    // Stop time
    gettimeofday(&end, NULL);
    long int time_taken = (end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec);
    float time_taken_in_seconds = time_taken / 1000000.0;
    printf("Time taken to receive response: %.2f seconds\n", time_taken_in_seconds);

    printf("Response: %s\n", response_buffer);

    // Close the socket
    close(socket_fd);

    return 0;
}