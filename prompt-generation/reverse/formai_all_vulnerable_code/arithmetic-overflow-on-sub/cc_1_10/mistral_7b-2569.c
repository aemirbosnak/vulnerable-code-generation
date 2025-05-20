//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: automated
#include <stdio.h>

#define MAX_SIZE 100

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[MAX_SIZE], i, n, flag;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);

    printf("\nSorted array: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    flag = 1;

    for (i = 0; i < n - 1; i++) {
        if (arr[i] != arr[i + 1]) {
            flag = 0;
            break;
        }
    }

    if (flag) {
        printf("\nArray is already sorted.\n");
    }

    return 0;
}