//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char send_buffer[BUFFER_SIZE];
    char recv_buffer[BUFFER_SIZE];

    // Check if the correct number of arguments are provided
    if (argc!= 3) {
        printf("Usage:./ping_test <IP address> <port number>\n");
        exit(1);
    }

    // Convert IP address from string to binary format
    struct in_addr ipaddr;
    inet_pton(AF_INET, argv[1], &ipaddr);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set up server address structure
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    serv_addr.sin_addr.s_addr = ipaddr.s_addr;

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Send data to server
    sprintf(send_buffer, "PING");
    n = send(sockfd, send_buffer, strlen(send_buffer), 0);
    if (n == -1) {
        printf("Error sending data\n");
        exit(1);
    }

    // Receive data from server
    n = recv(sockfd, recv_buffer, BUFFER_SIZE, 0);
    if (n == -1) {
        printf("Error receiving data\n");
        exit(1);
    }

    // Close socket
    close(sockfd);

    if (n > 0) {
        printf("Server responded with: %s\n", recv_buffer);
    } else {
        printf("No response from server\n");
    }

    return 0;
}