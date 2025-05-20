//FormAI DATASET v1.0 Category: Port Scanner ; Style: high level of detail
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

/* Wrapper function for creating a socket */
int create_socket() {
    int sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockfd < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
    return sockfd;
}

/* Function for scanning a specified port using TCP connect() system call */
bool scan_port(const char *ip, int port) {
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(struct sockaddr_in));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip);
    server_addr.sin_port = htons(port);
    int sockfd = create_socket();
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
        close(sockfd);
        return true;
    }
    close(sockfd);
    return false;
}

/* Main function that executes the port scanning process */
int main() {
    char ip[16];
    printf("Enter IP address : ");
    scanf("%s", ip);
    printf("Scanning ports on %s...\n", ip);
    bool is_open;
    for (int port = 1; port <= 65535; port++) {
        is_open = scan_port(ip, port);
        if (is_open) {
            printf("Port %d is open.\n", port);
        }
    }
    printf("Scanning completed.\n");
    return 0;
}