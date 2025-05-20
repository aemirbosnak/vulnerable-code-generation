//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ARRAY_SIZE 1000000

void generate_random_array(int *arr, int size){
    /* Generates an array of random integers */
    int i;
    srand(time(NULL));
    for(i=0; i<size; i++){
        arr[i] = rand();
    }
}

void insertion_sort(int *arr, int size){
    /* Insertion sort algorithm */
    int i, j, tmp;
    for(i=1; i<size; i++){
        j = i;
        while(j>0 && arr[j]<arr[j-1]){
            tmp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = tmp;
            j--;
        }
    }
}

int main(){
    int arr[MAX_ARRAY_SIZE], size;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter size of array: ");
    scanf("%d", &size);

    if(size <= 0 || size > MAX_ARRAY_SIZE){
        printf("Invalid array size!\n");
        return 1;
    }

    generate_random_array(arr, size);

    printf("Sorting...\n");

    start = clock(); // start timer
    insertion_sort(arr, size);
    end = clock(); // end timer

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Sorted %d elements in %f seconds\n", size, cpu_time_used);

    return 0;
}