//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <netinet/in.h>
 
#define INVALID_SOCKET -1
 
#define BUFFER_SIZE 8192
 
int main(int argc, char** argv) {
    struct sockaddr_in addr;
    int listen_sock;
    int fd;
    int conn_sock;
    int ret;
    size_t n;
    char buffer[BUFFER_SIZE];
    int yes = 1;
 
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <listen_port> <connect_ip:connect_port>. Eg. 8080 127.0.0.1:88\n", argv[0]);
        exit(EXIT_FAILURE);
    }
 
    /* Set up the listening socket */
    listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock == INVALID_SOCKET) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
 
    setsockopt(listen_sock, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes));
 
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(atoi(argv[1]));
    if (bind(listen_sock, (struct sockaddr*) &addr, sizeof(addr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }
 
    if (listen(listen_sock, 3) == -1) { /* 3 is the maximum backlog */
        perror("listen");
        exit(EXIT_FAILURE);
    }
 
    printf("Proxy server listening on port %s. Forwarding to %s.\n", argv[1], argv[2]);
 
    /* Main server loop */
    while (1) {
        conn_sock = accept(listen_sock, NULL, NULL);
        if (conn_sock == INVALID_SOCKET) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
 
        /* Fork a new process to deal with the connection */
        if (!fork()) {
            /* Get the requested host and port */
            char* port_index = strchr(argv[2], ':');
            if (!port_index) {
                fprintf(stderr, "Invalid connect string: %s\n", argv[2]);
                exit(EXIT_FAILURE);
            }
            *port_index = '\0';
            char* connect_host = argv[2];
            char* connect_port = port_index + 1;
 
            /* Open the connection to the remote host */
            fd = socket(AF_INET, SOCK_STREAM, 0);
            if (fd == INVALID_SOCKET) {
                perror("socket");
                exit(EXIT_FAILURE);
            }
 
            memset(&addr, 0, sizeof(addr));
            addr.sin_family = AF_INET;
            addr.sin_port = htons(atoi(connect_port));
            if (inet_pton(AF_INET, connect_host, &(addr.sin_addr)) != 1) {
                if (errno == EAFNOSUPPORT) {
                    fprintf(stderr, "Invalid address family.\n");
                } else {
                    perror("inet_pton");
                }
                exit(EXIT_FAILURE);
            }
 
            if (connect(fd, (struct sockaddr*) &addr, sizeof(addr)) == -1) {
                perror("connect");
                exit(EXIT_FAILURE);
            }
 
            /* Forward data between the client and the remote host */
            while ((n = recv(conn_sock, buffer, sizeof(buffer), 0)) > 0) {
                send(fd, buffer, n, 0);
            }
 
            /* Close the connection */
            close(fd);
            close(conn_sock);
            exit(EXIT_SUCCESS);
        }
 
        /* Parent process - close the connected socket and continue the loop */
        close(conn_sock);
    }
 
    return 0;
}