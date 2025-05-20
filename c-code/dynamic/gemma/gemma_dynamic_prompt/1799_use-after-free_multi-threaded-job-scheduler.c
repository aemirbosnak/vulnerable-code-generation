#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *thread_func(void *arg) {
    printf("Hello, world! from thread %ld\n", (long)arg);
    sleep(5);
    free(arg);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[10];
    void *args[10];

    for (int i = 0; i < 10; i++) {
        args[i] = malloc(10);
        pthread_create(&threads[i], NULL, thread_func, args[i]);
    }

    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
