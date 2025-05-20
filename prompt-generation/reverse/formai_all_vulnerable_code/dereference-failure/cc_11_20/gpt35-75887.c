//FormAI DATASET v1.0 Category: Networking ; Style: complex
//A Complex C Networking Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 9000

int main(int argc, char const *argv[]) {
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = INADDR_ANY,
        .sin_port = htons(PORT)
    };

    int opt = 1;
    if (setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) == -1) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    if (bind(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(sock_fd, 3) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for client connection\n");
    int client_fd = accept(sock_fd, NULL, NULL);
    if (client_fd == -1) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    char *recv_buf = malloc(sizeof(char) * 512);
    char *send_buf = malloc(sizeof(char) * 512);

    while (1) {
        memset(recv_buf, 0, 512);
        memset(send_buf, 0, 512);

        int ret = recv(client_fd, recv_buf, 512, 0);
        if (ret == -1) {
            perror("recv");
            exit(EXIT_FAILURE);
        } else if (ret == 0) {
            printf("Client disconnected\n");
            break;
        }

        printf("Received: %s", recv_buf);
        strcpy(send_buf, "Hello from server!\n");

        ret = send(client_fd, send_buf, strlen(send_buf), 0);
        if (ret == -1) {
            perror("send");
            exit(EXIT_FAILURE);
        }
    }

    if (shutdown(client_fd, SHUT_RDWR) == -1) {
        perror("shutdown");
        exit(EXIT_FAILURE);
    }

    close(client_fd);
    close(sock_fd);

    free(recv_buf);
    free(send_buf);

    return 0;
}