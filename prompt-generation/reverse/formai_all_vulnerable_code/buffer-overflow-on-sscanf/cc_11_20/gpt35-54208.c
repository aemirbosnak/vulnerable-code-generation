//FormAI DATASET v1.0 Category: Simple Web Server ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {

    int port = 8080;
    int sock, s_client;
    struct sockaddr_in serv_addr, client_addr;
    char buf[BUFSIZE];
    char path[BUFSIZE];
    char http_request[BUFSIZE];
    size_t readlen;
    ssize_t sendlen;

    if ((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1) {
        perror("socket()");
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    if (bind(sock, (const struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("bind()");
        exit(EXIT_FAILURE);
    }

    if (listen(sock, 5) == -1) {
        perror("listen()");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port: %d\n", port);

    while (1) {
        socklen_t addr_length = sizeof(struct sockaddr_in);
        s_client = accept(sock, (struct sockaddr*)&client_addr, &addr_length);
        if (s_client == -1) {
            perror("accept()");
            exit(EXIT_FAILURE);
        }
        printf("Accepted client connection: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        readlen = recv(s_client, buf, BUFSIZE, 0);
        if (readlen == -1) {
            perror("recv()");
            exit(EXIT_FAILURE);
        }
        else if (readlen == 0) {
            printf("Client closed connection\n");
            close(s_client);
            continue;
        }

        buf[readlen] = '\0';
        sscanf(buf, "%s %s", http_request, path);
        printf("HTTP REQUEST: %s\n", http_request);
        printf("PATH: %s\n", path);

        if (strcmp(path, "/") == 0) {
            strcpy(path, "/index.html");
        }

        char full_path[BUFSIZE] = {0};
        sprintf(full_path, "./www%s", path);

        int fd = open(full_path, O_RDONLY);
        if (fd == -1) {
            perror("open()");
            close(s_client);
            continue;
        }

        struct stat st;
        if (fstat(fd, &st) == -1) {
            perror("fstat()");
            close(s_client);
            continue;
        }

        char content_type[BUFSIZE] = {0};
        if (strstr(full_path, ".html")) {
            strcpy(content_type, "text/html");
        }
        else if (strstr(full_path, ".css")) {
            strcpy(content_type, "text/css");
        }
        else if (strstr(full_path, ".js")) {
            strcpy(content_type, "application/javascript");
        }
        else if (strstr(full_path, ".png")) {
            strcpy(content_type, "image/png");
        }
        else if (strstr(full_path, ".jpg")) {
            strcpy(content_type, "image/jpeg");
        }
        else if (strstr(full_path, ".gif")) {
            strcpy(content_type, "image/gif");
        }
        else {
            strcpy(content_type, "application/octet-stream");
        }

        char http_response[BUFSIZE];
        sprintf(http_response, "HTTP/1.1 200 OK\r\nContent-Type: %s\r\nContent-Length: %ld\r\n\r\n", content_type, st.st_size);
        sendlen = send(s_client, http_response, strlen(http_response), 0);
        if (sendlen == -1) {
            perror("send()");
            close(s_client);
            continue;
        }

        while ((readlen = read(fd, buf, BUFSIZE)) > 0) {
            sendlen = send(s_client, buf, readlen, 0);
            if (sendlen == -1) {
                perror("send()");
                break;
            }
        }

        close(fd);
        close(s_client);
    }

    close(sock);
    return 0;
}