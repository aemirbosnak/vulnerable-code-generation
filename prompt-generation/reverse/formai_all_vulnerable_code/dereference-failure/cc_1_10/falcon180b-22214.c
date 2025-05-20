//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void print_error(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        print_error("Usage:./ping hostname port");
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        print_error("Failed to create socket");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
        print_error("Invalid hostname");
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        close(sock);
        print_error("Failed to connect to server");
    }

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    send(sock, "PING", strlen("PING"), 0);

    int bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
    if (bytes_received <= 0) {
        close(sock);
        print_error("Failed to receive response");
    }

    if (strcmp(buffer, "PONG")!= 0) {
        close(sock);
        print_error("Invalid response");
    }

    close(sock);
    printf("Server is reachable\n");

    return 0;
}