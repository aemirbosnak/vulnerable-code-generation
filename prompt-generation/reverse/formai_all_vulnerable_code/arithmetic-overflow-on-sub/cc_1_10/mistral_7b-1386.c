//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }

    return -1;
}

int linearSearch(int arr[], int size, int x) {
    int i;

    for (i = 0; i < size; i++) {
        if (arr[i] == x)
            return i;
    }

    return -1;
}

int main() {
    int arr[MAX], n, key, choice, i;

    printf("Enter the number of elements : ");
    scanf("%d", &n);

    printf("Enter %d integers : ", n);

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\n1. Linear Search\n");
        printf("2. Binary Search\n");
        printf("3. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the key to search : ");
                scanf("%d", &key);
                int pos = linearSearch(arr, n, key);
                if (pos == -1)
                    printf("Element not present in array\n");
                else
                    printf("Element found at position %d\n", pos + 1);
                break;
            case 2:
                printf("Enter the key to search : ");
                scanf("%d", &key);
                int result = binarySearch(arr, 0, n - 1, key);
                if (result == -1)
                    printf("Element not present in array\n");
                else
                    printf("Element found at position %d\n", result + 1);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 3);

    return 0;
}