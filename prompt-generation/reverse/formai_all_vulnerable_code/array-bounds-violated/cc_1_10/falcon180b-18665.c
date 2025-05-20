//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define USERNAME "your_username"
#define PASSWORD "your_password"
#define SERVER "pop3.example.com"
#define PORT 110

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char username[100] = USERNAME;
    char password[100] = PASSWORD;
    char response[BUFFER_SIZE];
    int bytes_received;
    int i;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: Failed to create socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Failed to connect to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    send(sock, "USER ", strlen("USER "), 0);
    bytes_received = recv(sock, response, BUFFER_SIZE, 0);
    response[bytes_received] = '\0';
    printf("Server response: %s\n", response);

    send(sock, "PASS ", strlen("PASS "), 0);
    bytes_received = recv(sock, response, BUFFER_SIZE, 0);
    response[bytes_received] = '\0';
    printf("Server response: %s\n", response);

    if (response[0] == '+') {
        printf("Logged in successfully\n");

        send(sock, "STAT ", strlen("STAT "), 0);
        bytes_received = recv(sock, response, BUFFER_SIZE, 0);
        response[bytes_received] = '\0';
        printf("Server response: %s\n", response);

        send(sock, "LIST ", strlen("LIST "), 0);
        bytes_received = recv(sock, response, BUFFER_SIZE, 0);
        response[bytes_received] = '\0';
        printf("Server response: %s\n", response);

        for (i = 0; i < bytes_received; i++) {
            if (response[i] == '\n') {
                response[i] = '\0';
                printf("Message #%d: %s\n", ++i, &response[i]);
            }
        }
    } else {
        printf("Error: Failed to login\n");
    }

    close(sock);
    return 0;
}