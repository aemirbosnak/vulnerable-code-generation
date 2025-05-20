//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 100
#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int ports[MAX_PORTS];
int num_ports = 0;

void *scan_ports(void *arg) {
    int thread_id = *(int *) arg;
    int start_port = thread_id * (MAX_PORTS / MAX_THREADS) + 1;
    int end_port = (thread_id + 1) * (MAX_PORTS / MAX_THREADS);

    for (int i = start_port; i <= end_port; i++) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);

        struct sockaddr_in server;
        memset(&server, 0, sizeof(server));
        server.sin_family = AF_INET;
        server.sin_port = htons(i);
        server.sin_addr.s_addr = inet_addr("127.0.0.1");

        int result = connect(sock, (struct sockaddr *) &server, sizeof(server));

        if (result!= -1) {
            close(sock);
            printf("Thread %d: Port %d is open\n", thread_id, i);
        } else {
            printf("Thread %d: Port %d is closed\n", thread_id, i);
        }
    }

    return NULL;
}

int main() {
    printf("Enter the number of ports to scan: ");
    scanf("%d", &num_ports);

    for (int i = 1; i <= num_ports; i++) {
        ports[i - 1] = i;
    }

    pthread_t threads[MAX_THREADS];
    int thread_ids[MAX_THREADS];

    for (int i = 0; i < MAX_THREADS; i++) {
        thread_ids[i] = i * (MAX_PORTS / MAX_THREADS) + 1;
        pthread_create(&threads[i], NULL, scan_ports, (void *) &thread_ids[i]);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}