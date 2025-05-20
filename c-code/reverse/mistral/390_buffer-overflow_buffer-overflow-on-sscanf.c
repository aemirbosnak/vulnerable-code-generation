#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void *port_scanner(void *arg) {
    int port = *(int *)arg;
    // Your port scanning code here
}

int main(int argc, char *argv[]) {
    int start, end, i;
    char buffer[10];

    if (argc != 4) {
        printf("Usage: %s <start_port> <end_port> <num_threads>\n", argv[0]);
        return 1;
    }

    sscanf(argv[1], "%s", buffer);
    start = atoi(buffer);
    sscanf(argv[2], "%s", buffer);
    end = atoi(buffer);
    sscanf(argv[3], "%s", buffer);
    int num_threads = atoi(buffer);

    pthread_t threads[num_threads];

    for (i = start; i <= end; ++i) {
        pthread_create(&threads[i - start], NULL, port_scanner, &i);
    }

    for (i = 0; i < num_threads; ++i) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
