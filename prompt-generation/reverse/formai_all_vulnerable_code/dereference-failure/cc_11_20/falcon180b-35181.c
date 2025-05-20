//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 10000

int main()
{
    int i, j, n;
    double *array, max, min;
    clock_t start, end;
    double cpu_time_used;

    //initialize random seed
    srand(time(NULL));

    //initialize array
    array = (double*) malloc(SIZE * sizeof(double));
    for(i=0; i<SIZE; i++)
    {
        array[i] = rand() % 1000;
    }

    //find maximum and minimum values
    max = array[0];
    min = array[0];
    for(i=1; i<SIZE; i++)
    {
        if(array[i] > max)
        {
            max = array[i];
        }
        else if(array[i] < min)
        {
            min = array[i];
        }
    }

    //bucket sort
    int *bucket = (int*) malloc(SIZE * sizeof(int));
    for(i=0; i<SIZE; i++)
    {
        bucket[i] = 0;
    }

    for(i=0; i<SIZE; i++)
    {
        j = (int) ((array[i] - min) * SIZE / (max - min));
        bucket[j]++;
    }

    for(i=0; i<SIZE; i++)
    {
        j = (int) ((array[i] - min) * SIZE / (max - min));
        for(n=0; n<bucket[j]; n++)
        {
            array[i+n] = array[i];
        }
    }

    //free memory
    free(bucket);

    //measure cpu time used
    start = clock();
    for(i=0; i<SIZE; i++)
    {
        for(j=0; j<SIZE; j++)
        {
            if(array[i] == array[j])
            {
                printf("%d ", array[i]);
            }
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n");
    printf("CPU time used: %.6f seconds\n", cpu_time_used);

    return 0;
}