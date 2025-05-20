//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_THREADS 50
#define BUFFER_SIZE 1024

typedef struct {
    int socket;
    int port;
    char *ip;
} PortScannerThreadData;

void *port_scanner_thread(void *data) {
    PortScannerThreadData *thread_data = (PortScannerThreadData *) data;
    char buffer[BUFFER_SIZE];

    if (connect(thread_data->socket, (struct sockaddr *) &(thread_data->ip), sizeof(struct sockaddr_in))) {
        printf("Port %d is closed\n", thread_data->port);
    } else {
        printf("Port %d is open\n", thread_data->port);
    }

    close(thread_data->socket);
    free(thread_data->ip);
    free(thread_data);
}

int main() {
    char *ip_address;
    int port_range_start, port_range_end;
    int num_threads;

    printf("Enter IP address: ");
    scanf("%s", ip_address);

    printf("Enter port range start: ");
    scanf("%d", &port_range_start);

    printf("Enter port range end: ");
    scanf("%d", &port_range_end);

    printf("Enter number of threads: ");
    scanf("%d", &num_threads);

    int thread_ids[MAX_THREADS];
    pthread_t threads[MAX_THREADS];
    PortScannerThreadData *thread_data[MAX_THREADS];

    for (int i = 0; i < num_threads; i++) {
        thread_data[i] = (PortScannerThreadData *) malloc(sizeof(PortScannerThreadData));
        thread_data[i]->ip = (char *) malloc(sizeof(char) * (strlen(ip_address) + 1));
        strcpy(thread_data[i]->ip, ip_address);
        thread_data[i]->port = port_range_start + i;
        thread_data[i]->socket = socket(AF_INET, SOCK_STREAM, 0);

        pthread_create(&threads[i], NULL, port_scanner_thread, thread_data[i]);
        thread_ids[i] = i;
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}