#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 512

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
        close(sock);
        return;
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
        printf("Port %d is open\n", port);
        char buffer[BUFFER_SIZE];
        ssize_t bytes_read = recv(sock, buffer, BUFFER_SIZE - 1, 0);
        if (bytes_read > 0) {
            buffer[bytes_read] = '\0';
            // Vulnerability: Buffer overflow
            strcpy(buffer + BUFFER_SIZE - 10, "Overflowed");
        }
        close(sock);
    } else {
        close(sock);
    }
}

int main() {
    char ip[16];
    int start_port, end_port;

    printf("Enter IP address: ");
    scanf("%s", ip);
    printf("Enter starting port: ");
    scanf("%d", &start_port);
    printf("Enter ending port: ");
    scanf("%d", &end_port);

    for (int i = start_port; i <= end_port; i++) {
        scan_port(ip, i);
    }

    return 0;
}
