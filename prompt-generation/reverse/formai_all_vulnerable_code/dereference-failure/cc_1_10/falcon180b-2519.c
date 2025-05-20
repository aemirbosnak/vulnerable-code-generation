//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define DEBUG 0

#if DEBUG
#define LOG(...) fprintf(stdout, __VA_ARGS__)
#else
#define LOG(...)
#endif

#define MAX_THREADS 100
#define MAX_PORTS 10000

typedef struct thread_data {
    int id;
    int start_port;
    int end_port;
} thread_data_t;

void *scan_ports(void *arg) {
    thread_data_t *data = (thread_data_t *) arg;
    int start_port = data->start_port;
    int end_port = data->end_port;

    for (int port = start_port; port <= end_port; port++) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1) {
            LOG("Error creating socket for port %d\n", port);
            continue;
        }

        struct sockaddr_in addr;
        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        addr.sin_addr.s_addr = inet_addr("127.0.0.1");

        if (connect(sock, (struct sockaddr *) &addr, sizeof(addr)) == 0) {
            LOG("Port %d is open\n", port);
            close(sock);
        } else {
            LOG("Port %d is closed\n", port);
        }
    }

    return NULL;
}

int main() {
    int num_threads = MAX_THREADS;
    pthread_t threads[MAX_THREADS];

    for (int i = 0; i < num_threads; i++) {
        thread_data_t data;
        data.id = i + 1;
        data.start_port = i * (MAX_PORTS / num_threads) + 1;
        data.end_port = (i == num_threads - 1)? MAX_PORTS : (i + 1) * (MAX_PORTS / num_threads);

        pthread_create(&threads[i], NULL, scan_ports, &data);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}