//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 1000000
#define MAX_RANGE 1000000

int main() {
    int i, j, n;
    int *arr;
    float *buckets;
    int *sorted_arr;
    clock_t start, end;
    double cpu_time_used;
    srand(time(NULL));

    //initialize array
    arr = (int*)malloc(MAX_SIZE * sizeof(int));
    for(i=0; i<MAX_SIZE; i++){
        arr[i] = rand() % MAX_RANGE;
    }

    //initialize buckets
    buckets = (float*)malloc(MAX_RANGE * sizeof(float));
    for(i=0; i<MAX_RANGE; i++){
        buckets[i] = 0.0;
    }

    //initialize sorted array
    sorted_arr = (int*)malloc(MAX_SIZE * sizeof(int));

    //distribute elements into buckets
    for(i=0; i<MAX_SIZE; i++){
        int index = (int)(arr[i] / MAX_RANGE * MAX_RANGE);
        buckets[index]++;
    }

    //rearrange elements in ascending order
    for(i=0; i<MAX_RANGE; i++){
        for(j=0; j<buckets[i]; j++){
            sorted_arr[j] = i * MAX_RANGE;
            j++;
        }
    }

    //copy sorted elements back to original array
    for(i=0; i<MAX_SIZE; i++){
        arr[i] = sorted_arr[i];
    }

    //print sorted array
    printf("Sorted array:\n");
    for(i=0; i<MAX_SIZE; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    //measure cpu time
    start = clock();
    for(i=0; i<MAX_SIZE; i++){
        int index = (int)(arr[i] / MAX_RANGE * MAX_RANGE);
        buckets[index]++;
    }
    for(i=0; i<MAX_RANGE; i++){
        for(j=0; j<buckets[i]; j++){
            sorted_arr[j] = i * MAX_RANGE;
            j++;
        }
    }
    for(i=0; i<MAX_SIZE; i++){
        arr[i] = sorted_arr[i];
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("CPU time used: %lf seconds\n", cpu_time_used);

    return 0;
}