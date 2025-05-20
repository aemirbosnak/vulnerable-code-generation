//GEMINI-pro DATASET v1.0 Category: Periodic Table Quiz ; Style: multi-threaded
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_THREADS 8
#define MAX_SYMBOLS 118

typedef struct {
    char symbol[3];
    int atomic_number;
    char name[20];
    char category[20];
    double atomic_mass;
    int group;
    int period;
} element_t;

element_t elements[MAX_SYMBOLS];

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *quiz_thread(void *arg) {
    int *ptr = (int *)arg;
    int i = *ptr;
    char guess[3];
    int correct = 0;

    pthread_mutex_lock(&mutex);
    printf("%d. What is the symbol for element %d (%s)? ", i, elements[i].atomic_number, elements[i].name);
    fflush(stdout);
    scanf(" %s", guess);
    pthread_mutex_unlock(&mutex);

    if (strcasecmp(elements[i].symbol, guess) == 0) {
        correct = 1;
    }

    pthread_mutex_lock(&mutex);
    printf("%s is %s\n", guess, correct ? "correct" : "incorrect");
    pthread_mutex_unlock(&mutex);

    return (void *)correct;
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[100];
    int i = 0;
    int correct_count = 0;
    pthread_t threads[MAX_THREADS];

    fp = fopen("periodic_table.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        sscanf(line, "%s %d %s %s %lf %d %d", elements[i].symbol, &elements[i].atomic_number, elements[i].name, elements[i].category, &elements[i].atomic_mass, &elements[i].group, &elements[i].period);
        i++;
    }

    fclose(fp);

    for (i = 0; i < MAX_THREADS; i++) {
        int *ptr = malloc(sizeof(int));
        *ptr = i;
        pthread_create(&threads[i], NULL, quiz_thread, (void *)ptr);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        void *status;
        pthread_join(threads[i], &status);
        correct_count += (int)status;
    }

    printf("You got %d out of %d correct\n", correct_count, MAX_THREADS);

    return 0;
}