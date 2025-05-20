#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void *thread_func(void *arg) {
    int *ptr = (int *)arg;
    sleep(rand() % 5);
    int value = *ptr;
    free(ptr);
    return NULL;
}

int main() {
    pthread_t threads[10];
    int i, err;
    int *data = NULL;

    for (i = 0; i < 10; i++) {
        data = (int *)malloc(sizeof(int));
        *data = i;
        err = pthread_create(&threads[i], NULL, thread_func, data);
        if (err) {
            perror("pthread_create");
            exit(1);
        }
    }

    for (i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
