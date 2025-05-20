//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

void scan_port(int sockfd, struct sockaddr_in *addr, int port) {
    int result = connect(sockfd, (struct sockaddr *)addr, sizeof(struct sockaddr_in));
    if (result == 0) {
        printf("Port %d is open\n", port);
    } else {
        printf("Port %d is closed\n", port);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage:./port_scanner <IP Address> <Start Port> <End Port>\n");
        return 1;
    }

    char *ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    struct hostent *host = gethostbyname(ip);
    if (host == NULL) {
        printf("Invalid IP address\n");
        return 1;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Socket creation failed\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(start_port);
    inet_pton(AF_INET, ip, &server_addr.sin_addr);

    for (int i = start_port; i <= end_port; i++) {
        server_addr.sin_port = htons(i);
        scan_port(sockfd, &server_addr, i);
    }

    close(sockfd);
    return 0;
}