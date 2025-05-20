//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: unmistakable
#include <stdio.h>

// Function to perform binary search in the enchanted forest
int binarySearch(int arr[], int left, int right, int target) {
    // Checking if the enchanted forest range is valid
    while (left <= right) {
        // Casting a spell to find the middle point
        int mid = left + (right - left) / 2;

        // If the magical number is found!
        if (arr[mid] == target) {
            return mid;
        }
        // If the magical number is greater, search the right side
        if (arr[mid] < target) {
            left = mid + 1;
        }
        // Otherwise, search the left side
        else {
            right = mid - 1;
        }
    }
    // The magical number is lost in the forest!
    return -1;
}

// Function to display the enchanted forest (the array)
void displayForest(int arr[], int size) {
    printf("🌳 The Enchanted Forest of Magical Numbers: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function where the magic begins
int main() {
    // The sorted mystical numbers residing in the forest
    int enchantedForest[] = {1, 3, 7, 8, 12, 14, 19, 25, 30, 42, 55, 78, 89, 99};
    int size = sizeof(enchantedForest) / sizeof(enchantedForest[0]);
    
    // Display the enchanted forest
    displayForest(enchantedForest, size);
    
    int magicalNumber;
    printf("✨ Enter a magical number to find (between 1 and 99): ");
    scanf("%d", &magicalNumber);

    // Searching for the magical number in the enchanted forest
    int result = binarySearch(enchantedForest, 0, size - 1, magicalNumber);
    
    // Explore the result of the search
    if (result != -1) {
        printf("🎉 Congratulations! The magical number %d was found at index %d in the enchanted forest.\n", magicalNumber, result);
    } else {
        printf("😢 Alas! The magical number %d could not be found. It might be lost in the forest forever...\n", magicalNumber);
    }

    // A wise farewell to the user
    printf("🧚 Thank you for exploring the enchanted forest! Until next time...\n");
    
    return 0;
}