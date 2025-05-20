//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/time.h>
#include <pthread.h>

#define MAX_THREADS 64
#define MAX_PORTS 65535
#define TIMEOUT 1000 // 1 second

// Struct to hold thread data
typedef struct {
    int thread_id;
    int sock;
} thread_data;

// Function to check if a port is open
int check_port(int sock, int port) {
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
        close(sock);
        return 1;
    } else {
        close(sock);
        return 0;
    }
}

// Function to run in each thread
void *port_scanner(void *arg) {
    thread_data *data = (thread_data *) arg;
    int thread_id = data->thread_id;
    int sock = data->sock;

    for (int i = thread_id * MAX_PORTS / MAX_THREADS; i < (thread_id + 1) * MAX_PORTS / MAX_THREADS; i++) {
        if (check_port(sock, i)) {
            printf("Port %d is open on thread %d\n", i, thread_id);
        }
    }

    return NULL;
}

int main() {
    int num_threads = 4;
    pthread_t threads[MAX_THREADS];
    int socks[MAX_THREADS];

    // Create sockets for each thread
    for (int i = 0; i < num_threads; i++) {
        socks[i] = socket(AF_INET, SOCK_STREAM, 0);
    }

    // Create threads
    for (int i = 0; i < num_threads; i++) {
        thread_data data;
        data.thread_id = i;
        data.sock = socks[i];
        pthread_create(&threads[i], NULL, port_scanner, &data);
    }

    // Wait for threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
        close(socks[i]);
    }

    return 0;
}