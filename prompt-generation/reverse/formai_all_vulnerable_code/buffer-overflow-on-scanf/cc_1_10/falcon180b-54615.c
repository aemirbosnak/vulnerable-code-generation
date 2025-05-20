//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 100
#define MAX_PORTS 100

int port_list[MAX_PORTS];
int num_ports;

void *scan_ports(void *arg) {
    int thread_id = *(int *) arg;
    int port = port_list[thread_id];

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    int result = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (result == 0) {
        printf("Thread %d: Port %d is open\n", thread_id, port);
        close(sock);
    } else {
        printf("Thread %d: Port %d is closed\n", thread_id, port);
    }
    return NULL;
}

int main() {
    int num_threads;
    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    printf("Enter the ports to scan (comma-separated): ");
    char input[MAX_PORTS];
    scanf("%s", input);

    num_ports = 0;
    char *token = strtok(input, ",");
    while (token!= NULL) {
        port_list[num_ports++] = atoi(token);
        token = strtok(NULL, ",");
    }

    pthread_t threads[MAX_THREADS];
    int thread_ids[MAX_THREADS];

    for (int i = 0; i < num_threads; i++) {
        int port = port_list[i % num_ports];
        pthread_create(&threads[i], NULL, scan_ports, (void *)&port);
        thread_ids[i] = i;
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}