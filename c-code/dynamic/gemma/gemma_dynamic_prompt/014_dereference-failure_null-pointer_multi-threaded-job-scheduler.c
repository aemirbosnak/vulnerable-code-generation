#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_t threads[10];
void* thread_func(void* arg) {
    int i = (int)arg;
    char* ptr = NULL;
    ptr = (char*)malloc(10);
    *ptr = 'a' + i;
    pthread_exit(NULL);
}

int main() {
    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex, NULL);
    for(int i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void*)i);
    }
    for(int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }
    pthread_mutex_destroy(&mutex);
    return 0;
}
