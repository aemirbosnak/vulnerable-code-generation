//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 5000
#define BUF_SIZE 1024
#define MAX_CONNECTIONS 10

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Failed to open file\n");
        exit(1);
    }

    int socket_fd, conn_fd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        perror("socket creation failed");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(socket_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    if (listen(socket_fd, MAX_CONNECTIONS) < 0) {
        perror("listen failed");
        exit(1);
    }

    while (1) {
        conn_fd = accept(socket_fd, (struct sockaddr *) &cli_addr, (socklen_t *) &portno);
        if (conn_fd < 0) {
            perror("accept failed");
            exit(1);
        }

        char buffer[BUF_SIZE];
        bzero(buffer, BUF_SIZE);

        int num_lines = 0;
        while (num_lines++ < BUF_SIZE) {
            int n = read(conn_fd, buffer + num_lines, BUF_SIZE - num_lines);
            if (n < 0) {
                perror("read failed");
                exit(1);
            }

            if (n == 0) {
                break;
            }

            char *line = strtok(buffer, "\n");
            while (line!= NULL) {
                printf("%s\n", line);
                line = strtok(NULL, "\n");
            }
        }

        if (num_lines == 0) {
            printf("No input found\n");
        }

        close(conn_fd);
    }

    close(socket_fd);
    return 0;
}