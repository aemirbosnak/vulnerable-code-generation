//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

// Custom data structure to store a string and its length
typedef struct String {
    char *str;
    int len;
} String;

// Custom comparison function to sort strings by length
int compare_strings(const void *a, const void *b) {
    const String *str1 = (const String *)a;
    const String *str2 = (const String *)b;

    return str1->len - str2->len;
}

int main() {
    // Get the number of strings from the user
    int num_strings;
    printf("Enter the number of strings: ");
    scanf("%d", &num_strings);

    // Allocate memory for an array of strings
    String *strings = malloc(sizeof(String) * num_strings);

    // Read the strings from the user
    for (int i = 0; i < num_strings; i++) {
        // Allocate memory for the string
        strings[i].str = malloc(MAX_LENGTH);

        // Read the string
        printf("Enter string %d: ", i + 1);
        scanf(" %[^\n]%*c", strings[i].str);

        // Calculate the length of the string
        strings[i].len = strlen(strings[i].str);
    }

    // Sort the strings by length using the qsort function
    qsort(strings, num_strings, sizeof(String), compare_strings);

    // Print the sorted strings
    printf("\nSorted strings by length:\n");
    for (int i = 0; i < num_strings; i++) {
        printf("%s (%d characters)\n", strings[i].str, strings[i].len);
    }

    // Free the memory allocated for the strings
    for (int i = 0; i < num_strings; i++) {
        free(strings[i].str);
    }
    free(strings);

    return 0;
}