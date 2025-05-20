//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define BUFFER_SIZE 1024

void die_with_error(const char *error_msg) {
    perror(error_msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <IP address> <port number>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    int port_number = atoi(argv[2]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        die_with_error("socket");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_number);
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        die_with_error("connect");
    }

    char send_buffer[BUFFER_SIZE];
    memset(send_buffer, 'A', BUFFER_SIZE);
    send(sockfd, send_buffer, BUFFER_SIZE, 0);

    char recv_buffer[BUFFER_SIZE];
    int bytes_received = recv(sockfd, recv_buffer, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        die_with_error("recv");
    }

    close(sockfd);

    printf("Received %d bytes from server:\n%s\n", bytes_received, recv_buffer);

    return 0;
}