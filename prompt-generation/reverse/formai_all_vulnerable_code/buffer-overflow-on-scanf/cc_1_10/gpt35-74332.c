//FormAI DATASET v1.0 Category: Sorting ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
 
    /* create temp arrays */
    int *L = (int*) malloc(n1 * sizeof(int));
    int *R = (int*) malloc(n2 * sizeof(int));
 
    /* copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
 
    /* merge the temp arrays back into arr[left..right]*/
    i = 0;
    j = 0;
    k = left; // initial index of merged subarray
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
 
    /* copy the remaining elements of L[], if there are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* copy the remaining elements of R[], if there are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    /* free up memory used by temp arrays */
    free(L);
    free(R);
}
 
 
void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
 
 
int main() {
    int i, n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
 
    /* allocate memory dynamically */
    int *arr = (int*) malloc(n * sizeof(int));

    /* generate random integers and store in array */
    srand(time(NULL));
    for (i = 0; i < n; i++)
        arr[i] = rand() % 100;
 
    printf("\nUnsorted array: \n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
 
    merge_sort(arr, 0, n - 1); // sort the array
 
    printf("\nSorted array: \n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
 
    /* free up memory used by array */
    free(arr);
 
    return 0;
}