//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define PORT_SCAN_RANGE 1024
#define PORT_SCAN_THREADS 10

void *port_scan_thread(void *arg);

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    struct hostent *host = gethostbyname(ip_address);
    if (host == NULL) {
        printf("Invalid IP address\n");
        return 1;
    }

    int *ports = malloc(PORT_SCAN_RANGE * sizeof(int));
    for (int i = 0; i < PORT_SCAN_RANGE; i++) {
        ports[i] = i;
    }

    pthread_t threads[PORT_SCAN_THREADS];
    for (int i = 0; i < PORT_SCAN_THREADS; i++) {
        pthread_create(&threads[i], NULL, port_scan_thread, (void *)&ports[i * PORT_SCAN_RANGE / PORT_SCAN_THREADS]);
    }

    for (int i = 0; i < PORT_SCAN_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    free(ports);
    return 0;
}

void *port_scan_thread(void *arg) {
    int *ports = arg;
    int start_port = *ports;
    int end_port = *(ports + 1);

    for (int port = start_port; port <= end_port; port++) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        struct sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        inet_pton(AF_INET, "0.0.0.0", &addr.sin_addr);

        if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
            printf("Port %d is open\n", port);
            close(sock);
        } else {
            // Do nothing
        }
    }

    return NULL;
}