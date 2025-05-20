//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_THREADS 100
#define BUFFER_SIZE 1024

struct thread_data {
    int sock;
    struct sockaddr_in server;
};

void *scan_port(void *arg) {
    struct thread_data *data = (struct thread_data *) arg;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    if (connect(data->sock, (struct sockaddr *) &data->server, sizeof(data->server))!= 0) {
        printf("Port %d is closed\n", ntohs(data->server.sin_port));
        close(data->sock);
        return NULL;
    }

    printf("Port %d is open\n", ntohs(data->server.sin_port));
    close(data->sock);
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <IP address> <port range>\n", argv[0]);
        return 1;
    }

    char *ip = argv[1];
    char *port_range = argv[2];
    int start_port, end_port;
    int num_threads = 0;

    if (sscanf(port_range, "%d-%d", &start_port, &end_port)!= 2) {
        printf("Invalid port range\n");
        return 1;
    }

    pthread_t threads[MAX_THREADS];

    for (int i = start_port; i <= end_port; i++) {
        if (num_threads >= MAX_THREADS) {
            printf("Maximum number of threads reached\n");
            break;
        }

        struct sockaddr_in server;
        memset(&server, 0, sizeof(server));
        server.sin_family = AF_INET;
        server.sin_port = htons(i);
        inet_pton(AF_INET, ip, &server.sin_addr);

        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1) {
            printf("Error creating socket: %s\n", strerror(errno));
            continue;
        }

        struct thread_data *data = malloc(sizeof(struct thread_data));
        data->sock = sock;
        data->server = server;

        pthread_create(&threads[num_threads], NULL, scan_port, data);
        num_threads++;
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}