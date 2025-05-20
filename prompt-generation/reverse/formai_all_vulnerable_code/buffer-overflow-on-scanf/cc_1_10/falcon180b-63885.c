//Falcon-180B DATASET v1.0 Category: Memory management ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000 // Maximum size of the array

int main() {
    char **array = NULL; // Initialize the array to NULL
    int size = 0; // Initialize the size to 0
    char *input; // Declare a character pointer for user input

    // Loop until the user enters "exit"
    while (1) {
        printf("Enter a string (or 'exit' to quit): ");
        scanf("%s", input);

        // If the user enters "exit", break out of the loop
        if (strcmp(input, "exit") == 0) {
            break;
        }

        // Check if the array needs to be resized
        if (size == MAX_SIZE) {
            printf("Error: Array is full.\n");
            continue;
        }

        // Allocate memory for the new string
        char *new_string = malloc((strlen(input) + 1) * sizeof(char));

        // Check if memory allocation was successful
        if (new_string == NULL) {
            printf("Error: Memory allocation failed.\n");
            continue;
        }

        // Copy the input string to the new string
        strcpy(new_string, input);

        // Add the new string to the array
        array[size++] = new_string;

        // Print a message confirming the string was added
        printf("Added string: %s\n", input);
    }

    // Free all allocated memory and exit
    for (int i = 0; i < size; i++) {
        free(array[i]);
    }
    free(array);
    return 0;
}