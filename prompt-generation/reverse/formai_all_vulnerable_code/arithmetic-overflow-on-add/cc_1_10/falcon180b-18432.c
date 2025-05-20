//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_THREADS 100
#define MAX_PORTS 65535

int ports[MAX_PORTS];
int num_ports = 0;
int num_threads = 0;

void *scan_port(void *arg) {
    int port = *(int *) arg;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (connect(sock, (struct sockaddr *) &addr, sizeof(addr)) == 0) {
        printf("Port %d is open\n", port);
        close(sock);
    } else {
        printf("Port %d is closed\n", port);
    }
    return NULL;
}

void add_port(int port) {
    ports[num_ports++] = port;
}

int main() {
    int i, j, port;

    printf("Enter the number of ports to scan: ");
    scanf("%d", &num_ports);

    for (i = 1; i <= num_ports; i++) {
        printf("Enter port %d: ", i);
        scanf("%d", &port);
        add_port(port);
    }

    pthread_t threads[MAX_THREADS];
    int thread_id[MAX_THREADS];

    for (i = 0; i < num_ports; i++) {
        thread_id[i] = i;
        pthread_create(&threads[i], NULL, scan_port, &ports[i]);
    }

    for (i = 0; i < num_ports; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}