//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

void generate_random_array(int arr[], int size);
void print_array(int arr[], int size);
int binary_search(int arr[], int size, int target);

int main() {
    int arr[MAX_SIZE];
    int size, target;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array:\n");
    generate_random_array(arr, size);
    print_array(arr, size);

    printf("Enter the target element: ");
    scanf("%d", &target);

    int index = binary_search(arr, size, target);

    if (index == -1) {
        printf("Element not found.\n");
    } else {
        printf("Element found at index %d.\n", index);
    }

    return 0;
}

void generate_random_array(int arr[], int size) {
    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int binary_search(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}