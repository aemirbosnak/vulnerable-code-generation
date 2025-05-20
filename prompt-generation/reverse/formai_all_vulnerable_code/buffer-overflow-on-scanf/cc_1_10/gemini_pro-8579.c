//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRINGS 100
#define MAX_LENGTH 100

// Function to compare two strings based on their lengths
int compare_lengths(const void *a, const void *b) {
    const char *str1 = *(const char **)a;
    const char *str2 = *(const char **)b;
    return strlen(str1) - strlen(str2);
}

// Function to print the shortest and longest strings
void print_shortest_longest(char **strings, int num_strings) {
    // Sort the strings based on their lengths
    qsort(strings, num_strings, sizeof(char *), compare_lengths);

    // Print the shortest string
    printf("Shortest string: %s\n", strings[0]);

    // Print the longest string
    printf("Longest string: %s\n", strings[num_strings - 1]);
}

int main() {
    // Initialize an array of strings
    char *strings[MAX_STRINGS];

    // Get the number of strings from the user
    int num_strings;
    printf("Enter the number of strings: ");
    scanf("%d", &num_strings);

    // Check if the number of strings is valid
    if (num_strings <= 0 || num_strings > MAX_STRINGS) {
        printf("Invalid number of strings. Please enter a number between 1 and %d.\n", MAX_STRINGS);
        return 1;
    }

    // Get the strings from the user
    for (int i = 0; i < num_strings; i++) {
        // Allocate memory for the string
        strings[i] = malloc(MAX_LENGTH * sizeof(char));

        // Get the string from the user
        printf("Enter string %d: ", i + 1);
        scanf("%s", strings[i]);
    }

    // Print the shortest and longest strings
    print_shortest_longest(strings, num_strings);

    // Free the memory allocated for the strings
    for (int i = 0; i < num_strings; i++) {
        free(strings[i]);
    }

    return 0;
}