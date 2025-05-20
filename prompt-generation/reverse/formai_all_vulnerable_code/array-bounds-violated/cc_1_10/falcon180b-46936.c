//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define SERVER "localhost"
#define PORT 110
#define USER "username"
#define PASS "password"

#define MAX_LINE 1024
#define MAX_COMMAND 64

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[MAX_LINE];
    char command[MAX_COMMAND];
    int n;
    int state = 0;

    // create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    // connect to server
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // send username and password
    sprintf(command, "USER %s", USER);
    send(sock, command, strlen(command), 0);

    sprintf(command, "PASS %s", PASS);
    send(sock, command, strlen(command), 0);

    // receive server response
    n = recv(sock, buffer, MAX_LINE, 0);
    if (n <= 0) {
        printf("Error receiving server response\n");
        exit(1);
    }

    buffer[n] = '\0';
    printf("Server response: %s\n", buffer);

    // enter POP3 state machine
    while (1) {
        printf("Enter command: ");
        fgets(command, MAX_COMMAND, stdin);

        if (strcmp(command, "quit") == 0) {
            sprintf(command, "QUIT");
            send(sock, command, strlen(command), 0);
            break;
        } else if (strcmp(command, "stat") == 0) {
            sprintf(command, "STAT");
            send(sock, command, strlen(command), 0);
        } else if (strcmp(command, "list") == 0) {
            sprintf(command, "LIST");
            send(sock, command, strlen(command), 0);
        } else if (strcmp(command, "retr") == 0) {
            char *msg_num_str;
            int msg_num;

            msg_num_str = strtok(command, " ");
            msg_num = atoi(msg_num_str);

            sprintf(command, "RETR %d", msg_num);
            send(sock, command, strlen(command), 0);
        } else if (strcmp(command, "dele") == 0) {
            char *msg_num_str;
            int msg_num;

            msg_num_str = strtok(command, " ");
            msg_num = atoi(msg_num_str);

            sprintf(command, "DELE %d", msg_num);
            send(sock, command, strlen(command), 0);
        } else {
            printf("Invalid command\n");
        }
    }

    // close socket
    close(sock);

    return 0;
}