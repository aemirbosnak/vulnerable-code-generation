#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>

pthread_t threads[10];
void* thread_function(void* thread_id) {
    int* ptr = NULL;
    *ptr = 10;
    printf("Thread ID: %ld, Value: %d\n", (long)thread_id, *ptr);
    pthread_exit(NULL);
}

int main() {
    for (int i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, thread_function, (void*)i);
    }
    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}
