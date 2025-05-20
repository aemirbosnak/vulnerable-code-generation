#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *thread_function(void *arg) {
    int *ptr = (int *)arg;
    printf("Thread %d: Attempting to dereference invalid pointer: %p\n", *ptr, ptr);
    *ptr = 10;
    return NULL;
}

int main() {
    pthread_t threads[10];
    int i;
    int *arr = NULL;

    for (i = 0; i < 10; i++) {
        arr = realloc(arr, (i + 1) * sizeof(int));
        pthread_create(&threads[i], NULL, thread_function, (void *)arr);
    }

    for (i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
