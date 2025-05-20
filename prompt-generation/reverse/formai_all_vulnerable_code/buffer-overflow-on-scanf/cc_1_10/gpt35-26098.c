//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

// C Performance-Critical Component Example Program 

void merge(int arr[], int l, int m, int r)
{
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
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
  
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
  
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
  
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
  
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
  
        merge(arr, l, m, r);
    }
}

int main() {
    int arr[MAX_SIZE];
    int n, i;
    clock_t t1, t2, total;
    double time_taken;

    printf("Enter size of array: ");
    scanf("%d", &n);

    // Generate an array with random numbers
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        arr[i] = rand();
    }

    // Time the merge sort algorithm
    t1 = clock();
    mergeSort(arr, 0, n - 1);
    t2 = clock();

    // Calculate the total time taken
    total = t2 - t1;

    // Convert clock cycles to time taken in seconds
    time_taken = (double)total / CLOCKS_PER_SEC;

    printf("\nArray sorted using Merge Sort!");
    printf("\nTime taken: %f seconds", time_taken);

    return 0;
}