//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUF_SIZE 1024

void error_exit(char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        error_exit("Usage: ./ftpclient <server-ip>");
    }

    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        error_exit("Unable to create socket");
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(21);

    if (connect(sock_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        error_exit("Unable to connect to server");
    }

    char buf[MAX_BUF_SIZE] = {0};
    int recv_len = recv(sock_fd, buf, MAX_BUF_SIZE - 1, 0);
    buf[recv_len] = '\0';
    printf("%s", buf);

    while (1) {
        printf("Enter command: ");
        scanf("%s", buf);

        strcat(buf, "\r\n");
        send(sock_fd, buf, strlen(buf), 0);

        if (strcasecmp(buf, "quit\r\n") == 0) {
            break;
        }

        recv_len = recv(sock_fd, buf, MAX_BUF_SIZE - 1, 0);
        buf[recv_len] = '\0';
        printf("%s", buf);
    }

    close(sock_fd);
    return 0;
}