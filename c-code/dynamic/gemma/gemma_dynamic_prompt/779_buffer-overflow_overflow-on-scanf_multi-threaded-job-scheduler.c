#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <string.h>

void* thread_function(void* arg) {
    char buffer[1024];
    scanf("%s", buffer);
    printf("Thread: %s, Buffer: %s\n", (int)arg, buffer);
    return NULL;
}

int main() {
    pthread_t threads[10];
    char* arguments[10] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};

    for (int i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, thread_function, (void*)arguments[i]);
    }

    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
