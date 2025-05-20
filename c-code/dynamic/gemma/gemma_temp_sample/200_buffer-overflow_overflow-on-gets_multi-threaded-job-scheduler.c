#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <string.h>

#define MAX_THREADS 10

void *thread_func(void *thread_num) {
    char buffer[1024];
    gets(buffer);
    printf("Thread %ld: Message: %s\n", (long)thread_num, buffer);
    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    char *thread_args[MAX_THREADS];

    for (int i = 0; i < MAX_THREADS; i++) {
        thread_args[i] = malloc(sizeof(char *) * MAX_THREADS);
        pthread_create(&threads[i], NULL, thread_func, thread_args[i]);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
        free(thread_args[i]);
    }

    return 0;
}
