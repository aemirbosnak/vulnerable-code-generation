//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_THREADS 100
#define BUFFER_SIZE 1024

int target_port;
char target_ip[16];
int num_threads;
int thread_id;
int thread_socket;

void *thread_function(void *arg) {
    int thread_socket = (int) arg;

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    int bytes_received = recv(thread_socket, buffer, BUFFER_SIZE, 0);

    if (bytes_received > 0) {
        printf("Thread %d received data: %s\n", thread_id, buffer);
        close(thread_socket);
    } else {
        printf("Thread %d received nothing\n", thread_id);
        close(thread_socket);
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <target IP> <target port> <num threads>\n", argv[0]);
        return 1;
    }

    strcpy(target_ip, argv[1]);
    target_port = atoi(argv[2]);
    num_threads = atoi(argv[3]);

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(target_port);
    inet_pton(AF_INET, target_ip, &server_addr.sin_addr);

    if (connect(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to target\n");
        close(server_socket);
        return 1;
    }

    printf("Connected to target\n");

    pthread_t threads[MAX_THREADS];

    for (int i = 0; i < num_threads; i++) {
        thread_id = i;
        pthread_create(&threads[i], NULL, thread_function, (void *) server_socket);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    close(server_socket);

    return 0;
}