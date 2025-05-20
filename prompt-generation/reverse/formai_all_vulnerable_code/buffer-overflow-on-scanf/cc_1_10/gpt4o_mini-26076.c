//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void displayArray(int *arr, int size) {
    printf("The treasure map contains the following locations:\n");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

bool linearSearch(int *arr, int size, int key) {
    printf("\nBravely searching through the land with linear search...\n");
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            printf("Treasure found at location %d!\n", i);
            return true;
        }
    }
    printf("Alas! The treasure is not here.\n");
    return false;
}

bool binarySearch(int *arr, int size, int key) {
    int low = 0, high = size - 1;
    printf("\nNavigating the orc-infested woods with binary search...\n");
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            printf("Treasure found at location %d!\n", mid);
            return true;
        }
        if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    printf("The treasure is elusive...not found.\n");
    return false;
}

bool combinationSearch(int *arr, int size, int key) {
    printf("\nCombining forces for a combination search!\n");
    
    // First attempt linear search
    if (linearSearch(arr, size, key)) {
        return true;
    }
    
    // Then attempt binary search on sorted array
    printf("Now we will sort and try binary search...\n");
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    printf("The map is now sorted!\n");
    return binarySearch(arr, size, key);
}

int main() {
    int size, key;

    printf("Welcome to the Great Treasure Hunt!\n");
    printf("How many locations are on your treasure map? ");
    scanf("%d", &size);
    
    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Please enter the locations (integers): \n");
    for (int i = 0; i < size; i++) {
        printf("Location %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    displayArray(arr, size);

    printf("\nWhat location are you searching for? ");
    scanf("%d", &key);

    // Initiate different search methods
    printf("\nSearching using various techniques...\n");
    
    if (!combinationSearch(arr, size, key)) {
        printf("The treasure remains hidden...\n");
    }

    // Clean up
    free(arr);
    printf("Thank you for participating in the Treasure Hunt!\n");
    return 0;
}