//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100
#define MAX_STRINGS 10

// Function declarations
void allocateStrings(char ***strings, int count);
void deallocateStrings(char **strings);
void fillStrings(char **strings, int count);
void printStrings(char **strings, int count);

int main() {
    char **strings = NULL;
    int stringCount;

    printf("Enter the number of strings you want to allocate (up to %d): ", MAX_STRINGS);
    scanf("%d", &stringCount);

    if (stringCount < 1 || stringCount > MAX_STRINGS) {
        fprintf(stderr, "Error: The number of strings must be between 1 and %d.\n", MAX_STRINGS);
        return EXIT_FAILURE;
    }

    // Allocate memory for the strings
    allocateStrings(&strings, stringCount);
    
    // Fill the strings with data
    fillStrings(strings, stringCount);
    
    // Print the strings
    printf("\nHere are the strings you entered:\n");
    printStrings(strings, stringCount);

    // Deallocate memory for the strings
    deallocateStrings(strings);

    return EXIT_SUCCESS;
}

// Function to allocate memory for an array of strings
void allocateStrings(char ***strings, int count) {
    *strings = (char **)malloc(count * sizeof(char *));
    if (*strings == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < count; i++) {
        (*strings)[i] = (char *)malloc(MAX_STRING_LENGTH * sizeof(char));
        if ((*strings)[i] == NULL) {
            fprintf(stderr, "Error: Memory allocation for string %d failed.\n", i);
            exit(EXIT_FAILURE);
        }
    }
}

// Function to deallocate memory for the strings
void deallocateStrings(char **strings) {
    for (int i = 0; strings[i] != NULL; i++) {
        free(strings[i]);
    }
    free(strings);
}

// Function to fill strings with user input
void fillStrings(char **strings, int count) {
    for (int i = 0; i < count; i++) {
        printf("Enter string %d: ", i + 1);
        getchar(); // Clear newline left in buffer from previous input
        fgets(strings[i], MAX_STRING_LENGTH, stdin);
        strings[i][strcspn(strings[i], "\n")] = '\0'; // Remove newline character if present
    }
}

// Function to print the strings
void printStrings(char **strings, int count) {
    for (int i = 0; i < count; i++) {
        printf("String %d: %s\n", i + 1, strings[i]);
    }
}