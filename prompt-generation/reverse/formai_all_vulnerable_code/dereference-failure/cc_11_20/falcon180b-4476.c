//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <fcntl.h>

#define MAX_LINE_LEN 1024
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUF_SIZE];
    char *cmd;
    int n;
    char *user = "user";
    char *pass = "pass";
    char *host = "localhost";
    int port = 110;
    char *cmd_list[] = {"USER", "PASS", "STAT", "LIST", "RETR", "DELE", "QUIT", "\0"};
    int i = 0;

    if (argc < 4) {
        printf("Usage: %s <host> <port> <user> <pass>\n", argv[0]);
        return 1;
    }

    host = argv[1];
    port = atoi(argv[2]);
    user = argv[3];
    pass = argv[4];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Socket creation failed\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, host, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Connection failed\n");
        exit(1);
    }

    printf("Connected to POP3 server\n");

    while (i < 7) {
        cmd = cmd_list[i];
        printf("Sending %s command\n", cmd);
        if (send(sock, cmd, strlen(cmd), 0) == -1) {
            printf("Send failed\n");
            exit(1);
        }
        memset(buffer, 0, BUF_SIZE);
        n = recv(sock, buffer, BUF_SIZE, 0);
        if (n == -1) {
            printf("Receive failed\n");
            exit(1);
        }

        printf("Received response: %s\n", buffer);
        if (i == 0) {
            if (strstr(buffer, "+OK") == NULL) {
                printf("Login failed\n");
                exit(1);
            }
        } else if (i == 1) {
            if (strstr(buffer, "+OK") == NULL) {
                printf("Password incorrect\n");
                exit(1);
            }
        } else if (i == 4) {
            char *ptr = strstr(buffer, " ");
            if (ptr == NULL) {
                printf("Retrieve message failed\n");
                exit(1);
            }
            ptr++;
            int len = strlen(ptr);
            char *msg = malloc(len + 1);
            strcpy(msg, ptr);
            printf("Received message: %s\n", msg);
            free(msg);
        } else if (i == 5) {
            if (strstr(buffer, "+OK") == NULL) {
                printf("Delete message failed\n");
                exit(1);
            }
        }
        i++;
    }

    close(sock);
    return 0;
}