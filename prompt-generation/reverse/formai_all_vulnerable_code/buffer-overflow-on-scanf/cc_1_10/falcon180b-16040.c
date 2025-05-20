//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of elements that can be stored in the array
#define MAX_ELEMENTS 1000

// Define the structure of a single element in the array
typedef struct {
    char *key;
    int value;
} element_t;

// Define the main function
int main() {
    element_t array[MAX_ELEMENTS]; // Initialize the array
    int num_elements = 0; // Initialize the number of elements in the array
    int i; // Initialize the loop counter

    // Prompt the user to enter the number of elements they want to store in the array
    printf("Enter the number of elements you want to store in the array: ");
    scanf("%d", &num_elements);

    // Prompt the user to enter each element and store it in the array
    for (i = 0; i < num_elements; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%s", array[i].key);
        array[i].value = i + 1; // Assign a unique value to each element
    }

    // Prompt the user to enter a search key
    printf("Enter the search key: ");
    char *search_key = (char *)malloc(strlen(gets()) + 1); // Allocate memory for the search key
    strcpy(search_key, gets()); // Copy the search key to the allocated memory

    // Search for the element with the given key in the array
    int found = 0; // Initialize the flag for whether the element was found
    int index; // Initialize the index of the element if it is found
    for (i = 0; i < num_elements; i++) {
        if (strcmp(array[i].key, search_key) == 0) { // Compare the search key with the key of each element
            found = 1; // Set the flag to indicate that the element was found
            index = i; // Store the index of the element
            break; // Exit the loop since the element was found
        }
    }

    // Print the results of the search
    if (found) {
        printf("Element found at index %d with value %d\n", index, array[index].value);
    } else {
        printf("Element not found\n");
    }

    // Free the memory allocated for the search key
    free(search_key);

    return 0;
}