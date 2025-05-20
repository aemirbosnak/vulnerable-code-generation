//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LINE 1024
#define POP3_PORT 110

int main(int argc, char *argv[]) {
    int sock, ret;
    struct sockaddr_in server_addr;
    char hostname[64];
    char username[64];
    char password[64];
    char response[MAX_LINE];
    char command[MAX_LINE];
    char *ptr;
    int i;

    printf("Enter POP3 server hostname: ");
    scanf("%s", hostname);

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    ret = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    sprintf(command, "USER %s", username);
    send(sock, command, strlen(command), 0);

    ret = recv(sock, response, MAX_LINE, 0);
    if (ret == -1) {
        printf("Error receiving response\n");
        exit(1);
    }

    printf("Server response: %s", response);

    sprintf(command, "PASS %s", password);
    send(sock, command, strlen(command), 0);

    ret = recv(sock, response, MAX_LINE, 0);
    if (ret == -1) {
        printf("Error receiving response\n");
        exit(1);
    }

    printf("Server response: %s", response);

    sprintf(command, "STAT");
    send(sock, command, strlen(command), 0);

    ret = recv(sock, response, MAX_LINE, 0);
    if (ret == -1) {
        printf("Error receiving response\n");
        exit(1);
    }

    printf("Server response: %s", response);

    close(sock);

    return 0;
}