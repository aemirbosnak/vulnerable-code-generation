//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int main() {
    int arr[MAX_SIZE], i, num;

    printf("Enter the number of elements to be entered in the array: ");
    if (scanf("%d", &num) != 1) {
        fprintf(stderr, "Invalid input. Please enter an integer.\n");
        return 1;
    }

    if (num > MAX_SIZE) {
        fprintf(stderr, "Array size overflow. Maximum size is %d.\n", MAX_SIZE);
        return 1;
    }

    printf("Enter %d integers:\n", num);

    for (i = 0; i < num; i++) {
        printf("Enter element %d: ", i + 1);
        if (scanf("%d", &arr[i]) != 1) {
            fprintf(stderr, "Invalid input. Please enter an integer.\n");
            return 1;
        }
    }

    printf("\nElements in the array:\n");
    for (i = 0; i < num; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nSum of the elements in the array: %d\n", sumArray(arr, num));

    return 0;
}

int sumArray(int arr[], int size) {
    int sum = 0;
    if (arr == NULL || size <= 0) {
        fprintf(stderr, "Error: Invalid input. Array or size is not valid.\n");
        return -1;
    }

    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    return sum;
}