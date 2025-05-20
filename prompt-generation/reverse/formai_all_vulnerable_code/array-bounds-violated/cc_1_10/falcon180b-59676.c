//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <ctype.h>

#define BUF_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    int addr_len;
    char buffer[BUF_SIZE];
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error opening socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);
    server_addr.sin_port = htons(1234);

    addr_len = sizeof(server_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, addr_len) == -1) {
        printf("Error connecting to server\n");
        close(sockfd);
        exit(1);
    }

    printf("Connected to server\n");

    while (1) {
        memset(buffer, 0, BUF_SIZE);
        fgets(buffer, BUF_SIZE, stdin);
        n = strlen(buffer);
        if (n > 0 && buffer[n - 1] == '\n') {
            buffer[--n] = '\0';
        }
        send(sockfd, buffer, n, 0);

        n = recv(sockfd, buffer, BUF_SIZE, 0);
        if (n <= 0) {
            printf("Disconnected from server\n");
            close(sockfd);
            exit(1);
        }
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}