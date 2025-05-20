//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_STRING_LENGTH 100

char strings[MAX_THREADS][MAX_STRING_LENGTH];
int string_lengths[MAX_THREADS];
pthread_t threads[MAX_THREADS];
int num_threads;

void *reverse_string(void *arg) {
    int thread_num = *((int *) arg);
    int length = string_lengths[thread_num];
    char *string = strings[thread_num];

    for (int i = 0; i < length / 2; i++) {
        char temp = string[i];
        string[i] = string[length - i - 1];
        string[length - i - 1] = temp;
    }

    printf("Thread %d reversed string: %s\n", thread_num, string);

    pthread_exit(0);
}

int main() {
    printf("Enter number of threads (1-10): ");
    scanf("%d", &num_threads);

    if (num_threads < 1 || num_threads > MAX_THREADS) {
        printf("Invalid number of threads\n");
        return 1;
    }

    printf("Enter strings:\n");
    for (int i = 0; i < num_threads; i++) {
        scanf("%s", strings[i]);
        string_lengths[i] = strlen(strings[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, reverse_string, (void *) &i);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}