//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 1024
#define MAX_PORTS 65535

int ports[MAX_PORTS];
int num_ports;

void *scan_ports(void *arg) {
    int thread_id = *(int *) arg;
    int start_port = thread_id * (MAX_PORTS / MAX_THREADS) + 1;
    int end_port = (thread_id == MAX_THREADS - 1)? MAX_PORTS : start_port + (MAX_PORTS / MAX_THREADS) - 1;

    for (int i = start_port; i <= end_port; i++) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);

        struct sockaddr_in server_addr;
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(i);
        server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

        int result = connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr));

        if (result == 0) {
            close(sock);
            ports[num_ports++] = i;
        } else {
            close(sock);
        }
    }

    return NULL;
}

int main() {
    int num_threads;

    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    pthread_t threads[MAX_THREADS];

    num_ports = 0;

    for (int i = 0; i < num_threads; i++) {
        int start_port = i * (MAX_PORTS / num_threads) + 1;
        int end_port = (i == num_threads - 1)? MAX_PORTS : start_port + (MAX_PORTS / num_threads) - 1;

        printf("Thread %d scanning ports %d to %d\n", i, start_port, end_port);

        pthread_create(&threads[i], NULL, scan_ports, (void *) &i);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Open ports:\n");
    for (int i = 0; i < num_ports; i++) {
        printf("%d\n", ports[i]);
    }

    return 0;
}