//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

#define MAX_THREADS 100
#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int ports[MAX_PORTS];
int num_ports;

void *scan_thread(void *arg) {
    int thread_id = *(int *) arg;
    int start_port = thread_id * (MAX_PORTS / MAX_THREADS) + 1;
    int end_port = (thread_id == MAX_THREADS - 1)? MAX_PORTS : start_port + (MAX_PORTS / MAX_THREADS) - 1;

    for (int port = start_port; port <= end_port; port++) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);

        if (sock == -1) {
            perror("socket");
            continue;
        }

        struct sockaddr_in addr;
        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        addr.sin_addr.s_addr = INADDR_ANY;

        if (connect(sock, (struct sockaddr *) &addr, sizeof(addr)) == 0) {
            printf("Port %d is open\n", port);
            close(sock);
        } else if (errno == ECONNREFUSED) {
            printf("Port %d is closed\n", port);
        } else {
            printf("Error on port %d: %s\n", port, strerror(errno));
        }
    }

    return NULL;
}

int main() {
    printf("Enter the number of ports to scan (1-%d): ", MAX_PORTS);
    scanf("%d", &num_ports);

    for (int i = 1; i <= num_ports; i++) {
        ports[i - 1] = i;
    }

    pthread_t threads[MAX_THREADS];
    int thread_ids[MAX_THREADS];

    for (int i = 0; i < MAX_THREADS; i++) {
        thread_ids[i] = i * (MAX_PORTS / MAX_THREADS) + 1;
        pthread_create(&threads[i], NULL, scan_thread, &thread_ids[i]);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}