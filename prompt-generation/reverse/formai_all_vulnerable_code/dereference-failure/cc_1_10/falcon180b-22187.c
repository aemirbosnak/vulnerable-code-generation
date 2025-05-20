//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

void print_array(int arr[], int n) {
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void shuffle_array(int arr[], int n) {
    srand(time(0));
    for(int i=0; i<n; i++) {
        int j = rand() % n;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void bucket_sort(int arr[], int n) {
    int max = arr[0];
    int min = arr[0];
    for(int i=1; i<n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
        if(arr[i] < min) {
            min = arr[i];
        }
    }
    int range = max - min + 1;
    int *bucket = (int *)malloc(range * sizeof(int));
    for(int i=0; i<range; i++) {
        bucket[i] = 0;
    }
    for(int i=0; i<n; i++) {
        int index = (arr[i] - min) / (max - min) * range;
        bucket[index]++;
    }
    int j = 0;
    for(int i=0; i<range; i++) {
        while(bucket[i]-- > 0) {
            arr[j++] = i * (max - min) / range + min;
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[MAX_SIZE];
    printf("Enter the elements of the array:\n");
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    shuffle_array(arr, n);
    print_array(arr, n);
    bucket_sort(arr, n);
    printf("Sorted array using Bucket Sort:\n");
    print_array(arr, n);
    return 0;
}