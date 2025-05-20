//FormAI DATASET v1.0 Category: Benchmarking ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100000

void insertionSort(int arr[], int n){
    int i, key, j;
    for (i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }
}

void merge(int arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r){
    if (l < r){
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main(){
    int arr[MAX_SIZE];
    int n, i;

    srand(time(0)); // seeding the random function with current time

    printf("Enter the number of elements:\n");
    scanf("%d", &n);

    printf("Randomly generated array:\n");

    for (i = 0; i < n; i++){
        arr[i] = rand() % 1000;
        printf("%d ", arr[i]);
    }

    printf("\n");

    clock_t t;
    t = clock(); // starting the clock for insertion sort
    insertionSort(arr, n);
    t = clock() - t; // stopping the clock and calculating the time taken

    printf("Array sorted using Insertion Sort:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\nTime taken by Insertion Sort: %lf seconds\n", ((double)t) / CLOCKS_PER_SEC);

    t = clock(); // starting the clock for merge sort
    mergeSort(arr, 0, n - 1);
    t = clock() - t; // stopping the clock and calculating the time taken

    printf("Array sorted using Merge Sort:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\nTime taken by Merge Sort: %lf seconds\n", ((double)t) / CLOCKS_PER_SEC);

    return 0;
}