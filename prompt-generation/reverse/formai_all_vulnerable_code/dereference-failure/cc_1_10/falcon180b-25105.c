//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <ctype.h>

#define MAX_THREADS 100
#define MAX_PORTS 65535
#define THREAD_STACK_SIZE (1024*1024)

typedef struct {
    int sock;
    struct sockaddr_in server;
    int port;
} thread_data_t;

void *thread_func(void *arg) {
    thread_data_t *data = (thread_data_t *) arg;
    char buffer[1024];
    int bytes_received;

    if (connect(data->sock, (struct sockaddr *)&data->server, sizeof(data->server))!= 0) {
        close(data->sock);
        return NULL;
    }

    send(data->sock, "GET / HTTP/1.1\r\nHost: localhost\r\nConnection: close\r\n\r\n", 54, 0);

    bytes_received = recv(data->sock, buffer, sizeof(buffer), 0);
    if (bytes_received > 0) {
        buffer[bytes_received] = '\0';
        printf("Port %d is open\n", data->port);
    } else {
        printf("Port %d is closed\n", data->port);
    }

    close(data->sock);
    return NULL;
}

int main(int argc, char *argv[]) {
    int num_threads, i;
    pthread_t threads[MAX_THREADS];
    thread_data_t data[MAX_THREADS];

    if (argc!= 3) {
        printf("Usage: %s <ip address> <range>\n", argv[0]);
        return 1;
    }

    num_threads = atoi(argv[2]) - atoi(argv[1]) + 1;

    if (num_threads > MAX_THREADS || num_threads <= 0) {
        printf("Invalid range\n");
        return 1;
    }

    for (i = 0; i < num_threads; i++) {
        data[i].port = htons(atoi(argv[1]) + i);
        data[i].server.sin_family = AF_INET;
        data[i].server.sin_port = data[i].port;
        data[i].server.sin_addr.s_addr = inet_addr(argv[1]);

        pthread_create(&threads[i], NULL, thread_func, (void *)&data[i]);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}