#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <pthread.h>

void *thread_func(void *arg) {
    char buffer[10];
    scanf("%s", buffer);
    printf("Thread: %s\n", buffer);
    pthread_exit(NULL);
}

int main() {
    pthread_t t[10];
    for (int i = 0; i < 10; i++) {
        pthread_create(&t[i], NULL, thread_func, NULL);
    }
    for (int i = 0; i < 10; i++) {
        pthread_join(t[i], NULL);
    }
    return 0;
}
