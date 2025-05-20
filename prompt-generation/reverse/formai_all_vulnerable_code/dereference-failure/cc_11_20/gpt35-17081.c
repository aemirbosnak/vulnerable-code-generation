//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: complex
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/time.h>
#include <sys/types.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
        return 1;
    }

    char *port = argv[1];

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in server_addr = {0};
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(port));

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        return 1;
    }

    if (listen(server_fd, 1) == -1) {
        perror("listen");
        return 1;
    }

    printf("Server started on port %s...\n", port);

    while (1) {
        struct sockaddr_in client_addr = {0};
        socklen_t client_addr_len = sizeof(client_addr);
        int client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_fd == -1) {
            perror("accept");
            continue;
        }

        char client_addr_str[INET_ADDRSTRLEN] = {0};
        if (inet_ntop(AF_INET, &client_addr.sin_addr, client_addr_str, sizeof(client_addr_str)) == NULL) {
            perror("inet_ntop");
            close(client_fd);
            continue;
        }

        printf("Client connected from %s:%d\n", client_addr_str, ntohs(client_addr.sin_port));

        fd_set read_fds;
        FD_ZERO(&read_fds);
        FD_SET(client_fd, &read_fds);

        struct timeval timeout;
        timeout.tv_sec = 10;
        timeout.tv_usec = 0;

        int select_result = select(client_fd + 1, &read_fds, NULL, NULL, &timeout);
        if (select_result == -1) {
            perror("select");
            close(client_fd);
            continue;
        } else if (select_result == 0) {
            printf("Client timed out\n");
            close(client_fd);
            continue;
        }

        char buf[BUF_SIZE] = {0};
        ssize_t recv_result = recv(client_fd, buf, sizeof(buf), 0);
        if (recv_result == -1) {
            perror("recv");
            close(client_fd);
            continue;
        } else if (recv_result == 0) {
            printf("Client disconnected\n");
            close(client_fd);
            continue;
        }

        printf("Received message: %s\n", buf);

        ssize_t send_result = send(client_fd, "OK", strlen("OK"), 0);
        if (send_result == -1) {
            perror("send");
            close(client_fd);
            continue;
        } else if (send_result == 0) {
            printf("Client disconnected\n");
            close(client_fd);
            continue;
        }

        printf("Sent response: %s\n", "OK");

        close(client_fd);
    }

    return 0;
}