//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

void error_handling(const char* message);

int main(int argc, char* argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    struct hostent* server;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <IP address> <port number>\n", argv[0]);
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        error_handling("socket failed");
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        error_handling("no such host");
    }

    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr = *(struct in_addr*)server->h_addr;

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        error_handling("connect failed");
    }

    char buffer[BUFFER_SIZE];
    while (1) {
        bzero(buffer, BUFFER_SIZE);
        int bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }
        printf("Received: %s\n", buffer);
    }

    close(sock);
    return 0;
}

void error_handling(const char* message) {
    perror(message);
    exit(1);
}