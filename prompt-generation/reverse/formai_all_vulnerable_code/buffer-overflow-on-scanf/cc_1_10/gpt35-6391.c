//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#define NUM_THREADS 4

int *arr1, *result;
int n, range;

void *bucket_sort(void *tid)
{
    int i, j, k;
    int t_num = *(int *)tid;
    int start = t_num * (n / NUM_THREADS);
    int end = start + (n / NUM_THREADS);

    int *bucket = (int *)calloc(range, sizeof(int));
    for (i = start; i < end; i++)
        bucket[arr1[i]]++;
    for (i = 1; i < range; i++)
        bucket[i] += bucket[i - 1];
    for (i = end - 1; i >= start; i--)
    {
        j = arr1[i];
        result[--bucket[j]] = j;
    }

    free(bucket);
    pthread_exit(NULL);
}

int main()
{
    int i;
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    printf("Enter number of elements: ");
    scanf("%d", &n);
    arr1 = (int *)calloc(n, sizeof(int));
    result = (int *)calloc(n, sizeof(int));

    printf("Enter maximum element value: ");
    scanf("%d", &range);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr1[i]);

    for (i = 0; i < NUM_THREADS; i++)
    {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, bucket_sort, (void *)&thread_ids[i]);
    }

    for (i = 0; i < NUM_THREADS; i++)
        pthread_join(threads[i], NULL);

    printf("\nSorted elements:\n");
    for (i = 0; i < n; i++)
        printf("%d ", result[i]);

    free(arr1);
    free(result);
    return 0;
}