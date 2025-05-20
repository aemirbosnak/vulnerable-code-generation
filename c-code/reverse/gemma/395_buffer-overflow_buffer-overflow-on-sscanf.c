#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *scanner(int port) {
    char buf[1024];
    sprintf(buf, "Trying port %d...", port);
    printf(buf);
    if (snprintf(buf, sizeof(buf), "TCP/IP port %d is open", port) >= 0) {
        printf(buf);
    }
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: scanner <port range>\n");
        return 1;
    }

    char *port_range = argv[1];
    int min_port, max_port;
    if (sscanf(port_range, "%d-%d", &min_port, &max_port) != 2) {
        printf("Error parsing port range.\n");
        return 1;
    }

    pthread_t threads[max_port - min_port + 1];
    for (int i = min_port; i <= max_port; i++) {
        pthread_create(&threads[i], NULL, scanner, (void *)i);
    }

    for (int i = min_port; i <= max_port; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
