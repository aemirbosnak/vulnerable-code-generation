//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: genius
#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

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
        } else {
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

    free(L);
    free(R);
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        printf("Dividing: ");
        for (int i = l; i <= r; i++)
            printf("%d ", arr[i]);
        printf("\n");

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);

        printf("Merging: ");
        for (int i = l; i <= r; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
}

void printArray(int arr[], int size) {
    printf("Sorted Array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;
    
    printf("Adventurer, how many integers shall we sort? ");
    scanf("%d", &n);
    
    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Embarking on the journey of sorting...\n");
    
    mergeSort(arr, 0, n - 1);
    
    printArray(arr, n);

    free(arr);
    
    printf("The adventure of sorting has concluded!\n");
    return 0;
}