//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: multi-threaded
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define MAX 100

int arr[MAX];
int n;

void *search(void *arg)
{
    int i, start, end, *result = (int *)malloc(sizeof(int));

    start = *(int *)arg;
    end = start + n/2;

    for(i=start; i<=end; i++)
    {
        if(arr[i] == *(int *)arg)
        {
            *result = i;
            pthread_exit(result);
        }
    }

    pthread_exit(NULL);
}

int main()
{
    int i, sum=0, *result;
    pthread_t thread_id[MAX];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    printf("Enter the element to search: ");
    scanf("%d", &arr[n]);

    for(i=0; i<n; i++)
    {
        pthread_create(&thread_id[i], NULL, search, (void *)&arr[i]);
    }

    for(i=0; i<n; i++)
    {
        pthread_join(thread_id[i], (void **)&result);
        if(*result!= -1)
        {
            printf("Element found at position %d\n", *result);
        }
        else
        {
            printf("Element not found\n");
        }
    }

    printf("Sum of elements: %d\n", sum);

    return 0;
}