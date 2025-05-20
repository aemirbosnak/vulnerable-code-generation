//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    int port = atoi(argv[1]);
    int listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock == -1) {
        perror("Error creating socket");
        exit(1);
    }

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    if (bind(listen_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("Error binding socket");
        exit(1);
    }

    listen(listen_sock, 5);

    struct sockaddr_in cli_addr;
    socklen_t cli_len = sizeof(cli_addr);

    while (1) {
        int conn_sock = accept(listen_sock, (struct sockaddr *)&cli_addr, &cli_len);
        if (conn_sock == -1) {
            perror("Error accepting connection");
            exit(1);
        }

        char buf[1024];
        int n = recv(conn_sock, buf, sizeof(buf), 0);
        if (n == -1) {
            perror("Error receiving data");
            exit(1);
        }

        printf("Received: %s\n", buf);

        char msg[1024];
        scanf("%s", msg);

        if (send(conn_sock, msg, strlen(msg), 0) == -1) {
            perror("Error sending data");
            exit(1);
        }

        close(conn_sock);
    }

    close(listen_sock);
    return 0;
}