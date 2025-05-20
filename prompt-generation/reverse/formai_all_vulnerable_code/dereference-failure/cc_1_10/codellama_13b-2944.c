//Code Llama-13B DATASET v1.0 Category: Building a FTP Client ; Style: sophisticated
// ftp_client.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char buffer[MAX_BUFFER_SIZE];

    if (argc < 2) {
        printf("Usage: %s <ip_address> <port>\n", argv[0]);
        return 1;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Error creating socket\n");
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    server.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Error connecting to server\n");
        return 1;
    }

    printf("Connected to server\n");

    while (1) {
        printf("> ");
        fgets(buffer, MAX_BUFFER_SIZE, stdin);

        if (strcmp(buffer, "exit\n") == 0) {
            close(sock);
            break;
        }

        if (send(sock, buffer, strlen(buffer), 0) < 0) {
            printf("Error sending data to server\n");
            close(sock);
            break;
        }

        if (recv(sock, buffer, MAX_BUFFER_SIZE, 0) < 0) {
            printf("Error receiving data from server\n");
            close(sock);
            break;
        }

        printf("Received: %s", buffer);
    }

    return 0;
}