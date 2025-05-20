//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: curious
#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int size) {
    printf("Treasure map:\n");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        printf("Searching in the range [%d, %d], Middle gem: %d\n", left, right, arr[mid]);

        if (arr[mid] == target) {
            printf("Found the gem %d at position %d!\n", target, mid);
            return mid;
        }

        if (arr[mid] < target) {
            left = mid + 1; // Move right
        } else {
            right = mid - 1; // Move left
        }
    }
    
    printf("Alas! The gem %d is not found in the treasure map.\n", target);
    return -1; // Not found
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    // Magical array of treasures (unsorted)
    int treasures[] = {38, 15, 29, 47, 5, 92, 73};
    int size = sizeof(treasures)/sizeof(treasures[0]);

    printf("Before sorting:\n");
    printArray(treasures, size);

    // Sorting the treasures to make the search easier
    qsort(treasures, size, sizeof(int), compare);

    printf("After sorting:\n");
    printArray(treasures, size);

    // The valued gem we are in search of
    int targetGem;
    printf("Enter the value of the gem you seek: ");
    scanf("%d", &targetGem);

    // The hunt begins!
    int result = binarySearch(treasures, size, targetGem);

    // End of the quest
    if (result != -1) {
        printf("The quest was successful! You found the gem at position %d.\n", result);
    } else {
        printf("The quest ended in failure. Try searching for another gem!\n");
    }

    return 0;
}