#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>

#define MAX_THREADS 10

pthread_t threads[MAX_THREADS];
char buffer[1024];

void* thread_function(void* thread_id) {
    int i = (int)thread_id;
    printf("Thread %d: Enter a command: ", i);
    scanf("%s", buffer);

    printf("Thread %d: Your command: %s\n", i, buffer);
    pthread_exit(NULL);
}

int main() {
    int i;
    pthread_t t_id;

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_function, (void*)i);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
