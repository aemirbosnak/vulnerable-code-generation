//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    char *hostname;
    struct hostent *host;
    struct sockaddr_in server_addr;
    int opt = 1;
    char buffer[BUFFER_SIZE];

    if (argc!= 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    hostname = argv[1];
    host = gethostbyname(hostname);

    if (host == NULL) {
        printf("Error: Host not found.\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: Socket creation failed.\n");
        exit(1);
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Connection failed.\n");
        exit(1);
    }

    printf("Connection established.\n");

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        ssize_t read = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (read <= 0) {
            printf("Error: Reading from socket failed.\n");
            exit(1);
        }

        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}