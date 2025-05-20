//Falcon-180B DATASET v1.0 Category: Educational ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 1000 // Maximum length of a string

int main() {
    char *strings[100]; // Array to hold strings
    int num_strings = 0; // Number of strings in the array
    int i; // Loop counter

    // Seed the random number generator
    srand(time(NULL));

    // Prompt the user for the number of strings to generate
    printf("Enter the number of strings to generate: ");
    scanf("%d", &num_strings);

    // Generate the strings
    for (i = 0; i < num_strings; i++) {
        int length = rand() % MAX_LENGTH + 1; // Random length between 1 and MAX_LENGTH
        strings[i] = (char *) malloc(length * sizeof(char)); // Allocate memory for the string
        if (strings[i] == NULL) { // Check for memory allocation failure
            printf("Error: Failed to allocate memory for string.\n");
            exit(1);
        }
        // Fill the string with random characters
        for (int j = 0; j < length; j++) {
            strings[i][j] = rand() % 26 + 'a'; // Random lowercase letter
        }
        strings[i][length - 1] = '\0'; // Add null terminator to the end of the string
    }

    // Sort the strings alphabetically
    for (i = 0; i < num_strings - 1; i++) {
        for (int j = i + 1; j < num_strings; j++) {
            if (strcmp(strings[i], strings[j]) > 0) { // Compare the strings using strcmp
                char *temp = strings[i]; // Swap the strings
                strings[i] = strings[j];
                strings[j] = temp;
            }
        }
    }

    // Print the sorted strings
    printf("Sorted strings:\n");
    for (i = 0; i < num_strings; i++) {
        printf("%s\n", strings[i]);
    }

    // Free the memory allocated for the strings
    for (i = 0; i < num_strings; i++) {
        free(strings[i]);
    }

    return 0;
}