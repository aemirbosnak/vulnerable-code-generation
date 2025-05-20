//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>

#define TRUE   1
#define FALSE  0
#define BACKLOG 10
#define PORT 8080
#define MAX_REQUEST_SIZE 1024
#define ROOT_DIR "./www"
#define DEFAULT_FILE "index.html"

int main(int argc, char *argv[]) {
    int listen_fd, conn_fd;
    struct sockaddr_in server_addr;
    char ip[16];
    int port = PORT;

    if (argc > 1) {
        port = atoi(argv[1]);
    }

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        perror("socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(port);

    if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(listen_fd, BACKLOG) == -1) {
        perror("listen");
        exit(1);
    }

    printf("Server is listening on port %d\n", port);

    while (TRUE) {
        socklen_t addr_size;
        conn_fd = accept(listen_fd, (struct sockaddr *)&server_addr, &addr_size);
        if (conn_fd == -1) {
            perror("accept");
            continue;
        }

        char request[MAX_REQUEST_SIZE];
        memset(request, 0, MAX_REQUEST_SIZE);

        int bytes_received = recv(conn_fd, request, MAX_REQUEST_SIZE, 0);
        if (bytes_received <= 0) {
            close(conn_fd);
            continue;
        }

        char method[10];
        char uri[100];
        char version[10];
        sscanf(request, "%s %s %s", method, uri, version);

        if (strcmp(method, "GET")!= 0) {
            send(conn_fd, "HTTP/1.0 405 Method Not Supported\r\n", 39, 0);
            close(conn_fd);
            continue;
        }

        char file_path[200];
        strcpy(file_path, ROOT_DIR);
        strcat(file_path, uri);

        FILE *fp;
        if ((fp = fopen(file_path, "r")) == NULL) {
            strcpy(file_path, ROOT_DIR);
            strcat(file_path, DEFAULT_FILE);

            if ((fp = fopen(file_path, "r")) == NULL) {
                send(conn_fd, "HTTP/1.0 404 Not Found\r\n", 31, 0);
                close(conn_fd);
                continue;
            }
        }

        fseek(fp, 0, SEEK_END);
        int file_size = ftell(fp);
        fseek(fp, 0, SEEK_SET);

        char response[file_size + 1024];
        fread(response, file_size, 1, fp);
        fclose(fp);

        sprintf(response + file_size, "</body></html>");

        send(conn_fd, response, strlen(response), 0);
        close(conn_fd);
    }

    return 0;
}