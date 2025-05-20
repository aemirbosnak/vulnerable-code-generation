#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <string.h>

void *thread_func(void *arg) {
    char buffer[1024];
    fscanf(stdin, "%s", buffer);
    printf("Thread: %s, Input: %s\n", (int)arg, buffer);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[10];
    for (int i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void *)i);
    }
    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}
