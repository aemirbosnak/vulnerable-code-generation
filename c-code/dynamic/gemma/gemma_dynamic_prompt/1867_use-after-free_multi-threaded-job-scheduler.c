#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *thread_function(void *thread_id) {
    printf("Hello, world! Thread ID: %ld\n", (long)thread_id);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[5];
    int i;

    for (i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, thread_function, (void *)i);
    }

    for (i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
