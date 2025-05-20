//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

void mergeSort(int arr[], int l, int r);

int main(void) {
    int arr[MAX_SIZE], n, i;

    printf("Enter the number of elements in the array:\n");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n-1);

    printf("Sorted array: \n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

void mergeSort(int arr[], int l, int r) {
    if(l < r) {
        int m = l + (r-l)/2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        int i, j, k;
        int n1 = m - l + 1;
        int n2 = r - m;

        int L[n1], R[n2];

        for(i = 0; i < n1; i++) {
            L[i] = arr[l + i];
        }
        for(j = 0; j < n2; j++) {
            R[j] = arr[m + 1 + j];
        }

        i = 0;
        j = 0;
        k = l;

        while(i < n1 && j < n2) {
            if(L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while(i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while(j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
}