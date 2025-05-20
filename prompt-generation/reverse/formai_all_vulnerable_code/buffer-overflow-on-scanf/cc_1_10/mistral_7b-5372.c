//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

void binary_search(int arr[], int low, int high, int x, int *result);
void print_error_message(int error_code);

int main() {
    int arr[ARRAY_SIZE] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int x, result;

    printf("Welcome to the Binary Search Algorithm!\n");
    printf("Please enter the number you want to search for: ");
    scanf("%d", &x);

    binary_search(arr, 0, ARRAY_SIZE - 1, x, &result);

    if (result == -1) {
        printf("\nError: Invalid input! The array must be sorted.\n");
    } else if (result == -2) {
        print_error_message(result);
    } else {
        printf("\nElement %d found at index %d.\n", x, result);
    }

    return 0;
}

void binary_search(int arr[], int low, int high, int x, int *result) {
    if (high >= low) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x) {
            *result = mid;
            return;
        }

        if (arr[mid] < x) {
            binary_search(arr, mid + 1, high, x, result);
        } else {
            binary_search(arr, low, mid - 1, x, result);
        }
    } else {
        *result = -1;
        print_error_message(-3);
    }
}

void print_error_message(int error_code) {
    switch (error_code) {
        case -1:
            printf("\nError: The input number is not an integer.\n");
            break;
        case -2:
            printf("\nError: The input array is not sorted.\n");
            break;
        case -3:
            printf("\nError: The array is empty.\n");
            break;
        default:
            printf("\nError: Unknown error occurred.\n");
            break;
    }
}