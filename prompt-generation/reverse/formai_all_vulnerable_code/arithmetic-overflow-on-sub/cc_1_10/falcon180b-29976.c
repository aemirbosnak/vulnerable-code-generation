//Falcon-180B DATASET v1.0 Category: Digital Auction System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// function to partition the array
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// function to perform quick sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// function to perform auction
void auction(int arr[], int n, int m) {
    printf("\nAuction starts...\n");
    int i = 0;
    while (i < n) {
        printf("\nCurrent bid: %d\n", arr[i]);
        int bid = 0;
        while (bid <= m) {
            printf("Enter your bid: ");
            scanf("%d", &bid);
            if (bid > m) {
                printf("Invalid bid. Try again.\n");
            }
        }
        if (bid > 0) {
            m -= bid;
            printf("\nItem sold for %d\n", bid);
            i++;
        } else {
            printf("\nNo bids. Moving to next item.\n");
            i++;
        }
    }
}

// main function
int main() {
    int n, m;
    printf("Enter number of items: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter maximum bid: ");
    scanf("%d", &m);

    quickSort(arr, 0, n - 1);

    auction(arr, n, m);

    return 0;
}