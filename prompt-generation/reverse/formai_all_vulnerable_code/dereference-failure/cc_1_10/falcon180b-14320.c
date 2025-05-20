//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <pthread.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define NUM_THREADS 4

typedef struct {
    char *sequence;
    int length;
} Sequence;

Sequence *sequences;
pthread_t threads[NUM_THREADS];
int num_sequences;

void *runner(void *arg) {
    int i;
    for (i = 0; i < MAX_SEQUENCE_LENGTH; i++) {
        if (sequences[i % num_sequences].sequence[i] == 'A') {
            sequences[i % num_sequences].sequence[i] = 'T';
        } else if (sequences[i % num_sequences].sequence[i] == 'T') {
            sequences[i % num_sequences].sequence[i] = 'A';
        } else if (sequences[i % num_sequences].sequence[i] == 'C') {
            sequences[i % num_sequences].sequence[i] = 'G';
        } else if (sequences[i % num_sequences].sequence[i] == 'G') {
            sequences[i % num_sequences].sequence[i] = 'C';
        }
    }
    return NULL;
}

int main() {
    int i;
    sequences = (Sequence *) malloc(NUM_THREADS * sizeof(Sequence));
    srand(time(NULL));
    for (i = 0; i < NUM_THREADS; i++) {
        sequences[i].sequence = (char *) malloc(MAX_SEQUENCE_LENGTH * sizeof(char));
        sequences[i].length = MAX_SEQUENCE_LENGTH;
        int j;
        for (j = 0; j < sequences[i].length; j++) {
            sequences[i].sequence[j] = 'A' + rand() % 4;
        }
    }
    num_sequences = NUM_THREADS;
    int rc;
    for (i = 0; i < NUM_THREADS; i++) {
        rc = pthread_create(&threads[i], NULL, runner, (void *) &sequences[i]);
        if (rc) {
            printf("Error: unable to create thread, %d\n", rc);
            exit(-1);
        }
    }
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    for (i = 0; i < NUM_THREADS; i++) {
        free(sequences[i].sequence);
    }
    free(sequences);
    return 0;
}