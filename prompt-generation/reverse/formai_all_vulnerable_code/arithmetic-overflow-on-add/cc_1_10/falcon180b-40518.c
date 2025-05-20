//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

void scan_port(int sockfd, int port) {
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
        printf("Port %d is open\n", port);
        close(sockfd);
    } else {
        printf("Port %d is closed\n", port);
    }
}

void scan_ports(int start_port, int end_port) {
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Error: Could not create socket\n");
        return;
    }

    for (int i = start_port; i <= end_port; i++) {
        scan_port(sockfd, i);
    }

    close(sockfd);
}

int main() {
    int start_port, end_port;

    printf("Enter start port: ");
    scanf("%d", &start_port);

    printf("Enter end port: ");
    scanf("%d", &end_port);

    scan_ports(start_port, end_port);

    return 0;
}