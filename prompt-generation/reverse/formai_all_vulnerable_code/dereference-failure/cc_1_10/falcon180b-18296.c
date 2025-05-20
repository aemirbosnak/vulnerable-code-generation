//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char *username = "myusername";
    char *password = "mypassword";
    char *cmd = "USER ";
    char *cmd_user = "myusername";
    char *cmd_pass = "mypassword";

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Socket creation failed: %s\n", strerror(errno));
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(110);
    inet_pton(AF_INET, "localhost", &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Connection failed: %s\n", strerror(errno));
        exit(1);
    }

    printf("Connected to server\n");

    // Send USER command
    strcpy(buffer, cmd);
    strcat(buffer, username);
    strcat(buffer, "\r\n");
    send(sock, buffer, strlen(buffer), 0);

    // Send PASS command
    strcpy(buffer, cmd_user);
    strcat(buffer, "\r\n");
    send(sock, buffer, strlen(buffer), 0);

    strcpy(buffer, cmd_pass);
    strcat(buffer, "\r\n");
    send(sock, buffer, strlen(buffer), 0);

    // Check for server response
    char response[BUFFER_SIZE];
    memset(response, 0, BUFFER_SIZE);
    recv(sock, response, BUFFER_SIZE, 0);

    printf("Server response: %s\n", response);

    close(sock);
    return 0;
}