//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

void print_error(const char* message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void print_usage() {
    printf("Usage:./program <IP address> <port>\n");
}

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        print_usage();
        return 1;
    }

    char* ip_address = argv[1];
    int port = atoi(argv[2]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        print_error("socket");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        print_error("connect");
    }

    char buffer[BUFFER_SIZE];
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}