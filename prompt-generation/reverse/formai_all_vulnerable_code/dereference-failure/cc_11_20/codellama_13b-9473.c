//Code Llama-13B DATASET v1.0 Category: Network Topology Mapper ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_HOSTS 10
#define MAX_CONNS 10

typedef struct {
    char host[MAX_HOSTS][INET_ADDRSTRLEN];
    int port[MAX_CONNS];
} host_info_t;

int main(int argc, char *argv[]) {
    host_info_t *info = NULL;
    int sock, conn, i, j;
    struct sockaddr_in server, client;
    socklen_t client_len = sizeof(client);

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[1]));
    server.sin_addr.s_addr = INADDR_ANY;

    if (bind(sock, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("bind");
        return 1;
    }

    if (listen(sock, MAX_CONNS) < 0) {
        perror("listen");
        return 1;
    }

    while (1) {
        conn = accept(sock, (struct sockaddr *) &client, &client_len);
        if (conn < 0) {
            perror("accept");
            continue;
        }

        info = (host_info_t *) malloc(sizeof(host_info_t));
        if (info == NULL) {
            perror("malloc");
            close(conn);
            continue;
        }

        memset(info, 0, sizeof(host_info_t));

        for (i = 0; i < MAX_HOSTS; i++) {
            for (j = 0; j < MAX_CONNS; j++) {
                if (info->port[j] == 0) {
                    break;
                }
            }
            if (j == MAX_CONNS) {
                break;
            }
            info->port[j] = ntohs(client.sin_port);
            strcpy(info->host[i], inet_ntoa(client.sin_addr));
        }

        if (i == MAX_HOSTS) {
            fprintf(stderr, "Maximum number of hosts reached.\n");
            free(info);
            close(conn);
            continue;
        }

        printf("New connection from %s:%d\n", info->host[i], info->port[i]);

        close(conn);
    }

    close(sock);

    return 0;
}