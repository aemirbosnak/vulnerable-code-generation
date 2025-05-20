#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <arpa/inet.h>

#define MAX_HOSTS 1024
#define PORT_RANGE_START 1
#define PORT_RANGE_END 65535

typedef struct {
    char hostname[256];
    int port;
} HostPort;

HostPort hosts[MAX_HOSTS];
int num_hosts = 0;

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

    if (inet_pton(AF_INET, hp.hostname, &server_addr.sin_addr) <= 0) {
        close(sock);
        return NULL;
    }

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == 0) {
        printf("%s:%d is open\n", hp.hostname, hp.port);
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

    while (fscanf(file, "%255[^ ] %d", hosts[num_hosts].hostname, &hosts[num_hosts].port) != EOF) {
        num_hosts++;
    }
    fclose(file);

    pthread_t threads[num_hosts];
    int thread_ids[num_hosts];

    for (int i = 0; i < num_hosts; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, scan_port, &thread_ids[i]);
    }

    for (int i = 0; i < num_hosts; i++) {
        pthread_join(threads[i], NULL);
    }

    return EXIT_SUCCESS;
}
