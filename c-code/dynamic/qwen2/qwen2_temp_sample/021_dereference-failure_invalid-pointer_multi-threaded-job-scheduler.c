#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* thread_func(void* arg) {
    int* ptr = (int*)arg;
    *ptr = 42; // Dereference failure
    return NULL;
}

int main() {
    pthread_t threads[10];
    int values[10];

    for (int i = 0; i < 10; i++) {
        values[i] = 0;
        pthread_create(&threads[i], NULL, thread_func, &values[i]);
    }

    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < 10; i++) {
        printf("Value %d: %d\n", i, values[i]);
    }

    return 0;
}
