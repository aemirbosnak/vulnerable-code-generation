//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <ctype.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    char buffer[BUF_SIZE];
    struct sockaddr_in server_addr;
    struct hostent *host_info;
    char *ip_address;
    int port;

    if (argc!= 3) {
        printf("Usage:./program <ip address> <port>\n");
        return 1;
    }

    ip_address = argv[1];
    port = atoi(argv[2]);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    host_info = gethostbyname(ip_address);

    if (host_info == NULL) {
        printf("Error resolving hostname\n");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr.s_addr, host_info->h_addr, host_info->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    printf("Connected to %s:%d\n", ip_address, port);

    while (1) {
        memset(buffer, 0, BUF_SIZE);
        n = recv(sockfd, buffer, BUF_SIZE, 0);

        if (n <= 0) {
            printf("Error receiving data\n");
            break;
        }

        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}