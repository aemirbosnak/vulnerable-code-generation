//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024
#define LINE_SIZE 80
#define PORT 110
#define DELIMITER "\r\n"

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <hostname> <username>\n", argv[0]);
        return -1;
    }

    char *hostname = argv[1];
    char *username = argv[2];

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return -1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        return -1;
    }

    printf("Connected to server\n");

    char username_buf[LINE_SIZE];
    sprintf(username_buf, "USER %s\r\n", username);
    send(sock, username_buf, strlen(username_buf), 0);

    char response[BUFFER_SIZE];
    memset(response, 0, BUFFER_SIZE);
    recv(sock, response, BUFFER_SIZE, 0);
    printf("Server response: %s", response);

    char password_buf[LINE_SIZE];
    sprintf(password_buf, "PASS %s\r\n", username);
    send(sock, password_buf, strlen(password_buf), 0);

    memset(response, 0, BUFFER_SIZE);
    recv(sock, response, BUFFER_SIZE, 0);
    printf("Server response: %s", response);

    char list_buf[LINE_SIZE];
    sprintf(list_buf, "LIST\r\n");
    send(sock, list_buf, strlen(list_buf), 0);

    memset(response, 0, BUFFER_SIZE);
    recv(sock, response, BUFFER_SIZE, 0);
    printf("Server response: %s", response);

    close(sock);
    return 0;
}