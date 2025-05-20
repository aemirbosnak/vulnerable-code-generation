//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_THREADS 10
#define MAX_CONSPIRACY_LENGTH 50

struct conspiracy_theory {
    char theory[MAX_CONSPIRACY_LENGTH];
    int thread_id;
};

pthread_mutex_t print_mutex = PTHREAD_MUTEX_INITIALIZER;

void *generate_conspiracy_theory(void *arg) {
    int i;
    struct conspiracy_theory *theory = (struct conspiracy_theory *) arg;

    srand(time(NULL) + theory->thread_id);

    for (i = 0; i < MAX_CONSPIRACY_LENGTH; i++) {
        theory->theory[i] = rand() % 26 + 'a';
    }

    theory->theory[i] = '\0';

    pthread_mutex_lock(&print_mutex);
    printf("Conspiracy theory #%d: %s\n", theory->thread_id, theory->theory);
    pthread_mutex_unlock(&print_mutex);

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    struct conspiracy_theory theories[NUM_THREADS];

    int i;

    for (i = 0; i < NUM_THREADS; i++) {
        theories[i].thread_id = i;
        pthread_create(&threads[i], NULL, generate_conspiracy_theory, &theories[i]);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}