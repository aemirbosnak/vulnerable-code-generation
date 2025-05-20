//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORT 65535
#define MAX_THREADS 100

struct hostent *gethostbyname(const char *name);

void *scan_ports(void *arg) {
    int sock = *(int *) arg;
    char *ip = inet_ntoa(((struct sockaddr_in *) arg)->sin_addr);
    printf("Scanning ports on %s...\n", ip);

    for (int port = 1; port <= MAX_PORT; port++) {
        if (port % 1000 == 1) {
            printf("\rScanning port %d...", port);
        }
        if (connect(sock, (struct sockaddr *) arg, sizeof(struct sockaddr_in)) == 0) {
            close(sock);
            printf("\nPort %d is open.\n", port);
            return NULL;
        }
    }

    printf("\nAll ports are closed.\n");
    close(sock);
    return NULL;
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s <IP address> <port range>\n", argv[0]);
        return 1;
    }

    int start_port, end_port;
    if (sscanf(argv[2], "%d-%d", &start_port, &end_port)!= 2 || start_port > end_port) {
        printf("Invalid port range.\n");
        return 1;
    }

    int threads[MAX_THREADS];
    pthread_t thread_ids[MAX_THREADS];

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(start_port);
    inet_pton(AF_INET, argv[1], &server.sin_addr);

    for (int i = 0; i < MAX_THREADS; i++) {
        if (pthread_create(&thread_ids[i], NULL, scan_ports, (void *) &server)!= 0) {
            printf("Error creating thread.\n");
            return 1;
        }
        threads[i] = thread_ids[i];
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}