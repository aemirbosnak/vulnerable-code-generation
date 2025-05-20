//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define TRUE 1
#define FALSE 0
#define PORT_RANGE_MAX 65535
#define PORT_RANGE_MIN 1
#define DEFAULT_THREADS 10
#define DEFAULT_TIMEOUT 5000

typedef struct {
    int port;
    char *ip;
    int is_open;
} port_t;

void *scan_port(void *arg) {
    int sock = *(int *) arg;
    port_t *port = (port_t *) sock;

    if (connect(sock, (struct sockaddr *) &(port->ip), sizeof(struct sockaddr)) == 0) {
        port->is_open = TRUE;
        close(sock);
    } else {
        port->is_open = FALSE;
        close(sock);
    }

    pthread_exit(0);
}

int main(int argc, char *argv[]) {
    int threads = DEFAULT_THREADS;
    int timeout = DEFAULT_TIMEOUT;
    char *ip = "127.0.0.1";
    int start_port = PORT_RANGE_MIN;
    int end_port = PORT_RANGE_MAX;

    if (argc > 1) {
        ip = argv[1];
    }

    if (argc > 2) {
        start_port = atoi(argv[2]);
    }

    if (argc > 3) {
        end_port = atoi(argv[3]);
    }

    if (argc > 4) {
        threads = atoi(argv[4]);
    }

    if (argc > 5) {
        timeout = atoi(argv[5]);
    }

    pthread_t threads_id[threads];
    port_t ports[threads];

    for (int i = 0; i < threads; i++) {
        ports[i].port = start_port + i * (end_port - start_port) / threads;
        ports[i].ip = ip;
        ports[i].is_open = FALSE;

        int ret = pthread_create(&threads_id[i], NULL, scan_port, &ports[i]);

        if (ret!= 0) {
            fprintf(stderr, "Error: Unable to create thread, %d\n", ret);
            return 1;
        }
    }

    for (int i = 0; i < threads; i++) {
        pthread_join(threads_id[i], NULL);
    }

    return 0;
}