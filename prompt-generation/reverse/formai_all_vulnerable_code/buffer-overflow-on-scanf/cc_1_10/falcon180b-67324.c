//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: multiplayer
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<pthread.h>

#define MAX_THREADS 100
#define PORT_RANGE_MIN 1
#define PORT_RANGE_MAX 65535

int port_range[MAX_THREADS];
int thread_count = 0;

void *scan_ports(void *arg) {
    int thread_id = *(int *) arg;
    int start_port = PORT_RANGE_MIN + thread_id * (PORT_RANGE_MAX - PORT_RANGE_MIN) / thread_count;
    int end_port = start_port + (PORT_RANGE_MAX - PORT_RANGE_MIN) / thread_count;

    for(int i=start_port; i<=end_port; i++) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        struct sockaddr_in server;
        server.sin_family = AF_INET;
        server.sin_port = htons(i);
        server.sin_addr.s_addr = inet_addr("127.0.0.1");

        if(connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
            printf("Port %d is open on thread %d\n", i, thread_id);
        } else {
            printf("Port %d is closed on thread %d\n", i, thread_id);
        }
        close(sock);
    }
    return NULL;
}

int main() {
    int num_threads;
    printf("Enter number of threads: ");
    scanf("%d", &num_threads);

    if(num_threads < 1 || num_threads > MAX_THREADS) {
        printf("Invalid number of threads\n");
        return 1;
    }

    thread_count = num_threads;

    for(int i=0; i<thread_count; i++) {
        port_range[i] = PORT_RANGE_MIN + i * (PORT_RANGE_MAX - PORT_RANGE_MIN) / thread_count;
    }

    pthread_t threads[thread_count];

    for(int i=0; i<thread_count; i++) {
        pthread_create(&threads[i], NULL, scan_ports, (void *)&i);
    }

    for(int i=0; i<thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}