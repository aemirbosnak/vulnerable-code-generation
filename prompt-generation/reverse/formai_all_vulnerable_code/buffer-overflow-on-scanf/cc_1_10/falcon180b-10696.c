//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_THREADS 100
#define PORT_RANGE_MIN 1
#define PORT_RANGE_MAX 65535

int port_range[2] = {PORT_RANGE_MIN, PORT_RANGE_MAX};
int num_threads = 1;
int thread_id = 0;

void *thread_func(void *arg) {
    int thread_id = *(int *) arg;
    int start_port = port_range[0] + thread_id * (port_range[1] - port_range[0]) / num_threads;
    int end_port = start_port + (port_range[1] - port_range[0]) / num_threads - 1;

    printf("Thread %d scanning ports %d-%d\n", thread_id, start_port, end_port);

    for (int port = start_port; port <= end_port; port++) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        struct sockaddr_in server;
        memset(&server, 0, sizeof(server));
        server.sin_family = AF_INET;
        server.sin_port = htons(port);
        inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);

        int result = connect(sock, (struct sockaddr *)&server, sizeof(server));

        if (result == 0) {
            printf("Port %d is open\n", port);
        } else {
            printf("Port %d is closed\n", port);
        }

        close(sock);
    }

    return NULL;
}

int main() {
    printf("Medieval Port Scanner\n");
    printf("Enter number of threads (1-100): ");
    scanf("%d", &num_threads);

    pthread_t threads[MAX_THREADS];

    for (int i = 0; i < num_threads; i++) {
        int *thread_arg = malloc(sizeof(int));
        *thread_arg = i;
        pthread_create(&threads[i], NULL, thread_func, thread_arg);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}