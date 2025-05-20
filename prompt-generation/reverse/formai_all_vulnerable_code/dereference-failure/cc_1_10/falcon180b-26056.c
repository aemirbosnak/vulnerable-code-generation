//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_DATA_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char data[MAX_DATA_SIZE];
    int data_len;
    int ret;

    // Check if the correct number of arguments are provided
    if (argc!= 4) {
        printf("Usage: %s <IP Address> <Port> <Number of Packets>\n", argv[0]);
        return 1;
    }

    // Convert IP address and port number from string to integer
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);
    server_addr.sin_port = htons(atoi(argv[2]));

    // Create socket
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    // Send packets
    for (int i = 0; i < atoi(argv[3]); i++) {
        memset(data, i, MAX_DATA_SIZE);
        data_len = sendto(sock, data, MAX_DATA_SIZE, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
        if (data_len == -1) {
            printf("Error sending packet: %s\n", strerror(errno));
            close(sock);
            return 1;
        }
        printf("Sent packet %d\n", i + 1);
    }

    // Receive packets
    char buffer[MAX_DATA_SIZE];
    while (1) {
        memset(data, 0, MAX_DATA_SIZE);
        data_len = recv(sock, data, MAX_DATA_SIZE, 0);
        if (data_len <= 0) {
            printf("No more packets to receive\n");
            break;
        }
        printf("Received packet: %s\n", data);
    }

    // Close socket
    close(sock);
    return 0;
}