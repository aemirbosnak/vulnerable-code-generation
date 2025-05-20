#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_t threads[10];
int shared_array[10] = {0};

void *thread_function(void *thread_id) {
    int index = (int)thread_id;
    shared_array[index] = 100;
    return NULL;
}

int main() {
    pthread_create(threads, NULL, thread_function, (void *)0);
    pthread_create(threads + 1, NULL, thread_function, (void *)1);
    pthread_create(threads + 2, NULL, thread_function, (void *)2);
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);
    pthread_join(threads[2], NULL);

    return 0;
}
