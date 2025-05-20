//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_THREADS 100
#define MAX_PORTS 65535

typedef struct {
    int sock;
    struct sockaddr_in server;
    int port;
} thread_data_t;

void *port_scanner(void *arg) {
    thread_data_t *data = (thread_data_t *) arg;
    int result;
    char buffer[1024];

    result = connect(data->sock, (struct sockaddr *) &data->server, sizeof(data->server));
    if (result!= -1) {
        printf("Port %d is open\n", data->port);
    } else {
        if (errno == ECONNREFUSED) {
            printf("Port %d is closed\n", data->port);
        } else {
            printf("Error on port %d: %s\n", data->port, strerror(errno));
        }
    }

    close(data->sock);
    free(data);
    return NULL;
}

int main(int argc, char **argv) {
    int threads[MAX_THREADS];
    char host[1024];
    int port_range[2];
    int i, j, num_threads;
    struct hostent *he;

    if (argc!= 3) {
        printf("Usage: %s <IP address> <port range>\n", argv[0]);
        return 1;
    }

    strcpy(host, argv[1]);
    sscanf(argv[2], "%d-%d", &port_range[0], &port_range[1]);

    num_threads = port_range[1] - port_range[0] + 1;

    if (num_threads > MAX_THREADS) {
        printf("Error: Too many threads\n");
        return 1;
    }

    for (i = 0; i < num_threads; i++) {
        if (pthread_create(&threads[i], NULL, port_scanner, (void *) &i)!= 0) {
            printf("Error creating thread\n");
            return 1;
        }
    }

    for (i = 0; i < num_threads; i++) {
        if (pthread_join(threads[i], NULL)!= 0) {
            printf("Error joining thread\n");
            return 1;
        }
    }

    return 0;
}