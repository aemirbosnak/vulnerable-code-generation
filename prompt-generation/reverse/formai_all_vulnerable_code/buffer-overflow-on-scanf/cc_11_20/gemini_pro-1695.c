//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a string
#define MAX_STRING_LENGTH 100

// Define the number of strings to process
#define NUM_STRINGS 5

// Main function
int main() {
    // Declare an array of strings
    char strings[NUM_STRINGS][MAX_STRING_LENGTH];

    // Prompt the user to enter the strings
    printf("Enter %d strings:\n", NUM_STRINGS);
    for (int i = 0; i < NUM_STRINGS; i++) {
        scanf("%s", strings[i]);
    }

    // Print the original strings
    printf("Original strings:\n");
    for (int i = 0; i < NUM_STRINGS; i++) {
        printf("%s\n", strings[i]);
    }

    // Convert the strings to uppercase
    for (int i = 0; i < NUM_STRINGS; i++) {
        for (int j = 0; strings[i][j] != '\0'; j++) {
            strings[i][j] = toupper(strings[i][j]);
        }
    }

    // Print the uppercase strings
    printf("Uppercase strings:\n");
    for (int i = 0; i < NUM_STRINGS; i++) {
        printf("%s\n", strings[i]);
    }

    // Convert the strings to lowercase
    for (int i = 0; i < NUM_STRINGS; i++) {
        for (int j = 0; strings[i][j] != '\0'; j++) {
            strings[i][j] = tolower(strings[i][j]);
        }
    }

    // Print the lowercase strings
    printf("Lowercase strings:\n");
    for (int i = 0; i < NUM_STRINGS; i++) {
        printf("%s\n", strings[i]);
    }

    // Find the longest string
    int longest_string_length = 0;
    char *longest_string = NULL;
    for (int i = 0; i < NUM_STRINGS; i++) {
        int length = strlen(strings[i]);
        if (length > longest_string_length) {
            longest_string_length = length;
            longest_string = strings[i];
        }
    }

    // Print the longest string
    printf("Longest string: %s\n", longest_string);

    // Find the shortest string
    int shortest_string_length = MAX_STRING_LENGTH;
    char *shortest_string = NULL;
    for (int i = 0; i < NUM_STRINGS; i++) {
        int length = strlen(strings[i]);
        if (length < shortest_string_length) {
            shortest_string_length = length;
            shortest_string = strings[i];
        }
    }

    // Print the shortest string
    printf("Shortest string: %s\n", shortest_string);

    // Find the average string length
    int total_string_length = 0;
    for (int i = 0; i < NUM_STRINGS; i++) {
        total_string_length += strlen(strings[i]);
    }
    float average_string_length = (float)total_string_length / NUM_STRINGS;

    // Print the average string length
    printf("Average string length: %.2f\n", average_string_length);

    return 0;
}