//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100 // Maximum length of words

// Function to calculate Levenshtein distance between two strings
int levenshtein_distance(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // Initialize the matrix with zeros
    int matrix[MAX_LENGTH][MAX_LENGTH] = { 0 };

    // Initialize the first row and column of the matrix
    for (int i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    // Fill the rest of the matrix
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = matrix[i - 1][j] + 1;
            }
        }
    }

    return matrix[len1][len2];
}

int main() {
    char str1[MAX_LENGTH], str2[MAX_LENGTH];

    // Get input strings from user
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);

    // Calculate Levenshtein distance
    int distance = levenshtein_distance(str1, str2);

    // Print the result
    printf("Levenshtein distance between '%s' and '%s' is %d\n", str1, str2, distance);

    return 0;
}