#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void* scan_port(void* arg) {
    int port = *(int*)arg;
    printf("Scanning port %d\n", port);
    return NULL;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s \"port_range\"\n", argv[0]);
        return 1;
    }

    int start, end;
    if (sscanf(argv[1], "%d-%d", &start, &end) != 2) {
        fprintf(stderr, "Invalid port range format\n");
        return 1;
    }

    pthread_t threads[end - start + 1];
    for (int i = start; i <= end; i++) {
        pthread_create(&threads[i - start], NULL, scan_port, &i);
    }

    for (int i = start; i <= end; i++) {
        pthread_join(threads[i - start], NULL);
    }

    return 0;
}
