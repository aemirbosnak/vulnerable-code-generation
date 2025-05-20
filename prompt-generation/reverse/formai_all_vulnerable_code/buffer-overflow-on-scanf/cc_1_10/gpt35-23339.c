//FormAI DATASET v1.0 Category: Sorting ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

/* Function to display array elements */
void display(int arr[], int n) {
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/* Merge Function */
void merge(int arr[],int l,int m,int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    /* Merge the temp arrays back long_array [l..r]*/
    i = 0; // Initial index of first or left subarray 
    j = 0; // Initial index of second or right subarray 
    k = l; // Initial index of merged subarray 
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
 
    /* Copy the remaining left or first subarray */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining right or second subarray */
    while (j < n2)  {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* Merge Sort Function */
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int n;
    printf("Enter the size of the array:");
    scanf("%d",&n);

    int arr[n];
    printf("Enter the elements:");
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Elements before sorting: ");
    display(arr, n);
    printf("\n");

    /* Merge Sort */
    mergeSort(arr, 0, n-1);

    printf("Elements after sorting: ");
    display(arr, n);

    return 0;
}