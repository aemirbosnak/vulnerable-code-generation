//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 512
#define POP3_PORT 110
#define POP3_USER "username"
#define POP3_PASSWORD "password"

int main(int argc, char *argv[]) {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char send_buf[MAX_COMMAND_LENGTH];
    char recv_buf[1024];
    int n;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Error creating socket\n");
        return 1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(POP3_PORT);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        return 1;
    }

    printf("Connected to server\n");

    sprintf(send_buf, "USER %s\r\n", POP3_USER);
    send(sock, send_buf, strlen(send_buf), 0);
    n = recv(sock, recv_buf, sizeof(recv_buf), 0);
    recv_buf[n] = '\0';
    printf("Received: %s", recv_buf);

    sprintf(send_buf, "PASS %s\r\n", POP3_PASSWORD);
    send(sock, send_buf, strlen(send_buf), 0);
    n = recv(sock, recv_buf, sizeof(recv_buf), 0);
    recv_buf[n] = '\0';
    printf("Received: %s", recv_buf);

    close(sock);
    return 0;
}