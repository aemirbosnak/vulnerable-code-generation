//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

void error_handling(char* message) {
    perror(message);
    exit(1);
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage:./program <server_ip>\n");
        exit(1);
    }

    char server_ip[16];
    strcpy(server_ip, argv[1]);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
        error_handling("socket failed");

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1)
        error_handling("connect failed");

    char buffer[BUFFER_SIZE];
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0)
            break;

        printf("%s", buffer);
    }

    close(sock);
    return 0;
}