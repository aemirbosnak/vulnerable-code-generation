//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: excited
#include<stdio.h>
#include<string.h>

int min(int x, int y, int z) {
    if (x <= y && x <= z) {
        return x;
    }
    if (y <= x && y <= z) {
        return y;
    }
    else {
        return z;
    }
}

int levenshtein_distance(char* word1, char* word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int i, j;

    // Create a matrix to store Levenshtein distances
    int matrix[len1 + 1][len2 + 1];

    // Fill first row and column of the matrix with 0 to len values
    for (i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }
    for (j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    // Fill the rest of the matrix
    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            int substitution_cost = word1[i - 1] == word2[j - 1] ? 0 : 1;
            matrix[i][j] = min(matrix[i - 1][j] + 1,  // Deletion
                        matrix[i][j - 1] + 1,  // Insertion
                        matrix[i - 1][j - 1] + substitution_cost);  // Substitution
        }
    }

    // Return the final Levenshtein distance result
    return matrix[len1][len2];
}

int main() {
    char word1[100], word2[100];
    printf("Welcome to the Levenshtein Distance Calculator!\n");
    printf("Enter the first word: ");
    scanf("%s", word1);
    printf("Enter the second word: ");
    scanf("%s", word2);

    int result = levenshtein_distance(word1, word2);

    printf("The Levenshtein distance between '%s' and '%s' is %d.\n", word1, word2, result);
    printf("Thank you for using the Levenshtein Distance Calculator!");
    return 0;
}