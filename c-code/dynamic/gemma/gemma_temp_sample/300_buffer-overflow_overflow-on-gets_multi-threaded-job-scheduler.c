#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <pthread.h>

void* thread_function(void* thread_num) {
    char buffer[10];
    gets(buffer);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[10];
    int i;

    for (i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, thread_function, (void*)i);
    }

    for (i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
