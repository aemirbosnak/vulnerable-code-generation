//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

int arr[100];
int n;
int part;

void *runner(void *param);

int main(int argc, char **argv) {
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the element to search for: ");
    scanf("%d", &part);

    int i;
    for(i=0;i<n;i++) {
        arr[i] = i+1;
    }

    pthread_t threads[NUM_THREADS];

    int range = n/NUM_THREADS;

    int start, end;

    for(i=0;i<NUM_THREADS;i++) {
        start = i*range;
        end = (i==NUM_THREADS-1)? n-1 : start + range - 1;
        pthread_create(&threads[i], NULL, runner, (void *)&start);
    }

    for(i=0;i<NUM_THREADS;i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

void *runner(void *param) {
    int start = *((int *)param);
    int end = start + 25;

    int found = 0;

    for(int i=start;i<=end;i++) {
        if(arr[i] == part) {
            found = 1;
            break;
        }
    }

    if(found) {
        printf("Element found at index %d\n", start);
    } else {
        printf("Element not found\n");
    }

    return NULL;
}