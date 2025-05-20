//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_DATA_SIZE 1024
#define TRUE 1
#define FALSE 0

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <IP address> <port number>\n", argv[0]);
        exit(1);
    }

    char *ip_address = argv[1];
    int port_number = atoi(argv[2]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket.\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_number);

    if (inet_pton(AF_INET, ip_address, &server_addr.sin_addr) <= 0) {
        printf("Invalid IP address.\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server.\n");
        exit(1);
    }

    char send_data[] = "PING";
    if (send(sockfd, send_data, strlen(send_data), 0) == -1) {
        printf("Error sending data.\n");
        exit(1);
    }

    char recv_data[MAX_DATA_SIZE];
    int bytes_received = recv(sockfd, recv_data, MAX_DATA_SIZE, 0);
    if (bytes_received <= 0) {
        printf("Error receiving data.\n");
        exit(1);
    }

    printf("Received response: %s\n", recv_data);

    close(sockfd);
    return 0;
}