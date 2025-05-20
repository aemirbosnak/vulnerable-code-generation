//FormAI DATASET v1.0 Category: Networking ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<fcntl.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<netdb.h>

int main(int argc, char *argv[]){
    int sock, sock_fd, client_len;
    struct sockaddr_in server_addr, client_addr;
    fd_set fd_list;
    int max_fd;
    int ret;

    if (argc != 2) {
        printf("Usage: %s missing port!\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    int port = atoi(argv[1]);

    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port   = htons(port);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    ret = bind(sock, (struct sockaddr *) &server_addr, sizeof(server_addr));
    if (ret < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    ret = listen(sock, 5);
    if (ret == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    max_fd = sock + 1;

    while (1) {
        FD_ZERO(&fd_list);
        FD_SET(sock, &fd_list);

        if (sock_fd >= 0) {
            FD_SET(sock_fd, &fd_list);
        }

        ret = select(max_fd, &fd_list, NULL, NULL, NULL);

        if (FD_ISSET(sock, &fd_list)) {
            /*
             * Accept new connection.
             */

            sock_fd = accept(sock, (struct sockaddr *)&client_addr, &client_len);
            if (sock_fd < 0) {
                perror("accept");
                exit(EXIT_FAILURE);
            }

            fprintf(stderr,
                "Accepted a new connection. "
                "Client IP / Port = %s / %d\n",
                inet_ntoa(client_addr.sin_addr),
                ntohs(client_addr.sin_port));

            fflush(stderr);
        }

        if (FD_ISSET(sock_fd, &fd_list)) {
            char buf[1024];
            ssize_t n;

            n = recv(sock_fd, buf, sizeof(buf), 0);
            if (n <= 0) {
                fprintf(stderr, "Connection closed.\n");
                close(sock_fd);
                sock_fd = -1;
                continue;
            }

            fprintf(stderr, "Server received %zd bytes.\n", n);
            fflush(stderr);

            /*
             * Echo the data back to the client.
             */

            n = send(sock_fd, buf, n, 0);
            if (n < 0) {
                perror("send");
                exit(EXIT_FAILURE);
            }
        }
    }

    return 0;
}