//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <fcntl.h>

#define PORT 21
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock = 0;
    struct sockaddr_in server;
    char buffer[BUFFER_SIZE];
    char *username = "anonymous";
    char *password = "anonymous@example.com";
    char *command = "LIST";

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error: Could not create socket.\n");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr("ftp.example.com");

    if (connect(sock, (struct sockaddr *)&server, sizeof(struct sockaddr)) == -1) {
        printf("Error: Could not connect to server.\n");
        exit(1);
    }

    printf("Connected to server.\n");

    if (login(sock, username, password) == 0) {
        printf("Logged in successfully.\n");
    } else {
        printf("Error: Could not login.\n");
        exit(1);
    }

    if (send(sock, command, strlen(command), 0) == -1) {
        printf("Error: Could not send command.\n");
        exit(1);
    }

    while (1) {
        int bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            printf("Error: Could not receive data.\n");
            exit(1);
        }

        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    close(sock);
    return 0;
}