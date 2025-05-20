//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_NUM_SIZE 32

typedef struct {
    char num[MAX_NUM_SIZE];
    int thread_id;
} ThreadData;

void *convert_binary(void *arg) {
    ThreadData *data = (ThreadData *) arg;
    int thread_id = data->thread_id;
    char *num = data->num;

    printf("Thread %d is converting %s to binary...\n", thread_id, num);
    char binary_num[MAX_NUM_SIZE];
    int len = strlen(num);
    int i;
    for (i = 0; i < len; i++) {
        int n = num[i] - '0';
        sprintf(&binary_num[i * 4], "%04b", n);
    }
    printf("Thread %d has converted %s to binary: %s\n", thread_id, num, binary_num);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[MAX_THREADS];
    int num_threads = 0;
    char input_num[MAX_NUM_SIZE];

    printf("Enter a decimal number to convert to binary (up to %d digits): ", MAX_NUM_SIZE - 1);
    scanf("%s", input_num);

    while (num_threads < MAX_THREADS && input_num[num_threads]!= '\0') {
        ThreadData data;
        strncpy(data.num, input_num + num_threads, MAX_NUM_SIZE - num_threads);
        data.num[MAX_NUM_SIZE - 1] = '\0';
        data.thread_id = num_threads;
        pthread_create(&threads[num_threads], NULL, convert_binary, (void *) &data);
        num_threads++;
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}