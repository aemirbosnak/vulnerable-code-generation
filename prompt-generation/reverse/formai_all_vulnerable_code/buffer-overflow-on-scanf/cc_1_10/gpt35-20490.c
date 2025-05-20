//FormAI DATASET v1.0 Category: Searching algorithm ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// Create a structure to hold the data for each element in the search array
typedef struct {
    int key;    // Unique identifier for the element
    int value;  // Value associated with the element
} Element;

// Function to search the array for a given key
int search(Element array[], int size, int key) {
    int low = 0;
    int high = size - 1;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        
        if (array[mid].key == key) {
            return array[mid].value;
        } else if (array[mid].key < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return -1;
}

int main() {
    // Create a sample array of elements to search through
    Element array[] = {{0, 10}, {1, 20}, {2, 30}, {3, 40}, {4, 50}, {5, 60}, {6, 70}, {7, 80}, {8, 90}, {9, 100}};
    int size = sizeof(array) / sizeof(Element);
    
    // Prompt the user for a key to search
    int key;
    printf("Enter a key to search for: ");
    scanf("%d", &key);
    
    // Search for the key in the array
    int value = search(array, size, key);
    
    // Display the result
    if (value == -1) {
        printf("Key not found.\n");
    } else {
        printf("Value for key %d: %d\n", key, value);
    }
    
    return 0;
}