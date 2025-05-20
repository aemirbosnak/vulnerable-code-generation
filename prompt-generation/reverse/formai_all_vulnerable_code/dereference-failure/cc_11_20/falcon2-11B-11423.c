//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int listen_fd, conn_fd, addrlen;
    struct sockaddr_in server_addr, client_addr;
    int bufsize = 1024;
    char buffer[bufsize];

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <proxy_host> <proxy_port>\n", argv[0]);
        exit(1);
    }

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd < 0) {
        fprintf(stderr, "Error opening socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Error binding socket\n");
        exit(1);
    }

    if (listen(listen_fd, 3) < 0) {
        fprintf(stderr, "Error listening on socket\n");
        exit(1);
    }

    while (1) {
        conn_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &addrlen);
        if (conn_fd < 0) {
            fprintf(stderr, "Error accepting connection\n");
            exit(1);
        }

        printf("Connected to %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (read(conn_fd, buffer, bufsize) > 0) {
            printf("Received %s\n", buffer);

            struct hostent *host = gethostbyname(argv[2]);
            if (host == NULL) {
                fprintf(stderr, "Error resolving host\n");
                exit(1);
            }

            struct sockaddr_in server_addr;
            memcpy(&server_addr, host->h_addr_list[0], host->h_length);
            server_addr.sin_family = AF_INET;
            server_addr.sin_port = htons(atoi(argv[1]));
            server_addr.sin_addr.s_addr = inet_addr(argv[2]);

            if (connect(conn_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
                fprintf(stderr, "Error connecting to server\n");
                exit(1);
            }

            while (read(conn_fd, buffer, bufsize) > 0) {
                printf("Sent %s\n", buffer);
                write(conn_fd, buffer, strlen(buffer));
            }

            printf("Connection closed\n");
            close(conn_fd);
        }

        printf("Connection closed\n");
        close(conn_fd);
    }

    return 0;
}