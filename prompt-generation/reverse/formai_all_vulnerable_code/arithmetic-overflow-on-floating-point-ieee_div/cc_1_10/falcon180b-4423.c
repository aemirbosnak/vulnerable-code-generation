//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define NUM_THREADS 5

typedef struct {
    int id;
    int socket;
} thread_data_t;

void *thread_func(void *arg) {
    thread_data_t *data = (thread_data_t *) arg;
    int socket = data->socket;

    char buffer[BUFFER_SIZE];
    int bytes_received = 0;

    while (1) {
        bytes_received = recv(socket, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            break;
        }

        time_t start_time = time(NULL);

        for (int i = 0; i < bytes_received; i++) {
            // Do some processing here
        }

        time_t end_time = time(NULL);
        double elapsed_time = difftime(end_time, start_time);
        double speed = (double) bytes_received / elapsed_time;

        printf("Thread %d received %d bytes in %lf seconds (%.2lf bytes/sec)\n", data->id, bytes_received, elapsed_time, speed);
    }

    close(socket);
    return NULL;
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr));
    listen(server_socket, 5);

    printf("Server started on port 8080\n");

    thread_data_t thread_data[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].id = i + 1;
        thread_data[i].socket = accept(server_socket, NULL, NULL);

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, thread_func, &thread_data[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(thread_data[i].socket, NULL);
    }

    close(server_socket);

    return 0;
}