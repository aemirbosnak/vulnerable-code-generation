//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void error_handling(char* message);

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <server_ip> <port>\n", argv[0]);
        return 1;
    }

    char* server_ip = argv[1];
    int port = atoi(argv[2]);

    int client_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (client_socket == -1) {
        error_handling("socket failed");
    }

    struct sockaddr_in server_addr;

    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(server_ip);

    if (connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        error_handling("connect failed");
    }

    char buffer[BUFFER_SIZE];

    while (1) {
        bzero(buffer, BUFFER_SIZE);
        fgets(buffer, BUFFER_SIZE, stdin);

        send(client_socket, buffer, strlen(buffer), 0);

        bzero(buffer, BUFFER_SIZE);
        recv(client_socket, buffer, BUFFER_SIZE, 0);

        printf("%s", buffer);
    }

    close(client_socket);

    return 0;
}

void error_handling(char* message) {
    perror(message);
    exit(1);
}