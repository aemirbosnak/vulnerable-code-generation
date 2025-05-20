//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_THREADS 10
#define MAX_NUM_SIZE 8

typedef struct {
    char hex[MAX_NUM_SIZE];
    char bin[33];
} number_t;

void *thread_func(void *arg) {
    number_t *num = (number_t *) arg;
    sprintf(num->bin, "%032b", atoi(num->hex));
    return NULL;
}

int main() {
    int num_threads = 0;
    char input[MAX_NUM_SIZE];
    char *token;
    number_t nums[MAX_THREADS];

    printf("Enter a hexadecimal number: ");
    scanf("%s", input);

    token = strtok(input, " ");
    while (token!= NULL) {
        strncpy(nums[num_threads].hex, token, MAX_NUM_SIZE);
        num_threads++;
        token = strtok(NULL, " ");
    }

    pthread_t threads[MAX_THREADS];
    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, thread_func, &nums[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < num_threads; i++) {
        printf("Hex: %s\nBinary: %s\n", nums[i].hex, nums[i].bin);
    }

    return 0;
}