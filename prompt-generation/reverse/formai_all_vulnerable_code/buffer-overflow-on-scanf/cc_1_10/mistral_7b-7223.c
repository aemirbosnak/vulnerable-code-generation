//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void cheerfulBubbleSort(int arr[], int size) {
    int i, j, flag;
    for (i = 0; i < size - 1; i++) {
        printf("Round %d: \n", i + 1);
        for (j = 0; j < size - i - 1; j++) {
            printf("Comparing %d and %d... \n", arr[j], arr[j + 1]);
            if (arr[j] > arr[j + 1]) {
                printf("Swapping... \n");
                swap(&arr[j], &arr[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0) {
            printf("Hurray! The array is already sorted! \n");
            break;
        } else {
            flag = 0;
        }
        printArray(arr, size);
    }
}

int main() {
    int arr[MAX];
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter %d integers: \n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    cheerfulBubbleSort(arr, size);

    return 0;
}