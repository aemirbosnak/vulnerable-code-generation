//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <netdb.h>

#define BUFSIZE 2048

int main(int argc, char *argv[]) {
    struct sockaddr_in srv_addr, cli_addr;
    socklen_t cli_len = sizeof(cli_addr);
    int srv_port, cli_fd, srv_fd, num_ready, num_bytes;
    char *srv_ip, buf[BUFSIZE];
    fd_set read_fds, write_fds;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s [server ip] [server port]\n", argv[0]);
        exit(1);
    }
    srv_ip = argv[1];
    srv_port = atoi(argv[2]);

    // Create socket for client
    cli_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (cli_fd == -1) {
        perror("socket");
        exit(1);
    }

    // Bind socket to any available interface and port
    memset(&cli_addr, 0, sizeof(cli_addr));
    cli_addr.sin_family = AF_INET;
    cli_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    cli_addr.sin_port = htons(0);
    if (bind(cli_fd, (struct sockaddr *)&cli_addr, cli_len) == -1) {
        perror("bind");
        exit(1);
    }

    // Connect to server
    memset(&srv_addr, 0, sizeof(srv_addr));
    srv_addr.sin_family = AF_INET;
    srv_addr.sin_addr.s_addr = inet_addr(srv_ip);
    srv_addr.sin_port = htons(srv_port);
    if (connect(cli_fd, (struct sockaddr *)&srv_addr, sizeof(srv_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    srv_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (srv_fd == -1) {
        perror("socket");
        exit(1);
    }
    if (bind(srv_fd, (struct sockaddr *)&cli_addr, cli_len) == -1) {
        perror("bind");
        exit(1);
    }
    if (listen(srv_fd, 10) == -1) {
        perror("listen");
        exit(1);
    }

    while (1) {
        FD_ZERO(&read_fds);
        FD_ZERO(&write_fds);
        FD_SET(cli_fd, &read_fds);
        if (strlen(buf) > 0) {
            FD_SET(srv_fd, &write_fds);
        } else {
            FD_SET(srv_fd, &read_fds);
        }
        num_ready = select(FD_SETSIZE, &read_fds, &write_fds, NULL, NULL);
        if (num_ready == -1) {
            perror("select");
            exit(1);
        }
        if (FD_ISSET(cli_fd, &read_fds)) {
            num_bytes = recv(cli_fd, buf, BUFSIZE, 0);
            if (num_bytes == -1) {
                perror("recv");
                exit(1);
            }
            if (num_bytes == 0) {
                printf("Connection closed by remote host.\n");
                break;
            }
            printf("[CLIENT -> PROXY] %s \n\n", buf);
        }
        if (FD_ISSET(srv_fd, &read_fds)) {
            char buffer[BUFSIZE];
            num_bytes = recv(srv_fd, buffer, BUFSIZE, 0);
            if (num_bytes == -1) {
                perror("recv");
                exit(1);
            }
            if (num_bytes == 0) {
                printf("Connection closed by remote host.\n");
                break;
            }
            printf("[SERVER -> PROXY] %s \n\n", buffer);
            send(cli_fd, buffer, num_bytes, 0);
        }
        if (FD_ISSET(srv_fd, &write_fds)) {
            send(srv_fd, buf, strlen(buf), 0);
            printf("[PROXY -> SERVER] %s \n\n", buf);
            memset(buf, 0, BUFSIZE);
        }
    }
    close(cli_fd);
    close(srv_fd);
    return 0;
}