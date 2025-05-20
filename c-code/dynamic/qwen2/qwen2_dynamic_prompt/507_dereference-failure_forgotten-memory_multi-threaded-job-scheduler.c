#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* thread_func(void* arg) {
    int* ptr = (int*)malloc(sizeof(int));
    *ptr = 42;
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[10];
    for (int i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, thread_func, NULL);
    }

    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    // Dereference a freed pointer
    int value = *(int*)NULL;

    printf("Value: %d\n", value);

    return 0;
}
