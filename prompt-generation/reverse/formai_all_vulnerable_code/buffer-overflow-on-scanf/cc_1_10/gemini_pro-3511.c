//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Define the data type of the array
typedef int data_type;

// Define the function to search for an element in the array
int search(data_type *array, int size, data_type element) {
  // Initialize the index of the element to be found
  int index = 0;

  // Iterate over the array until the element is found or the end of the array is reached
  while (index < size && array[index] != element) {
	// Increment the index
	index++;
  }

  // Return the index of the element if it was found, or -1 if it was not found
  return index < size ? index : -1;
}

// Define the main function
int main() {
    
    // Define the array
    int size;
    data_type array[MAX_SIZE];
  
    printf("Enter the size of the array: ");
    scanf(" %d ", &size);
    
    printf("Enter the elements of the array separted by Comma(,): ");
    
    for(int i=0; i<size; i++){
        scanf(" %d ", &array[i]);
    }   
  
    // Get the element to be searched
    data_type element;
    printf("Enter the element to be searched: ");
    scanf("%d", &element);

    // Search for the element
    int index = search(array, size, element);

    // Print the result
    if (index == -1) {
      printf("The element was not found.\n");
    } else {
      printf("The element was found at index %d.\n", index);
    }
  
    return 0;
}