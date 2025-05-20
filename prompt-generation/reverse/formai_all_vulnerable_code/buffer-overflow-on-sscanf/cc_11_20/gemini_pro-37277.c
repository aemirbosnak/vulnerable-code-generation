//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 1024
#define BUFF_SIZE 4096

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <ip> <port1-port2>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *ip = argv[1];
    char *port_range = argv[2];

    int start_port, end_port;
    if (sscanf(port_range, "%d-%d", &start_port, &end_port) != 2) {
        fprintf(stderr, "Invalid port range: %s\n", port_range);
        return EXIT_FAILURE;
    }

    if (start_port < 0 || start_port > 65535 || end_port < 0 || end_port > 65535 || start_port > end_port) {
        fprintf(stderr, "Invalid port range: %s\n", port_range);
        return EXIT_FAILURE;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(start_port);
    if (inet_pton(AF_INET, ip, &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        return EXIT_FAILURE;
    }

    char buff[BUFF_SIZE];
    char *msg = "HEAD / HTTP/1.1\r\nHost: %s\r\n\r\n";
    int len = snprintf(buff, BUFF_SIZE, msg, ip);

    while (start_port <= end_port) {
        int ret = connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
        if (ret == 0) {
            printf("Port %d: open\n", start_port);
            write(sockfd, buff, len);
            read(sockfd, buff, BUFF_SIZE);
        } else {
            printf("Port %d: closed\n", start_port);
        }

        servaddr.sin_port = htons(++start_port);
    }

    close(sockfd);
    return EXIT_SUCCESS;
}