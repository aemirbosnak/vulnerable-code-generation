//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    if (argc > 1) {
        strcpy(server_addr.sin_zero, "");
        server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    } else {
        server_addr.sin_addr.s_addr = INADDR_ANY;
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    while (1) {
        bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
        if (bytes_received == 0) {
            printf("Connection closed by server\n");
            break;
        } else if (bytes_received == -1) {
            printf("Error receiving data\n");
            exit(1);
        }

        buffer[bytes_received] = '\0';
        printf("Received data: %s", buffer);
    }

    close(sock);
    exit(0);
}