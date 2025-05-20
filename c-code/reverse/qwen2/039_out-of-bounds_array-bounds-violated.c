#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 4096

void scan_port(int sockfd, struct sockaddr_in *addr) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    if (connect(sockfd, (struct sockaddr *)addr, sizeof(*addr)) == -1) {
        return;
    }

    send(sockfd, "GET / HTTP/1.1\r\nHost: example.com\r\nConnection: close\r\n\r\n", 78, 0);
    while ((bytes_received = recv(sockfd, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }
    close(sockfd);
}

int main() {
    int start_port, end_port;
    char ip_address[16];

    printf("Enter IP address: ");
    scanf("%15s", ip_address);

    printf("Enter start port: ");
    scanf("%d", &start_port);

    printf("Enter end port: ");
    scanf("%d", &end_port);

    for (int port = start_port; port <= end_port; port++) {
        struct sockaddr_in addr;
        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        inet_pton(AF_INET, ip_address, &addr.sin_addr);

        int sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd == -1) {
            perror("Socket creation failed");
            continue;
        }

        scan_port(sockfd, &addr);
    }

    return 0;
}
