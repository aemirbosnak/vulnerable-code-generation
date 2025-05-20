#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_HOSTS 1000
#define MAX_THREADS 50

typedef struct {
    char hostname[256];
    int port;
} HostPort;

HostPort hosts[MAX_HOSTS];
int num_hosts = 0;

void* scan_port(void* arg) {
    int thread_id = *(int*)arg;
    for (int i = thread_id; i < num_hosts; i += MAX_THREADS) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1) continue;

        struct sockaddr_in server_addr;
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        if (inet_pton(AF_INET, hosts[i].hostname, &server_addr.sin_addr) <= 0) {
            close(sock);
            continue;
        }
        server_addr.sin_port = htons(hosts[i].port);

        if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == 0) {
            printf("%s:%d is up\n", hosts[i].hostname, hosts[i].port);
        } else {
            printf("%s:%d is down\n", hosts[i].hostname, hosts[i].port);
        }

        close(sock);
    }
    return NULL;
}

int main() {
    FILE *file = fopen("hosts.txt", "r");
    if (!file) {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }

    while (num_hosts < MAX_HOSTS && fscanf(file, "%255[^ ] %d", hosts[num_hosts].hostname, &hosts[num_hosts].port) != EOF) {
        num_hosts++;
    }

    fclose(file);

    pthread_t threads[MAX_THREADS];
    int thread_ids[MAX_THREADS];

    for (int i = 0; i < MAX_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, scan_port, &thread_ids[i]);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return EXIT_SUCCESS;
}
