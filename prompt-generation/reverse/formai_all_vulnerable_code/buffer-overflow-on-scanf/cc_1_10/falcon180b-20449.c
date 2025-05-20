//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_NUMBERS 10000

int numbers[MAX_NUMBERS];
int thread_count;
pthread_t threads[MAX_THREADS];
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *bucket_sort(void *arg) {
    int i, j, k, num;
    int *bucket;

    num = *(int *) arg;
    bucket = malloc(MAX_NUMBERS * sizeof(int));

    for (i = 0; i < MAX_NUMBERS; i++) {
        bucket[i] = 0;
    }

    for (i = 0; i < num; i++) {
        pthread_mutex_lock(&lock);
        for (j = 0; j < MAX_NUMBERS; j++) {
            if (numbers[j] == i) {
                bucket[j]++;
                break;
            }
        }
        pthread_mutex_unlock(&lock);
    }

    for (i = 0, k = 0; i < MAX_NUMBERS; i++) {
        while (bucket[i] > 0) {
            numbers[k++] = i;
            bucket[i]--;
        }
    }

    free(bucket);
    return NULL;
}

int main(int argc, char **argv) {
    int i, num, max, min, sum = 0;
    srand(time(NULL));

    printf("Enter the number of threads: ");
    scanf("%d", &thread_count);

    for (i = 0; i < thread_count; i++) {
        pthread_create(&threads[i], NULL, bucket_sort, (void *) &i);
    }

    for (i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Enter the minimum value: ");
    scanf("%d", &min);
    printf("Enter the maximum value: ");
    scanf("%d", &max);

    for (i = min; i <= max; i++) {
        num = rand() % (max - min + 1) + min;
        numbers[num]++;
        sum += num;
    }

    printf("Sorted array:\n");
    for (i = 0; i < MAX_NUMBERS; i++) {
        while (numbers[i] > 0) {
            printf("%d ", i);
            numbers[i]--;
        }
    }

    printf("\nSum: %d\n", sum);

    return 0;
}