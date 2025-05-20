#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_THREADS 100

void* scan_port(void* arg) {
    int* port = (int*)arg;
    struct sockaddr_in server_addr;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) return NULL;

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, "192.168.1.100", &server_addr.sin_addr);
    server_addr.sin_port = htons(*port);

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == 0) {
        printf("Port %d is open\n", *port);
    }
    close(sock);
    free(port);
    return NULL;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <port_range>\n", argv[0]);
        return 1;
    }

    char* host = argv[1];
    char* port_range = argv[2];
    int start_port, end_port;
    sscanf(port_range, "%d-%d", &start_port, &end_port);

    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    for (int i = start_port; i <= end_port; i++) {
        int* port = malloc(sizeof(int));
        *port = i;
        if (pthread_create(&threads[thread_count], NULL, scan_port, port) != 0) {
            free(port);
            continue;
        }
        thread_count++;
        if (thread_count >= MAX_THREADS) {
            for (int j = 0; j < thread_count; j++) {
                pthread_join(threads[j], NULL);
            }
            thread_count = 0;
        }
    }

    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
