//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define NUM_THREADS 4

char *genome_sequence;
int sequence_length;

struct thread_data {
    int thread_id;
    int start_pos;
    int end_pos;
};

void *thread_function(void *arg) {
    struct thread_data *data = arg;
    int thread_id = data->thread_id;
    int start_pos = data->start_pos;
    int end_pos = data->end_pos;

    for (int i = start_pos; i < end_pos; i++) {
        genome_sequence[i] = 'A' + thread_id;
    }

    pthread_exit(0);
}

int main() {
    srand(time(NULL));

    sequence_length = MAX_SEQUENCE_LENGTH;
    genome_sequence = malloc(sequence_length * sizeof(char));

    pthread_t threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        struct thread_data *data = malloc(sizeof(struct thread_data));
        data->thread_id = i;
        data->start_pos = i * (sequence_length / NUM_THREADS);
        data->end_pos = (i + 1) * (sequence_length / NUM_THREADS);

        pthread_create(&threads[i], NULL, thread_function, data);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Genome sequence:\n%s\n", genome_sequence);

    free(genome_sequence);
    return 0;
}