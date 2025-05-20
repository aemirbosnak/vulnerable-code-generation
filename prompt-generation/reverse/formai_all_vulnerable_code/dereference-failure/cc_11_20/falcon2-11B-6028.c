//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_CONNECTIONS 10
#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        exit(1);
    }

    int server_fd, listen_fd, client_fd, new_fd, portno = atoi(argv[1]);
    struct sockaddr_in serv_addr, cli_addr;
    int opt = 1;
    int addrlen = sizeof(serv_addr);
    char buffer[BUFSIZE];
    int n;

    printf("Listening for connections on port %d...\n", portno);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("socket");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(server_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    listen(server_fd, MAX_CONNECTIONS);

    while (1) {
        listen_fd = accept(server_fd, (struct sockaddr *) &cli_addr, (socklen_t *) &addrlen);
        if (listen_fd == -1) {
            perror("accept");
            exit(1);
        }

        printf("New connection from client: %s\n", inet_ntoa(cli_addr.sin_addr));

        client_fd = accept(server_fd, (struct sockaddr *) &cli_addr, (socklen_t *) &addrlen);
        if (client_fd == -1) {
            perror("accept");
            exit(1);
        }

        if (listen_fd!= -1) {
            close(listen_fd);
        }

        int fdmax = listen_fd > client_fd? listen_fd : client_fd;
        int fds[fdmax + 1];
        fds[fdmax] = -1;

        fds[0] = server_fd;
        fds[1] = client_fd;

        while (1) {
            int ready = select(fdmax + 1, fds, NULL, NULL, NULL);
            if (ready == -1) {
                perror("select");
                exit(1);
            }

            if (ready == 0) {
                continue;
            }

            for (int i = 0; i <= fdmax; i++) {
                if (fds[i] == -1) {
                    break;
                }

                if (i == 0) { // server_fd
                    n = read(fds[0], buffer, BUFSIZE);
                    if (n == -1) {
                        perror("read");
                        exit(1);
                    }

                    if (n == 0) {
                        close(fds[0]);
                        fds[0] = -1;
                        continue;
                    }

                    write(fds[1], buffer, n);
                } else if (i == 1) { // client_fd
                    n = read(fds[i], buffer, BUFSIZE);
                    if (n == -1) {
                        perror("read");
                        exit(1);
                    }

                    if (n == 0) {
                        close(fds[i]);
                        fds[i] = -1;
                        continue;
                    }

                    write(fds[0], buffer, n);
                }
            }
        }
    }

    return 0;
}