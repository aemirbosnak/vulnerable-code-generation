//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 64
#define MAX_PORTS 65535

int ports[MAX_PORTS];
int num_ports = 0;

void *thread_func(void *arg) {
    int thread_id = *(int *) arg;
    int port = ports[thread_id];

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    int result = connect(sock, (struct sockaddr *) &server, sizeof(server));
    if (result == 0) {
        printf("Thread %d: Port %d is open\n", thread_id, port);
        close(sock);
    } else {
        printf("Thread %d: Port %d is closed\n", thread_id, port);
    }

    pthread_exit(0);
}

int main() {
    int num_threads = 0;

    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    if (num_threads > MAX_THREADS) {
        printf("Error: Number of threads cannot exceed %d\n", MAX_THREADS);
        return 1;
    }

    printf("Enter the ports to scan (comma-separated): ");
    char input[1024];
    scanf("%s", input);

    char *port_str = strtok(input, ",");
    while (port_str!= NULL) {
        int port = atoi(port_str);
        if (port >= 1 && port <= MAX_PORTS) {
            ports[num_ports++] = port;
        }
        port_str = strtok(NULL, ",");
    }

    pthread_t threads[num_threads];
    int thread_ids[num_threads];

    for (int i = 0; i < num_threads; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, thread_func, &thread_ids[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}