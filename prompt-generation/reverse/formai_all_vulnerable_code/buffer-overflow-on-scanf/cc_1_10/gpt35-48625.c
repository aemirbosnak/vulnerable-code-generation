//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: immersive
#include <stdio.h>
#include <string.h>

/*
Levenshtein Distance is a measure of the minimum number of operations (deletions, insertions, or substitutions) to transform one string into another.
This implementation of Levenshtein Distance uses Dynamic Programming, and it runs in O(n*m) time complexity to compare strings of length n and m.
*/

// Function to calculate Levenshtein Distance between two strings
int levenshtein_distance(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // Initializing matrix to represent edits required to transform str1 into str2
    int edit_matrix[len1+1][len2+1];

    // Filling first row and column with their indices
    for (int i = 0; i <= len1; i++) {
        edit_matrix[i][0] = i;
    }

    for (int j = 0; j <= len2; j++) {
        edit_matrix[0][j] = j;
    }

    // Filling rest of the matrix using dynamic programming
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int substitution_cost;
            if (str1[i-1] == str2[j-1]) {
                substitution_cost = 0;
            } else {
                substitution_cost = 1;
            }
            int deletion_cost = edit_matrix[i-1][j] + 1;
            int insertion_cost = edit_matrix[i][j-1] + 1;
            int substitution_or_nothing_cost = edit_matrix[i-1][j-1] + substitution_cost;
            int min_cost = deletion_cost;
            if (insertion_cost < min_cost) {
                min_cost = insertion_cost;
            }
            if (substitution_or_nothing_cost < min_cost) {
                min_cost= substitution_or_nothing_cost;
            }
            edit_matrix[i][j] = min_cost;
        }
    }

    // Returning the final minimum edit distance
    return edit_matrix[len1][len2];
}

int main() {
    printf("Welcome to the Levenshtein Distance Calculator!\n\n");
    char str1[1000];
    char str2[1000];

    printf("Enter the first string: ");
    scanf("%[^\n]s", str1);
    getchar();

    printf("\nEnter the second string: ");
    scanf("%[^\n]s", str2);

    int distance = levenshtein_distance(str1, str2);

    printf("\nLevenshtein Distance between \"%s\" and \"%s\" is %d\n", str1, str2, distance);

    return 0;
}