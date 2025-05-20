//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, port;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    if (argc!= 3) {
        printf("Usage: %s IP_Address Port_Number\n", argv[0]);
        return -1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return -1;
    }

    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);
    server_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        close(sockfd);
        return -1;
    }

    printf("Scanning ports...\n");
    for (port = 1; port <= MAX_PORTS; port++) {
        if (port == atoi(argv[2]))
            continue;

        server_addr.sin_port = htons(port);

        if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
            printf("Port %d is open\n", port);
            close(sockfd);
            return 0;
        } else if (errno!= ECONNREFUSED) {
            printf("Error connecting to port %d\n", port);
            close(sockfd);
            return -1;
        }
    }

    printf("All ports are closed\n");
    close(sockfd);
    return 0;
}