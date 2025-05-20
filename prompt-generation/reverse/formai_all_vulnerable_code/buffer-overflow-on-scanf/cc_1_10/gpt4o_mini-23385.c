//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: automated
#include <stdio.h>
#include <stdlib.h>

void linearSearch(int arr[], int size, int target);
void binarySearch(int arr[], int size, int target);
int compare(const void *a, const void *b);

int main() {
    int choice, size, target;
    
    printf("Welcome to the Search Algorithm Program!\n");
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);
    
    int *arr = (int*)malloc(size * sizeof(int));
    
    printf("Enter the elements of the array:\n");
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nChoose a search algorithm:\n");
    printf("1. Linear Search\n");
    printf("2. Binary Search\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    
    printf("Enter the target value to search: ");
    scanf("%d", &target);
    
    switch (choice) {
        case 1:
            linearSearch(arr, size, target);
            break;

        case 2:
            qsort(arr, size, sizeof(int), compare);
            binarySearch(arr, size, target);
            break;

        default:
            printf("Invalid choice. Please run the program again.\n");
            break;
    }
    
    free(arr);
    return 0;
}

void linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            printf("Linear Search: Element %d found at index %d.\n", target, i);
            return;
        }
    }
    printf("Linear Search: Element %d not found in the array.\n", target);
}

void binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1, mid;
    
    while (left <= right) {
        mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            printf("Binary Search: Element %d found at index %d.\n", target, mid);
            return;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    printf("Binary Search: Element %d not found in the array.\n", target);
}

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}