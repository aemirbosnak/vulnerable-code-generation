#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_PORT 65535

void scan_port(char *ip, int port) {
    struct sockaddr_in server_addr;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Socket creation failed");
        return;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, ip, &server_addr.sin_addr) <= 0) {
        printf("Invalid address/ Address not supported\n");
        close(sock);
        return;
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
        char buffer[1024];
        int bytes_received = recv(sock, buffer, sizeof(buffer), 0);
        if (bytes_received > 0) {
            buffer[bytes_received] = '\0';
            printf("Port %d is open. Response: %s\n", port, buffer);
        } else {
            printf("Port %d is open.\n", port);
        }
    } else {
        printf("Port %d is closed.\n", port);
    }

    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <IP> <start_port> <end_port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port < 1 || start_port > MAX_PORT || end_port < 1 || end_port > MAX_PORT || start_port > end_port) {
        fprintf(stderr, "Invalid port range.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = start_port; i <= end_port; i++) {
        scan_port(ip, i);
    }

    return 0;
}
