//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 100
#define ELEMENT_RANGE 1000

void generateRandomNumbers(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % ELEMENT_RANGE;
    }
}

void displayArray(int arr[], int n) {
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; // return the index if found
        }
    }
    return -1; // return -1 if not found
}

int main() {
    srand(time(NULL));  // Seed the random number generator
    
    // The maze is created here, with unknown treasures inside.
    int arr[MAX_ELEMENTS];
    int numberOfElements = (rand() % (MAX_ELEMENTS - 1)) + 2; // Generate at least 2 elements
    generateRandomNumbers(arr, numberOfElements);
    
    // Treasures hidden within the labyrinth are displayed for the seeker.
    displayArray(arr, numberOfElements);
    
    int key;
    printf("Enter the treasure number you seek (0 to %d): ", ELEMENT_RANGE - 1);
    scanf("%d", &key);
    
    // The seeker embarks on the search for the treasure they desire.
    int result = linearSearch(arr, numberOfElements, key);
    
    // The treasure hunt is revealed as follows:
    if (result != -1) {
        printf("Treasure found at index: %d\n", result);
    } else {
        printf("Alas! The treasure you seek is not here in this maze.\n");
    }
    
    // Additional challenge: attempt to discover if the treasure was nearby.
    if (result > 0) {
        printf("Perhaps the treasure is near index %d with value %d.\n", result - 1, arr[result - 1]);
    }
    if (result < numberOfElements - 1) {
        printf("Or maybe it’s just around the corner at index %d with value %d.\n", result + 1, arr[result + 1]);
    }
    
    // Quest continues at the creator's discretion!
    printf("Would you like to search for another treasure? (1 for Yes, 0 for No): ");
    int continueSearch;
    scanf("%d", &continueSearch);
    
    while (continueSearch) {
        printf("Enter the treasure number you seek (0 to %d): ", ELEMENT_RANGE - 1);
        scanf("%d", &key);
        
        result = linearSearch(arr, numberOfElements, key);
        
        if (result != -1) {
            printf("Treasure found at index: %d\n", result);
        } else {
            printf("Alas! The treasure you seek is not here in this maze.\n");
        }
        
        if (result > 0) {
            printf("Perhaps the treasure is near index %d with value %d.\n", result - 1, arr[result - 1]);
        }
        if (result < numberOfElements - 1) {
            printf("Or maybe it’s just around the corner at index %d with value %d.\n", result + 1, arr[result + 1]);
        }
        
        printf("Would you like to search for another treasure? (1 for Yes, 0 for No): ");
        scanf("%d", &continueSearch);
    }
    
    printf("The journey ends here, treasure seeker. Until next time!\n");
    return 0;
}