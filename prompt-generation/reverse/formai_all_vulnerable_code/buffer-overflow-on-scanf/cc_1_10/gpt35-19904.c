//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: statistical
#include <stdio.h>
#include <string.h>

// Define maximum length for strings
#define MAX 100

// Function to calculate the minimum of three integers
int min(int a, int b, int c) {
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    return min;
}

// Function to calculate Levenshtein Distance between two strings
int levenshtein(char* s1, char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int matrix[MAX][MAX];

    // Initialize the matrix with 0s
    for (int i = 0; i <= len1; i++) {
            for (int j = 0; j <= len2; j++) {
            matrix[i][j] = 0;
        }
    }

    // Fill the first row and column with increasing numbers
    for (int i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    // Loop over the matrix and calculate the minimum edit distance
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = s1[i-1] == s2[j-1] ? 0 : 1;
            int substitution = matrix[i-1][j-1] + cost;
            int insertion = matrix[i][j-1] + 1;
            int deletion = matrix[i-1][j] + 1;
            matrix[i][j] = min(substitution, insertion, deletion);
        }
    }

    // Return the final edit distance
    return matrix[len1][len2];
}

int main() {
    char str1[MAX], str2[MAX];
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);
    int distance = levenshtein(str1, str2);
    printf("Levenshtein Distance: %d\n", distance);
    return 0;
}