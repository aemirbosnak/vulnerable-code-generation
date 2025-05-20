//Falcon2-11B DATASET v1.0 Category: Searching algorithm ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to search for a pattern in a string
int searchPattern(char* str, char* pattern) {
    int len1 = strlen(str);
    int len2 = strlen(pattern);
    int i, j;

    // Check if both strings are empty
    if (len1 == 0 || len2 == 0) {
        return -1;
    }

    // Search for the pattern in the string
    for (i = 0, j = 0; i < len1 && j < len2; i++, j++) {
        if (str[i]!= pattern[j]) {
            // If not a match, move to the next position in the string
            if (str[i] < pattern[j]) {
                i++;
            } else {
                j++;
            }
        }
    }

    // If the pattern is found, return the position where it was found
    if (i == len1 && j == len2) {
        return i;
    }

    // If the pattern is not found, return -1
    return -1;
}

int main() {
    char str[100];
    char pattern[100];

    printf("Enter the string to search: ");
    scanf("%s", str);

    printf("Enter the pattern to search: ");
    scanf("%s", pattern);

    int position = searchPattern(str, pattern);

    if (position!= -1) {
        printf("The pattern '%s' was found at position %d in the string.\n", pattern, position);
    } else {
        printf("The pattern '%s' was not found in the string.\n", pattern);
    }

    return 0;
}