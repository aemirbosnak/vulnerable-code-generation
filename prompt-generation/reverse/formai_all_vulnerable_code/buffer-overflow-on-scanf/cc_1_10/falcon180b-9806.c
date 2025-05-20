//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 100
#define BUFFER_SIZE 1024

int target_port;
char target_ip[16];
int num_threads;
int thread_id;
int thread_count;

void *scan_thread(void *arg) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(target_port);
    inet_pton(AF_INET, target_ip, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
        char buffer[BUFFER_SIZE];
        snprintf(buffer, BUFFER_SIZE, "Thread %d connected to %s:%d\n", thread_id, target_ip, target_port);
        write(sock, buffer, strlen(buffer));
        close(sock);
        return NULL;
    } else {
        char buffer[BUFFER_SIZE];
        snprintf(buffer, BUFFER_SIZE, "Thread %d failed to connect to %s:%d\n", thread_id, target_ip, target_port);
        write(1, buffer, strlen(buffer));
        close(sock);
        return NULL;
    }
}

int main(int argc, char *argv[]) {
    printf("Enter target IP: ");
    scanf("%s", target_ip);
    printf("Enter target port: ");
    scanf("%d", &target_port);
    printf("Enter number of threads: ");
    scanf("%d", &num_threads);

    pthread_t threads[MAX_THREADS];
    thread_count = 0;

    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, scan_thread, (void *)i);
        thread_count++;
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}