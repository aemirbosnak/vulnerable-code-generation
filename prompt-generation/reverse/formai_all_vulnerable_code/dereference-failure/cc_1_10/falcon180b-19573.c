//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define BUF_SIZE 1024
#define SERVER "pop3.example.com"
#define USER "user"
#define PASSWORD "password"

int main() {
    int sock;
    struct hostent *host;
    struct sockaddr_in server_addr;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    host = gethostbyname(SERVER);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(110);
    server_addr.sin_addr.s_addr = *((unsigned long *) host->h_addr);

    connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr));

    char *username = USER;
    char *password = PASSWORD;

    char buffer[BUF_SIZE];
    sprintf(buffer, "USER %s\r\n", username);
    send(sock, buffer, strlen(buffer), 0);

    char response[BUF_SIZE];
    recv(sock, response, BUF_SIZE, 0);

    if (strncmp(response, "+OK", 3)!= 0) {
        printf("Authentication failed.\n");
        close(sock);
        return 1;
    }

    sprintf(buffer, "PASS %s\r\n", password);
    send(sock, buffer, strlen(buffer), 0);

    recv(sock, response, BUF_SIZE, 0);

    if (strncmp(response, "+OK", 3)!= 0) {
        printf("Authentication failed.\n");
        close(sock);
        return 1;
    }

    char *command = "STAT\r\n";
    send(sock, command, strlen(command), 0);

    recv(sock, response, BUF_SIZE, 0);

    printf("Server response: %s\n", response);

    close(sock);
    return 0;
}