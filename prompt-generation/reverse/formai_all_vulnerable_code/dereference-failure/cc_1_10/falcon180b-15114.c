//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

// Function to create a socket
int create_socket(int sock_type, int protocol) {
    int sock = socket(AF_INET, sock_type, protocol);
    if (sock == -1) {
        printf("Error: Failed to create socket\n");
        exit(1);
    }
    return sock;
}

// Function to connect to a remote host
int connect_to_host(int sock, const char* hostname, int port) {
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Failed to connect to host\n");
        close(sock);
        exit(1);
    }
    return sock;
}

// Function to send a ping request
int send_ping_request(int sock) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    sprintf(buffer, "PING %s\r\n", "example.com");

    if (send(sock, buffer, strlen(buffer), 0) == -1) {
        printf("Error: Failed to send ping request\n");
        close(sock);
        exit(1);
    }
    return sock;
}

// Function to receive a ping response
int receive_ping_response(int sock) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    if (recv(sock, buffer, BUFFER_SIZE, 0) == -1) {
        printf("Error: Failed to receive ping response\n");
        close(sock);
        exit(1);
    }

    printf("Ping response: %s\n", buffer);
    close(sock);
    exit(0);
}

int main(int argc, char** argv) {
    if (argc!= 3) {
        printf("Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    int sock = create_socket(SOCK_STREAM, IPPROTO_TCP);
    sock = connect_to_host(sock, argv[1], atoi(argv[2]));
    sock = send_ping_request(sock);
    receive_ping_response(sock);

    return 0;
}