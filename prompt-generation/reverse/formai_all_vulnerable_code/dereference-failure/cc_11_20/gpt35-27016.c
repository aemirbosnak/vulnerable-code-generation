//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        printf("Usage: ./proxy <portno>\n");
        return -1;
    }

    int portno = atoi(argv[1]);

    struct sockaddr_in server_addr, client_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    memset(&client_addr, 0, sizeof(client_addr));

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket error");
        return -1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(portno);

    if (bind(server_fd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        perror("bind error");
        return -1;
    }

    if (listen(server_fd, 10) < 0) {
        perror("listen error");
        return -1;
    }

    printf("Proxy is listening on port %d...\n", portno);

    while (1) {
        int client_fd = accept(server_fd, (struct sockaddr*) &client_addr, sizeof(client_addr));
        if (client_fd < 0) {
            perror("accept error");
            continue;
        }

        char buffer[1024] = {0};
        int valread = read(client_fd, buffer, 1024);
        if (valread <= 0) {
            perror("read error");
            continue;
        }

        char* host = strtok(buffer + 4, " ");
        char* port_str = strchr(host, ':');
        if (port_str == NULL) {
            port_str = "80";
        } else {
            *port_str = '\0';
            port_str++;
        }
        int port = atoi(port_str);

        struct sockaddr_in server_addr2;
        int server_fd2 = socket(AF_INET, SOCK_STREAM, 0);
        if (server_fd2 < 0) {
            perror("socket error");
            continue;
        }

        server_addr2.sin_family = AF_INET;
        server_addr2.sin_addr.s_addr = inet_addr(host);
        server_addr2.sin_port = htons(port);

        if (connect(server_fd2, (struct sockaddr*) &server_addr2, sizeof(server_addr2)) < 0) {
            perror("connect error");
            continue;
        }

        if (write(server_fd2, buffer, strlen(buffer)) < 0) {
            perror("write error");
            continue;
        }

        memset(buffer, 0, sizeof(buffer));

        while (1) {
            valread = read(server_fd2, buffer, 1024);
            if (valread <= 0) {
                break;
            }

            if (write(client_fd, buffer, valread) < 0) {
                perror("write error");
                break;
            }

            memset(buffer, 0, sizeof(buffer));
        }

        close(server_fd2);
        close(client_fd);
    }

    close(server_fd);

    return 0;
}