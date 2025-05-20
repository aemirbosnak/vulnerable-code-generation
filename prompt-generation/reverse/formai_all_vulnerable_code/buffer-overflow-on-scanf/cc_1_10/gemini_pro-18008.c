//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the strings
#define MAX_LEN 100

// Define the cost of insertion, deletion, and substitution
#define COST_INSERT 1
#define COST_DELETE 1
#define COST_SUBSTITUTE 1

// Function to calculate the Levenshtein distance between two strings
int levenshtein(char *s1, char *s2) {
    // Create a matrix to store the distances
    int matrix[MAX_LEN][MAX_LEN];

    // Initialize the first row and column of the matrix
    for (int i = 0; i < strlen(s1) + 1; i++) {
        matrix[i][0] = i * COST_INSERT;
    }
    for (int j = 0; j < strlen(s2) + 1; j++) {
        matrix[0][j] = j * COST_DELETE;
    }

    // Fill in the rest of the matrix
    for (int i = 1; i < strlen(s1) + 1; i++) {
        for (int j = 1; j < strlen(s2) + 1; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = fmin(fmin(matrix[i - 1][j] + COST_DELETE,
                                         matrix[i][j - 1] + COST_INSERT),
                                    matrix[i - 1][j - 1] + COST_SUBSTITUTE);
            }
        }
    }

    // Return the distance
    return matrix[strlen(s1)][strlen(s2)];
}

// Main function
int main() {
    // Get the two strings from the user
    char s1[MAX_LEN], s2[MAX_LEN];
    printf("Enter the first string: ");
    scanf("%s", s1);
    printf("Enter the second string: ");
    scanf("%s", s2);

    // Calculate the Levenshtein distance
    int distance = levenshtein(s1, s2);

    // Print the distance
    printf("The Levenshtein distance between the two strings is: %d\n", distance);

    return 0;
}