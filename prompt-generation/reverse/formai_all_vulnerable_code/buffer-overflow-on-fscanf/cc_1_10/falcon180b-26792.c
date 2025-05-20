//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_ELEMENTS 118
#define NUM_THREADS 4

struct element {
    char symbol[3];
    char name;
    int atomic_number;
    float atomic_weight;
};

struct element elements[NUM_ELEMENTS];

void init_elements() {
    FILE *fp = fopen("elements.txt", "r");
    if (fp == NULL) {
        printf("Error opening elements file.\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(fp, "%s %c %d %f", elements[i].symbol, &elements[i].name, &elements[i].atomic_number, &elements[i].atomic_weight)!= EOF) {
        i++;
    }

    fclose(fp);
}

void *thread_func(void *arg) {
    int start = *(int *) arg;
    int end = start + 29;

    for (int i = start; i < end; i++) {
        printf("%d. %s (%c)\n", i + 1, elements[i].name, elements[i].symbol[0]);
    }

    return NULL;
}

int main() {
    init_elements();

    pthread_t threads[NUM_THREADS];
    int ids[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        ids[i] = i * 30;
        pthread_create(&threads[i], NULL, thread_func, &ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}