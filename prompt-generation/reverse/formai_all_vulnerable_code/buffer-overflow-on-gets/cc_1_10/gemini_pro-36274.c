//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the strings to be compared
#define MAX_STRING_LENGTH 100

// Declare the function to calculate the Levenshtein distance
int levenshtein(char *s1, char *s2);

// Main function
int main(void) {

    // Declare the variables to store the strings to be compared and the Levenshtein distance
    char s1[MAX_STRING_LENGTH];
    char s2[MAX_STRING_LENGTH];
    int distance;

    // Prompt the user to enter the first string
    printf("Enter the first string: ");
    gets(s1);

    // Prompt the user to enter the second string
    printf("Enter the second string: ");
    gets(s2);

    // Calculate the Levenshtein distance
    distance = levenshtein(s1, s2);

    // Print the Levenshtein distance
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d\n", s1, s2, distance);

    return 0;
}

// Function to calculate the Levenshtein distance
int levenshtein(char *s1, char *s2) {

    // Declare the variables to store the length of the strings
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    // Declare the matrix to store the Levenshtein distances
    int matrix[len1 + 1][len2 + 1];

    // Initialize the first row and column of the matrix
    for (int i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    // Calculate the Levenshtein distances
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = fmin(fmin(matrix[i - 1][j - 1], matrix[i - 1][j]), matrix[i][j - 1]) + 1;
            }
        }
    }

    // Return the Levenshtein distance
    return matrix[len1][len2];
}