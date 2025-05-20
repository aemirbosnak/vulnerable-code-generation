//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 1000
#define MAX_THREADS 10

char buffer[BUFFER_SIZE];
sem_t mutex;

void* convert_binary(void* arg) {
    char* input = (char*) arg;
    int decimal = 0;
    int i = 0;
    int j = strlen(input) - 1;

    while (i <= j) {
        if (input[i] == '1') {
            decimal += pow(2, j - i);
        }
        i++;
    }

    sprintf(buffer + strlen(buffer), "Binary: %s Decimal: %d\n", input, decimal);

    return NULL;
}

int main() {
    sem_init(&mutex, 0, 1);

    pthread_t threads[MAX_THREADS];
    int count = 0;

    while (count < MAX_THREADS) {
        char input[100];
        printf("Enter a binary number: ");
        scanf("%s", input);

        pthread_create(&threads[count], NULL, convert_binary, input);
        count++;

        sleep(1);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("\n%s", buffer);

    sem_destroy(&mutex);
    return 0;
}