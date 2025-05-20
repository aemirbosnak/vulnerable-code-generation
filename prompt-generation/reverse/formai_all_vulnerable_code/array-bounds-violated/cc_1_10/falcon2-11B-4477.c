//Falcon2-11B DATASET v1.0 Category: Client Server Application ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    int server_fd, client_fd, c_addrlen, msg_len;
    struct sockaddr_in server_addr, client_addr;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket error");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind error");
        exit(1);
    }

    listen(server_fd, 5);

    while (1) {
        client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &c_addrlen);
        if (client_fd < 0) {
            perror("accept error");
            continue;
        }

        printf("Connection from: %s\n", inet_ntoa(client_addr.sin_addr));

        char buffer[BUFSIZE];
        bzero(buffer, BUFSIZE);
        msg_len = recv(client_fd, buffer, BUFSIZE, 0);
        if (msg_len <= 0) {
            perror("recv error");
            exit(1);
        }

        buffer[msg_len] = '\0';
        printf("Received message: %s\n", buffer);

        msg_len = send(client_fd, buffer, strlen(buffer), 0);
        if (msg_len <= 0) {
            perror("send error");
            exit(1);
        }

        close(client_fd);
    }

    close(server_fd);
    return 0;
}