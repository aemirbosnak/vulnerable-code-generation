//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[1024];
    int n;
    int port = 8080;
    char *ip = "127.0.0.1";

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        printf("Enter message: ");
        fgets(buffer, sizeof(buffer), stdin);
        n = strlen(buffer);
        if (send(sockfd, buffer, n, 0) == -1) {
            perror("send failed");
            exit(EXIT_FAILURE);
        }
        memset(buffer, 0, sizeof(buffer));
        n = recv(sockfd, buffer, sizeof(buffer), 0);
        if (n == 0) {
            printf("Connection closed by server\n");
            break;
        }
        buffer[n] = '\0';
        printf("Received message: %s", buffer);
    }

    close(sockfd);
    return 0;
}