#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_t threads[10];
int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

void *thread_func(void *arg) {
    int i = (int)arg;
    arr[i] = 10;
    printf("Thread %d: Finished\n", i);
    pthread_exit(NULL);
}

int main() {
    pthread_t t_id;
    for (int i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void *)i);
    }

    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Main: Finished\n");
    return 0;
}
