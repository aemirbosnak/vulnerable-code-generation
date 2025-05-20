#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024

void scan_port(int ip, int start_port, int end_port) {
    struct sockaddr_in server_addr;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Socket creation failed");
        return;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;

    for (int port = start_port; port <= end_port; port++) {
        server_addr.sin_port = htons(port);

        if (inet_pton(AF_INET, inet_ntoa(*(struct in_addr *)&ip), &server_addr.sin_addr) <= 0) {
            printf("Invalid address/ Address not supported\n");
            close(sock);
            return;
        }

        if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
            char buffer[1024];
            ssize_t bytes_received = recv(sock, buffer, sizeof(buffer) - 1, 0);
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
        sleep(1); // Prevent flooding the target with requests
    }
}

int main() {
    int ip = 0x7F000001; // 127.0.0.1
    int start_port = 1;
    int end_port = PORT_RANGE;

    scan_port(ip, start_port, end_port);

    return 0;
}
