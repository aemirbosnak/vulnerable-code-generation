#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdlib.h>

pthread_t threads[10];
void* thread_function(void* thread_id) {
    int* ptr = (int*)pthread_getspecific(thread_id);
    free(ptr);
    return NULL;
}

int main() {
    for(int i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, thread_function, (void*)i);
    }

    for(int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
