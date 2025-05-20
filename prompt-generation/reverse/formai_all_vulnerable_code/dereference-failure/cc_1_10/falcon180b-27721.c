//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define SERVER_PORT 8080
#define SERVER_IP "127.0.0.1"
#define MAX_THREADS 10
#define BUFFER_SIZE 1024

struct thread_data {
    int thread_id;
    int sock;
};

void *download_thread(void *arg) {
    struct thread_data *data = (struct thread_data *) arg;
    char buffer[BUFFER_SIZE];
    int bytes_received = 0;

    while (bytes_received < 1000000) {
        int result = recv(data->sock, buffer, BUFFER_SIZE, 0);
        if (result <= 0) {
            break;
        }
        bytes_received += result;
    }

    close(data->sock);
    return NULL;
}

int main() {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    connect(server_sock, (struct sockaddr *) &server_addr, sizeof(server_addr));

    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    while (thread_count < MAX_THREADS) {
        int result = pthread_create(&threads[thread_count], NULL, download_thread, (void *) ++thread_count);
        if (result!= 0) {
            break;
        }
    }

    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    close(server_sock);
    return 0;
}