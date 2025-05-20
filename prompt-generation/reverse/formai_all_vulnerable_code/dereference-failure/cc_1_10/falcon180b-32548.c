//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>

#define BUF_SIZE 1024
#define SERVER_PORT 8080
#define SERVER_ADDR "127.0.0.1"

void error_handling(char *message) {
    perror(message);
    exit(1);
}

int main(int argc, char *argv[]) {
    int client_sock;
    struct sockaddr_in server_addr;
    char buffer[BUF_SIZE];

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <IP address> <port number>\n", argv[0]);
        exit(1);
    }

    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        error_handling("Invalid IP address");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));

    if ((client_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        error_handling("socket failed");
    }

    if (connect(client_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        error_handling("connect failed");
    }

    printf("Connected to server\n");

    while (fgets(buffer, BUF_SIZE, stdin)!= NULL) {
        send(client_sock, buffer, strlen(buffer), 0);
    }

    close(client_sock);

    return 0;
}