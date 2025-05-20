//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the string array
#define MAX_SIZE 100

// Function to search for a string in an array of strings
int search(char *strings[], int size, char *target) {
    int i;

    // Loop through each string in the array
    for (i = 0; i < size; i++) {
        // Compare the target string with the current string in the array
        if (strcmp(strings[i], target) == 0) {
            // If a match is found, return the index of the string
            return i;
        }
    }

    // If no match is found, return -1
    return -1;
}

int main() {
    char strings[MAX_SIZE][100];
    int size;

    // Prompt the user to enter the number of strings
    printf("Enter the number of strings: ");
    scanf("%d", &size);

    // Prompt the user to enter each string
    printf("Enter the strings:\n");
    for (int i = 0; i < size; i++) {
        scanf("%s", strings[i]);
    }

    // Prompt the user to enter the target string
    char target[100];
    printf("Enter the target string: ");
    scanf("%s", target);

    // Search for the target string in the array
    int result = search(strings, size, target);

    // Print the result of the search
    if (result == -1) {
        printf("The target string was not found in the array.\n");
    } else {
        printf("The target string was found at index %d.\n", result);
    }

    return 0;
}