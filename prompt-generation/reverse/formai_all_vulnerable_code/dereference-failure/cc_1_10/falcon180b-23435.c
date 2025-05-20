//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: modular
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

#define MAX_THREADS 100
#define BUFFER_SIZE 1024
#define THREAD_STACK_SIZE 8192
#define MAX_PORTS_PER_THREAD 100

typedef struct {
    int sock;
    struct sockaddr_in server;
    int port;
    int thread_id;
} thread_data_t;

void *port_scanner(void *arg) {
    thread_data_t *data = (thread_data_t *) arg;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    for (int i = 0; i < MAX_PORTS_PER_THREAD; i++) {
        data->port = i + 1;
        if (connect(data->sock, (struct sockaddr *) &data->server, sizeof(data->server)) == 0) {
            printf("Port %d is open on IP address %s\n", data->port, inet_ntoa(data->server.sin_addr));
        } else {
            printf("Port %d is closed on IP address %s\n", data->port, inet_ntoa(data->server.sin_addr));
        }
        close(data->sock);
        data->sock = socket(AF_INET, SOCK_STREAM, 0);
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <IP address> <number of threads>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    int num_threads = atoi(argv[2]);

    if (num_threads > MAX_THREADS) {
        printf("Number of threads cannot be greater than %d\n", MAX_THREADS);
        return 1;
    }

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(ip_address);
    server.sin_port = htons(80);

    if (connect(server_socket, (struct sockaddr *) &server, sizeof(server)) == -1) {
        printf("Error connecting to IP address %s: %s\n", ip_address, strerror(errno));
        close(server_socket);
        return 1;
    }

    pthread_t threads[num_threads];
    thread_data_t data[num_threads];

    for (int i = 0; i < num_threads; i++) {
        data[i].sock = server_socket;
        data[i].server = server;
        data[i].thread_id = i + 1;
        pthread_create(&threads[i], NULL, port_scanner, &data[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    close(server_socket);
    return 0;
}