#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_HOSTS 1024
#define BUFFER_SIZE 256

typedef struct {
    char host[BUFFER_SIZE];
    int port;
} HostPort;

HostPort hosts[MAX_HOSTS];
int host_count = 0;

void* scan_port(void* arg) {
    int index = *(int*)arg;
    HostPort hp = hosts[index];
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Socket creation failed");
        return NULL;
    }
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(hp.port);
    if (inet_pton(AF_INET, hp.host, &server_addr.sin_addr) <= 0) {
        close(sock);
        return NULL;
    }
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == 0) {
        printf("%s:%d is open\n", hp.host, hp.port);
    } else {
        // Handle error gracefully
    }
    close(sock);
    return NULL;
}

int main() {
    FILE *file = fopen("hosts.txt", "r");
    if (!file) {
        perror("File opening failed");
        return EXIT_FAILURE;
    }
    while (host_count < MAX_HOSTS && fscanf(file, "%s %d", hosts[host_count].host, &hosts[host_count].port) != EOF) {
        host_count++;
    }
    fclose(file);

    pthread_t threads[MAX_HOSTS];
    int thread_ids[MAX_HOSTS];

    for (int i = 0; i < host_count; i++) {
        thread_ids[i] = i;
        if (pthread_create(&threads[i], NULL, scan_port, &thread_ids[i]) != 0) {
            perror("Thread creation failed");
            return EXIT_FAILURE;
        }
    }

    for (int i = 0; i < host_count; i++) {
        pthread_join(threads[i], NULL);
    }

    return EXIT_SUCCESS;
}
