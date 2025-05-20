//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_THREADS 100
#define MAX_SEQUENCE_LENGTH 1000000
#define PORT 8080
#define BUFFER_SIZE 1024

struct thread_data {
    int thread_id;
    char *sequence;
    int sequence_length;
};

void *sequence_generator(void *arg) {
    struct thread_data *data = (struct thread_data *) arg;
    char sequence[MAX_SEQUENCE_LENGTH];
    int i, j;

    srand(time(NULL) + data->thread_id);

    for (i = 0; i < data->sequence_length; i++) {
        j = rand() % 4;
        if (j == 0) {
            sequence[i] = 'A';
        } else if (j == 1) {
            sequence[i] = 'C';
        } else if (j == 2) {
            sequence[i] = 'G';
        } else {
            sequence[i] = 'T';
        }
    }

    send(data->thread_id, sequence, strlen(sequence), 0);

    pthread_exit(NULL);
}

void *sequence_receiver(void *arg) {
    int thread_id = *(int *) arg;
    char sequence[MAX_SEQUENCE_LENGTH];
    int bytes_received;

    bytes_received = recv(thread_id, sequence, MAX_SEQUENCE_LENGTH, 0);

    printf("Thread %d received sequence: %s\n", thread_id, sequence);

    pthread_exit(NULL);
}

int main() {
    int i, bytes_sent;
    pthread_t threads[MAX_THREADS];
    struct thread_data thread_data[MAX_THREADS];

    printf("Starting genome sequencing simulator...\n");

    for (i = 0; i < MAX_THREADS; i++) {
        thread_data[i].thread_id = i;
        thread_data[i].sequence_length = MAX_SEQUENCE_LENGTH;
        pthread_create(&threads[i], NULL, sequence_generator, &thread_data[i]);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}