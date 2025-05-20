//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAX_LINE 4096

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int create_socket(int port) {
    int sockfd;
    int opt = 1;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        error("socket failed");
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        error("setsockopt");
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        error("bind failed");
    }

    if (listen(sockfd, 5) == -1) {
        error("listen");
    }

    return sockfd;
}

void *handle_client(void *arg) {
    int client_sock = *(int *) arg;
    char buffer[MAX_LINE];

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        int bytes_received = recv(client_sock, buffer, MAX_LINE, 0);
        if (bytes_received <= 0) {
            break;
        }

        send(client_sock, buffer, bytes_received, 0);
    }

    close(client_sock);
    return NULL;
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);

    int server_sock = create_socket(port);

    while (1) {
        int client_sock = accept(server_sock, NULL, NULL);
        pthread_t thread_id;

        if (pthread_create(&thread_id, NULL, handle_client, (void *)&client_sock)!= 0) {
            error("pthread_create");
        }
    }

    return 0;
}