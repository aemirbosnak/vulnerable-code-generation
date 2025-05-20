//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 4
#define SEQUENCE_LENGTH 1000000

char *sequence;
int sequence_length;
int num_threads;
pthread_t threads[MAX_THREADS];
int results[MAX_THREADS];

void *runner(void *arg) {
    int start = *(int *) arg;
    int end = start + sequence_length / num_threads;
    int count = 0;

    for (int i = start; i < end; i++) {
        if (sequence[i] == 'A') {
            count++;
        }
    }

    results[*(int *) arg] = count;
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <sequence> <num_threads>\n", argv[0]);
        return 1;
    }

    sequence_length = strlen(argv[1]);
    sequence = argv[1];
    num_threads = atoi(argv[2]);

    if (num_threads > MAX_THREADS || num_threads <= 0) {
        printf("Invalid number of threads.\n");
        return 1;
    }

    for (int i = 0; i < num_threads; i++) {
        int start = i * SEQUENCE_LENGTH / num_threads;
        int end = (i == num_threads - 1)? sequence_length : (i + 1) * SEQUENCE_LENGTH / num_threads;
        pthread_create(&threads[i], NULL, runner, &i);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Number of A's in the sequence: %d\n", results[0]);

    return 0;
}