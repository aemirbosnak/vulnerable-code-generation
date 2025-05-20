//Falcon-180B DATASET v1.0 Category: Firewall ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>

#define MAX_CONNECTIONS 100
#define BUF_SIZE 1024

struct connection_info {
    int sock;
    struct sockaddr_in client_addr;
};

void *handle_client(void *arg) {
    struct connection_info *conn = (struct connection_info *) arg;
    char buf[BUF_SIZE];
    int n = 0;

    while ((n = recv(conn->sock, buf, BUF_SIZE, 0)) > 0) {
        send(conn->sock, buf, n, 0);
    }

    close(conn->sock);
    free(conn);
    return NULL;
}

int main() {
    int listen_sock, client_sock, opt = 1;
    struct sockaddr_in server_addr, client_addr;
    struct connection_info *conn;
    pthread_t thread_id;

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(8080);

    listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    setsockopt(listen_sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    bind(listen_sock, (struct sockaddr *) &server_addr, sizeof(server_addr));
    listen(listen_sock, MAX_CONNECTIONS);

    printf("Firewall is listening on port 8080\n");

    while (1) {
        socklen_t addr_size = sizeof(client_addr);
        client_sock = accept(listen_sock, (struct sockaddr *) &client_addr, &addr_size);

        if (client_sock == -1) {
            perror("accept");
            continue;
        }

        conn = (struct connection_info *) malloc(sizeof(struct connection_info));
        conn->sock = client_sock;
        memcpy(&conn->client_addr, &client_addr, sizeof(client_addr));

        pthread_create(&thread_id, NULL, handle_client, conn);
    }

    return 0;
}