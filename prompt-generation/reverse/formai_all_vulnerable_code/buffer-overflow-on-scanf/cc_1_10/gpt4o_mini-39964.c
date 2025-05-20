//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // For sleep()
#include <string.h>

#define SIZE 10  // Size of the array
#define DELAY 500000 // Delay in microseconds

// Function to display a shape
void display_shape(const char* shape) {
    printf("\r%s", shape);
    fflush(stdout);
}

// Function for Linear Search
int linear_search(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        // Displaying shapes
        display_shape("🔴 Searching...");
        usleep(DELAY);
        
        if (arr[i] == target) {
            display_shape("🟢 Found!");
            usleep(DELAY);
            return i; // Return the index where the target is found
        }
        
        // Indicating the current index being searched
        if (i % 3 == 0)
            display_shape("🔵 Looking...");
        else if (i % 3 == 1)
            display_shape("🟡 Checking...");
        else
            display_shape("🟣 Still searching...");
        
        usleep(DELAY);
    }
    display_shape("🔴 Not found!");
    return -1; // Target not found
}

int main() {
    int array[SIZE] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int target;
  
    printf("Array: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
  
    printf("Enter number to search: ");
    scanf("%d", &target);
  
    int result = linear_search(array, SIZE, target);
  
    if (result != -1) {
        printf("\nTarget %d found at index: %d\n", target, result);
    } else {
        printf("\nTarget %d not found in the array.\n", target);
    }
    
    // Final cleanup of shapes
    display_shape("\n✨ Search Complete!\n");
    return 0;
}