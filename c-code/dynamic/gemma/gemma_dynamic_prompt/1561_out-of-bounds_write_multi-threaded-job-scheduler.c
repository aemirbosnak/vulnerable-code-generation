#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void* thread_function(void* arg) {
    int* shared_ptr = (int*)arg;
    *shared_ptr = 10;
    pthread_exit(NULL);
}

int main() {
    int shared_data = 0;
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, thread_function, &shared_data);
    pthread_join(thread_id, NULL);
    printf("Shared data: %d\n", shared_data);
    return 0;
}
