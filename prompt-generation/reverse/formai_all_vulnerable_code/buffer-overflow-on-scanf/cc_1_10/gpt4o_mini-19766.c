//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void printArray(int arr[], int size);
int linearSearch(int arr[], int size, int target);

int main() {
    // Let's begin this odyssey
    int n;
    
    // User asked for size
    printf("Give me the size of the array, brave warrior: ");
    scanf("%d", &n);
    
    // Array declaration, this is the battlefield
    int *array = (int *)malloc(n * sizeof(int));
    
    // Array initialization, filling it with numbers
    printf("Hark! Now enter %d numbers to populate your army of integers:\n", n);
    for(int i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &array[i]);
    }
    
    // The quest begins for a number
    int target;
    printf("Choose your target number to seek: ");
    scanf("%d", &target);
    
    // The search commences
    int index = linearSearch(array, n, target);
    
    // The end of the quest
    if (index != -1) {
        printf("Aha! Your target %d was found at index %d.\n", target, index);
    } else {
        printf("Alas! The number %d is lost in the void.\n", target);
    }
    
    // Freeing the memory, no corpses left behind!
    free(array);
    
    return 0;
}

// Print the array like an artist displaying their masterpiece
void printArray(int arr[], int size) {
    printf("The array consists of: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Our glorious linear search function 
int linearSearch(int arr[], int size, int target) {
    // Adventure begins here
    printf("Searching for the elusive %d...\n", target);
    for(int i = 0; i < size; i++) {
        // Check each mystical element
        if (arr[i] == target) {
            // Victory is sweet, return glory!
            return i; 
        }
    }
    // If we reach here, it means our quest failed, come back empty-handed
    return -1;
}