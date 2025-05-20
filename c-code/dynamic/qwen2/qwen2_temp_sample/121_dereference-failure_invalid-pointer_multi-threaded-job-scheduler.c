#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* thread_func(void* arg) {
    int* ptr = (int*)arg;
    *ptr = 42; // Dereference failure: accessing invalid memory
    return NULL;
}

int main() {
    pthread_t threads[10];
    int data[10];

    for (int i = 0; i < 10; ++i) {
        data[i] = 0;
        pthread_create(&threads[i], NULL, thread_func, &data[i]);
    }

    for (int i = 0; i < 10; ++i) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < 10; ++i) {
        printf("Data[%d]: %d\n", i, data[i]);
    }

    return 0;
}
