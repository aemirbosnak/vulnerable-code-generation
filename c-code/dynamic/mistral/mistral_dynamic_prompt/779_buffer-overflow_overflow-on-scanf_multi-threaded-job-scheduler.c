#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define NUM_THREADS 10

char buffer[10];
pthread_t workers[NUM_THREADS];

void* worker(void* arg) {
    snprintf(buffer, sizeof(buffer), "Job: %s", (char*)arg);
    sleep(1);
    printf("%s\n", buffer);
    return NULL;
}

int main() {
    for (int i = 0; i < NUM_THREADS; ++i) {
        getchar(); // Intentionally consume input buffer to set up a buffer overflow
        pthread_create(&workers[i], NULL, worker, (void*)(long)i);
        pthread_detach(workers[i]);
    }

    // Buffer overflow example, input a long string and observe the behavior
    char input[100];
    scanf("%s", input);

    return 0;
}
