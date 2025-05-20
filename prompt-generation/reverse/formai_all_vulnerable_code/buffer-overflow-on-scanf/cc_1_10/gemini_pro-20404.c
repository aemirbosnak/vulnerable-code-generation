//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a string is a valid number
int is_number(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
    }
    return 1;
}

// Function to compare two strings
int compare_strings(const void *a, const void *b) {
    const char *str1 = *(const char **)a;
    const char *str2 = *(const char **)b;

    // Check if both strings are numbers
    int is_num1 = is_number(str1);
    int is_num2 = is_number(str2);

    // If both strings are numbers, compare them numerically
    if (is_num1 && is_num2) {
        int num1 = atoi(str1);
        int num2 = atoi(str2);
        return num1 - num2;
    }
    // If only one string is a number, put the number first
    else if (is_num1) {
        return -1;
    } else if (is_num2) {
        return 1;
    }
    // Otherwise, compare the strings lexicographically
    else {
        return strcmp(str1, str2);
    }
}

int main() {
    // Get the input array of strings
    char **strings;
    int num_strings;
    printf("Enter the number of strings: ");
    scanf("%d", &num_strings);

    strings = malloc(sizeof(char *) * num_strings);
    for (int i = 0; i < num_strings; i++) {
        strings[i] = malloc(sizeof(char) * 100);
        printf("Enter string %d: ", i + 1);
        scanf("%s", strings[i]);
    }

    // Sort the array of strings
    qsort(strings, num_strings, sizeof(char *), compare_strings);

    // Print the sorted array of strings
    printf("\nSorted strings:\n");
    for (int i = 0; i < num_strings; i++) {
        printf("%s\n", strings[i]);
    }

    // Free the allocated memory
    for (int i = 0; i < num_strings; i++) {
        free(strings[i]);
    }
    free(strings);

    return 0;
}