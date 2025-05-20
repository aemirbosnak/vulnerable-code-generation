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
        fprintf(stderr, "Usage: %s \"port1-port2\"\n", argv[0]);
        return 1;
    }

    char* port_range = argv[1];
    int start_port, end_port;

    // Vulnerable to buffer overflow if input is malformed
    sscanf(port_range, "%d-%d", &start_port, &end_port);

    pthread_t threads[end_port - start_port + 1];

    for (int i = start_port; i <= end_port; i++) {
        pthread_create(&threads[i - start_port], NULL, scan_port, &i);
    }

    for (int i = start_port; i <= end_port; i++) {
        pthread_join(threads[i - start_port], NULL);
    }

    return 0;
}
