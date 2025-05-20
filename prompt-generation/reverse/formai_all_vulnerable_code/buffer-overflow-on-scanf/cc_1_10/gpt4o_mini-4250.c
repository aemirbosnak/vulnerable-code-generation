//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void printArray(int arr[], int size) {
    printf("Current array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            printf("Target %d found at index %d! 😱\n", target, i);
            return i;
        }
    }
    printf("Oh no! Target %d not found in the array! 😢\n", target);
    return -1;
}

int binarySearch(int arr[], int left, int right, int target) {
    printf("Searching between indices %d and %d...😅\n", left, right);
    if (right >= left) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            printf("Target %d found at index %d! 🎉\n", target, mid);
            return mid;
        }
        
        if (arr[mid] > target) {
            return binarySearch(arr, left, mid - 1, target);
        }
        
        return binarySearch(arr, mid + 1, right, target);
    }
    
    printf("Oops! Target %d is not in the array! 😱😱\n", target);
    return -1;
}

void sortArray(int arr[], int size) {
    printf("Sorting the array... 🧐\n");
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                printf("Swapped %d and %d! 😯\n", arr[j + 1], arr[j]);
            }
        }
    }
    printf("Array sorted! Here it is now: \n");
    printArray(arr, size);
}

int main() {
    int arr[MAX_SIZE];
    int size, choice, target;

    printf("Welcome to the Shocked Search Program! 🌟\n");
    printf("Enter the number of elements in the array (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    if(size < 1 || size > MAX_SIZE) {
        printf("Invalid size! Please try again. 📉\n");
        return -1;
    }

    printf("Please enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printArray(arr, size);

    printf("Choose a search method:\n");
    printf("1. Linear Search\n");
    printf("2. Binary Search (Array needs to be sorted)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter the target value to search for: ");
    scanf("%d", &target);

    if (choice == 1) {
        linearSearch(arr, size, target);
    } else if (choice == 2) {
        printf("Sorting array for binary search! 📈\n");
        sortArray(arr, size);
        binarySearch(arr, 0, size - 1, target);
    } else {
        printf("Invalid choice! Please restart the program. 🥺\n");
    }

    printf("Thank you for using the Shocked Search Program! Goodbye! 💔\n");
    return 0;
}