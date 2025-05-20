#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_THREADS 1024

void* scan_port(void* arg) {
    int port = *(int*)arg;
    struct sockaddr_in server_addr;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Socket creation failed");
        return NULL;
    }
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        close(sock);
        return NULL;
    }

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == 0) {
        printf("Port %d is open\n", port);
    } else {
        // Do nothing if the port is closed
    }
    close(sock);
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <start_port> <end_port>\n", argv[0]);
        return 1;
    }

    int start_port, end_port;
    if (sscanf(argv[1], "%d", &start_port) != 1 || sscanf(argv[2], "%d", &end_port) != 1) {
        fprintf(stderr, "Invalid port numbers\n");
        return 1;
    }

    pthread_t threads[MAX_THREADS];
    int ports[MAX_THREADS];
    int num_threads = 0;

    for (int i = start_port; i <= end_port && num_threads < MAX_THREADS; i++) {
        ports[num_threads] = i;
        if (pthread_create(&threads[num_threads], NULL, scan_port, &ports[num_threads]) != 0) {
            perror("Thread creation failed");
            break;
        }
        num_threads++;
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
