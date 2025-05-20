//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_LINE_LEN 1024
#define SMTP_PORT 25

void print_error(const char* msg) {
    perror(msg);
    exit(1);
}

void print_usage() {
    printf("Usage:./smtp_client [host] [port]\n");
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        print_usage();
    }

    char* host = argv[1];
    int port = atoi(argv[2]);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        print_error("socket");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, host, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        print_error("connect");
    }

    char buffer[MAX_LINE_LEN];
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        fgets(buffer, sizeof(buffer), stdin);

        send(sock, buffer, strlen(buffer), 0);

        int bytes_received = 0;
        char response[MAX_LINE_LEN];
        while (bytes_received < MAX_LINE_LEN - 1) {
            int ret = recv(sock, response + bytes_received, MAX_LINE_LEN - bytes_received - 1, 0);
            if (ret <= 0) {
                print_error("recv");
                break;
            }
            bytes_received += ret;
            response[bytes_received] = '\0';
        }

        printf("%s", response);

        if (strcmp(response, "220") == 0) {
            break;
        }
    }

    close(sock);
    return 0;
}