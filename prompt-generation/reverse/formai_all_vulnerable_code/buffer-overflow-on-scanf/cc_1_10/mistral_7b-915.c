//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: protected
#include <stdio.h>
#define MAX_SIZE 50

void bubbleSort(int arr[], int size);
int isValidInput(int *input, int size);
int isValidIndex(int index, int size);

int main() {
    int arr[MAX_SIZE];
    int size, i, isValid;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    if (isValidInput(arr, size) != 1) {
        printf("Invalid input\n");
        return 1;
    }

    printf("Enter %d integers:\n", size);
    for (i = 0; i < size; i++) {
        if (isValidIndex(i, size) != 1) {
            printf("Invalid index\n");
            return 1;
        }
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, size);

    printf("Sorted array: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

void bubbleSort(int arr[], int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int isValidInput(int *input, int size) {
    if (input == NULL || size < 0) {
        return 0;
    }
    return 1;
}

int isValidIndex(int index, int size) {
    if (index < 0 || index >= size) {
        return 0;
    }
    return 1;
}