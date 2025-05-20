//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>

#define MAX_CONNECTIONS 10
#define BUFFER_SIZE 1024

typedef struct {
    int socket;
    struct sockaddr_in address;
    char hostname[NI_MAXHOST];
    char service[NI_MAXSERV];
} connection_t;

void *monitor_connection(void *arg) {
    connection_t *conn = (connection_t *) arg;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        bytes_received = recv(conn->socket, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            break;
        }

        printf("Received %d bytes from %s:%s\n", bytes_received, conn->hostname, conn->service);
        fflush(stdout);
    }

    close(conn->socket);
    free(conn);
    pthread_exit(0);
}

int main() {
    int listener = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    int opt = 1;
    int addrlen = sizeof(server_addr);

    setsockopt(listener, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(1234);

    bind(listener, (struct sockaddr *) &server_addr, sizeof(server_addr));
    listen(listener, 3);

    printf("Server listening on port %d\n", ntohs(server_addr.sin_port));

    while (1) {
        connection_t *conn = malloc(sizeof(connection_t));
        socklen_t addrlen = sizeof(conn->address);
        conn->socket = accept(listener, (struct sockaddr *) &conn->address, &addrlen);

        if (conn->socket == -1) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        getnameinfo((struct sockaddr *) &conn->address, sizeof(conn->address),
                    conn->hostname, NI_MAXHOST, conn->service, NI_MAXSERV, 0);

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, monitor_connection, conn);
    }

    close(listener);
    return 0;
}