//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX 100

int arr[MAX];

sem_t mutex;

void init_mutex()
{
    int ret;
    ret = sem_init(&mutex, 0, 1);
    if(ret!= 0)
    {
        printf("Error in initializing Mutex\n");
        exit(0);
    }
}

void *fill_array(void *arg)
{
    int i, n = *((int *) arg);
    for(i=0; i<n; i++)
    {
        arr[i] = i;
    }
    return NULL;
}

void *sum_array(void *arg)
{
    int i, n = *((int *) arg);
    int sum = 0;
    for(i=0; i<n; i++)
    {
        sum += arr[i];
    }
    printf("The sum of array elements is %d\n", sum);
    return NULL;
}

int main()
{
    int i, n, sum;
    pthread_t threads[2];

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    init_mutex();

    for(i=0; i<n; i++)
    {
        arr[i] = 0;
    }

    pthread_create(&threads[0], NULL, fill_array, (void *)&n);
    pthread_create(&threads[1], NULL, sum_array, (void *)&n);

    for(i=0; i<2; i++)
    {
        pthread_join(threads[i], NULL);
    }

    return 0;
}