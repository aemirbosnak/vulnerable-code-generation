#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <pthread.h>

void *thread_func(void *arg) {
    char buffer[10];
    gets(buffer);
    printf("Thread: %s, Input: %s\n", (char *)arg, buffer);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[10];
    char *thread_args[10];

    for (int i = 0; i < 10; i++) {
        thread_args[i] = malloc(10);
        sprintf(thread_args[i], "Thread %d", i);
        pthread_create(&threads[i], NULL, thread_func, thread_args[i]);
    }

    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
