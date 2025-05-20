//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define NUM_THREADS 4
#define MAX_STRING_LEN 100

char strings[NUM_THREADS][MAX_STRING_LEN];
pthread_t threads[NUM_THREADS];
int finished[NUM_THREADS];

void *thread_func(void *arg) {
    int i, j;
    char *str = (char *) arg;

    for (i = 0; i < strlen(str); i++) {
        for (j = 0; j < strlen(str); j++) {
            if (i!= j) {
                str[i] = str[j];
            }
        }
    }

    finished[*(int *) arg] = 1;
    pthread_exit(0);
}

int main() {
    int i;

    for (i = 0; i < NUM_THREADS; i++) {
        printf("Enter string %d: ", i + 1);
        scanf("%s", strings[i]);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void *) &i);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        printf("Thread %d finished. Result: %s\n", i + 1, strings[i]);
    }

    return 0;
}