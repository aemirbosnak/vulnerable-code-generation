//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX 1024
#define PORT 8080
#define SA struct sockaddr

void die(char *s) {
    perror(s);
    exit(1);
}

int main(int argc, char *argv[]) {
    int listen_fd, conn_fd;
    struct sockaddr_in serv_addr, cli_addr;
    int opt = 1;
    int addrlen = sizeof(cli_addr);

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (listen_fd == -1)
        die("socket failed");

    if (setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
        die("setsockopt");

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(PORT);

    if (bind(listen_fd, (SA *)&serv_addr, sizeof(serv_addr)) < 0)
        die("bind failed");

    if (listen(listen_fd, 5) < 0)
        die("listen");

    while (1) {
        conn_fd = accept(listen_fd, (SA *)&cli_addr, &addrlen);

        if (conn_fd < 0)
            die("accept");

        printf("Connection from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        char buffer[MAX];
        int bytes_received = 0;

        while ((bytes_received = recv(conn_fd, buffer, MAX, 0)) > 0) {
            buffer[bytes_received] = '\0';
            printf("Received message: %s\n", buffer);

            if (send(conn_fd, buffer, strlen(buffer), 0) < 0)
                die("send");
        }

        close(conn_fd);
    }

    return 0;
}