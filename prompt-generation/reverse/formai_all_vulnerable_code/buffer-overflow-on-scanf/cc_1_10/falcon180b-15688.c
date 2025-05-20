//Falcon-180B DATASET v1.0 Category: Memory management ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int main() {
    char *str;
    int size = 0;
    int i;

    // Allocate memory for the string
    str = (char*) malloc(MAX_SIZE);

    // Check if memory allocation was successful
    if (str == NULL) {
        printf("Memory allocation failed!\n");
        exit(0);
    }

    // Initialize string to empty
    str[0] = '\0';

    // Prompt user to enter a string
    printf("Enter a string: ");
    scanf("%s", str);

    // Get the size of the string
    for (i = 0; str[i]!= '\0'; i++) {
        size++;
    }

    // Reallocate memory for the string based on its size
    str = (char*) realloc(str, size + 1);

    // Check if reallocation was successful
    if (str == NULL) {
        printf("Reallocation failed!\n");
        exit(0);
    }

    // Copy the string to the new memory location
    strcpy(str, str);

    // Print the string
    printf("String: %s\n", str);

    // Free the memory allocated for the string
    free(str);

    return 0;
}