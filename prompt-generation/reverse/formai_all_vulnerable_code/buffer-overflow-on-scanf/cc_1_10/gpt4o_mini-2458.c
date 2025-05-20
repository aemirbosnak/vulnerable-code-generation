//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: surprised
#include <stdio.h>

// Surprise! We are on a treasure hunt!
void print_intro() {
    printf("🎉 Welcome to the Magical Treasure Hunt! 🎉\n");
    printf("Here, we seek the hidden treasure in a sorted array!\n");
    printf("Let's dive right in and find out what we can discover!\n\n");
}

// A function to perform binary search
int binary_search(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    printf("🔍 Searching for treasure: %d\n", target);
    
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // What do we find in the middle?
        printf("😲 Opening the treasure chest at index %d - found %d!\n", mid, arr[mid]);

        if (arr[mid] == target) {
            printf("🎊 Hooray! Treasure found at index %d! 🎊\n", mid);
            return mid;  // Treasure found!
        } 
        else if (arr[mid] < target) {
            printf("💔 This treasure is too small... we need a bigger one!\n");
            left = mid + 1;  // Search in the right half
        } 
        else {
            printf("🔎 This treasure is too big... let's search to the left!\n");
            right = mid - 1;  // Search in the left half
        }
    }
    
    printf("🕵️‍♂️ Oh no! We couldn't find the treasure... try again next time!\n");
    return -1;  // Treasure not found
}

// A function to display the treasure array
void print_array(int arr[], int size) {
    printf("🏆 Here are all the treasures in the array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}

int main() {
    // Create a sorted array of treasures
    int treasures[] = {2, 7, 11, 15, 20, 24, 33, 56, 85, 99};
    int size = sizeof(treasures) / sizeof(treasures[0]);

    // Call the intro
    print_intro();

    // Print the treasures
    print_array(treasures, size);

    // Get user input for treasure searching
    int target;
    printf("👀 What treasure are you searching for? Enter a number: ");
    scanf("%d", &target);

    // Perform the binary search
    int result = binary_search(treasures, size, target);

    // Final results
    if (result != -1) {
        printf("✅ Your treasure hunt was successful! The treasure is at index %d.\n", result);
    } else {
        printf("😢 Alas! The treasure you seek is not in this realm...\n");
    }

    return 0;
}