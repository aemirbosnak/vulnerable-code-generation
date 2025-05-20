//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define TRUE 1
#define FALSE 0
#define PORT_NUMBER 65535
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT_NUMBER);
    server.sin_addr.s_addr = INADDR_ANY;

    if (bind(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    int bytes_received;

    for (int i = 0; i < PORT_NUMBER; i++) {
        sprintf(buffer, "Port %d is ", i);
        send(sock, buffer, strlen(buffer), 0);

        bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            continue;
        }

        buffer[bytes_received] = '\0';
        if (strcmp(buffer, "open") == 0) {
            printf("Port %d is open.\n", i);
        } else {
            printf("Port %d is closed.\n", i);
        }
    }

    close(sock);
    return 0;
}