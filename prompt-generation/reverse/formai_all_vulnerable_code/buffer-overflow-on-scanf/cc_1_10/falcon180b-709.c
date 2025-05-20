//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define PORT 21
#define SERVER "localhost"

int main(void) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    char username[64];
    char password[64];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    char login_msg[128];
    sprintf(login_msg, "USER %s\r\n", username);
    send(sock, login_msg, strlen(login_msg), 0);

    char pass_msg[128];
    sprintf(pass_msg, "PASS %s\r\n", password);
    send(sock, pass_msg, strlen(pass_msg), 0);

    char response[BUFFER_SIZE];
    memset(response, 0, BUFFER_SIZE);
    recv(sock, response, BUFFER_SIZE, 0);

    if (strncmp(response, "230", 3)!= 0) {
        printf("Login failed\n");
        exit(1);
    }

    char command[BUFFER_SIZE];
    while (1) {
        printf("Enter command: ");
        scanf("%s", command);

        if (strcmp(command, "quit") == 0) {
            break;
        }

        char msg[128];
        sprintf(msg, "%s\r\n", command);
        send(sock, msg, strlen(msg), 0);

        memset(response, 0, BUFFER_SIZE);
        recv(sock, response, BUFFER_SIZE, 0);

        printf("%s", response);
    }

    close(sock);
    return 0;
}