//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_THREADS 100
#define BUFFER_SIZE 1024

int target_port;
char target_ip[20];
int num_threads;

void *scan_thread(void *arg) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(target_port);
    inet_pton(AF_INET, target_ip, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
        char buffer[BUFFER_SIZE];
        send(sock, "GET / HTTP/1.1\r\nHost: google.com\r\n\r\n", strlen("GET / HTTP/1.1\r\nHost: google.com\r\n\r\n"), 0);
        int bytes_received = 0;
        while ((bytes_received = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
            printf("Thread %d received response from port %d\n", (int)arg, target_port);
            printf("Response: %s", buffer);
        }
        close(sock);
    } else {
        printf("Thread %d failed to connect to port %d\n", (int)arg, target_port);
    }
    return NULL;
}

int main() {
    printf("Enter target IP address: ");
    scanf("%s", target_ip);
    printf("Enter target port number: ");
    scanf("%d", &target_port);
    printf("Enter number of threads: ");
    scanf("%d", &num_threads);

    pthread_t threads[MAX_THREADS];
    int thread_ids[MAX_THREADS];

    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, scan_thread, (void *)i);
        thread_ids[i] = i;
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}