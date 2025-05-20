//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000

void create_array(int arr[], int size) {
    int i;
    for(i=0; i<size; i++) {
        arr[i] = rand() % 100;
    }
}

void print_array(int arr[], int size) {
    int i;
    for(i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucket_sort(int arr[], int size) {
    int i, j, k;
    int n = size;
    int *bucket = (int *)malloc(MAX_SIZE * sizeof(int));
    int max_val = arr[0];
    int min_val = arr[0];

    // find max and min values in array
    for(i=1; i<n; i++) {
        if(arr[i] > max_val) {
            max_val = arr[i];
        }
        if(arr[i] < min_val) {
            min_val = arr[i];
        }
    }

    // calculate range and bucket size
    int range = max_val - min_val;
    int bucket_size = range / n;

    // initialize buckets
    for(i=0; i<n; i++) {
        bucket[i] = 0;
    }

    // put elements in buckets
    for(i=0; i<n; i++) {
        j = (arr[i] - min_val) / bucket_size;
        bucket[j]++;
    }

    // sort elements in buckets
    for(i=0; i<n; i++) {
        for(j=0; j<bucket[i]; j++) {
            k = i * bucket_size + j * bucket_size;
            arr[k] = arr[i];
            i++;
        }
    }
}

int main() {
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);

    int arr[size];
    create_array(arr, size);
    print_array(arr, size);

    bucket_sort(arr, size);
    print_array(arr, size);

    return 0;
}