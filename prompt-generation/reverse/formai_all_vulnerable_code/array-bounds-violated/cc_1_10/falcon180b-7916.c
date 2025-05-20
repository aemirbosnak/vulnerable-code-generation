//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>

#define BUFFER_SIZE 1024
#define POP3_PORT 110

void print_buffer(char *buffer, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%c", buffer[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char *server_ip = "127.0.0.1";
    char *username = "your_username";
    char *password = "your_password";
    char buffer[BUFFER_SIZE];
    int bytes_received;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    if (send(sock, username, strlen(username), 0) == -1) {
        printf("Error sending username\n");
        exit(1);
    }

    if (send(sock, password, strlen(password), 0) == -1) {
        printf("Error sending password\n");
        exit(1);
    }

    while (1) {
        bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            printf("Error receiving data\n");
            break;
        }

        buffer[bytes_received] = '\0';
        print_buffer(buffer, bytes_received);
    }

    close(sock);

    return 0;
}