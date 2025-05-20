//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum string length
#define MAX_STR_LEN 100

// Define the cost of insertion, deletion, and substitution
#define COST_INSERT 1
#define COST_DELETE 1
#define COST_SUBSTITUTE 1

// Calculate the Levenshtein distance between two strings
int levenshtein(char *str1, char *str2) {
    // Initialize the distance matrix
    int d[MAX_STR_LEN + 1][MAX_STR_LEN + 1];
    for (int i = 0; i <= strlen(str1); i++) {
        for (int j = 0; j <= strlen(str2); j++) {
            d[i][j] = 0;
        }
    }

    // Calculate the distance matrix
    for (int i = 1; i <= strlen(str1); i++) {
        d[i][0] = i * COST_DELETE;
    }
    for (int j = 1; j <= strlen(str2); j++) {
        d[0][j] = j * COST_INSERT;
    }
    for (int i = 1; i <= strlen(str1); i++) {
        for (int j = 1; j <= strlen(str2); j++) {
            if (str1[i - 1] == str2[j - 1]) {
                d[i][j] = d[i - 1][j - 1];
            } else {
                d[i][j] = fmin(fmin(d[i - 1][j] + COST_DELETE, d[i][j - 1] + COST_INSERT), d[i - 1][j - 1] + COST_SUBSTITUTE);
            }
        }
    }

    // Return the distance
    return d[strlen(str1)][strlen(str2)];
}

// Main function
int main() {
    // Get the two strings from the user
    char str1[MAX_STR_LEN + 1];
    char str2[MAX_STR_LEN + 1];
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);

    // Calculate the Levenshtein distance between the two strings
    int distance = levenshtein(str1, str2);

    // Print the distance
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", str1, str2, distance);

    return 0;
}