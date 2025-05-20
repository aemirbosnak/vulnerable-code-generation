#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_t threads[1000];
int jobs[1000];

void* thread_function(void* arg) {
    int i = (int)arg;
    jobs[i] = 1 + jobs[i];
    pthread_exit(NULL);
}

int main() {
    int i;
    for (i = 0; i < 1000; i++) {
        pthread_create(&threads[i], NULL, thread_function, (void*)i);
    }

    for (i = 0; i < 1000; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
