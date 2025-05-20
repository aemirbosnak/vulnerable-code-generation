//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: enthusiastic
// Hello! Welcome to my Levenshtein Distance Calculator!

#include <stdio.h>
#include <string.h>

// Function to find the minimum of three numbers
int min(int x, int y, int z) {
    if (x < y && x < z) {
        return x;
    } else if (y < x && y < z) {
        return y;
    } else {
        return z;
    }
}

// Function to calculate Levenshtein Distance
int levenshtein_distance(char *a, char *b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    int matrix[len_a + 1][len_b + 1];
    
    // Initialize matrix
    for (int i = 0; i <= len_a; i++) {
        for (int j = 0; j <= len_b; j++) {
            if (i == 0) {
                matrix[i][j] = j;
            }
            else if (j == 0) {
                matrix[i][j] = i;
            }
            else {
                matrix[i][j] = 0;
            }
        }
    }
    
    /* Loop through the matrix and calculate the Levenshtein Distance
    using the minimum of three numbers: the cell to the left + 1,
    the cell above + 1, or the cell diagonally above and to the left */
    for (int i = 1; i <= len_a; i++) {
        for (int j = 1; j <= len_b; j++) {
            if (a[i-1] == b[j-1]) {
                matrix[i][j] = matrix[i-1][j-1];
            }
            else {
                matrix[i][j] = min(matrix[i][j-1] + 1, matrix[i-1][j] + 1, matrix[i-1][j-1] + 1);
            }
        }
    }
    
    // Return the Levenshtein Distance, which is the value in the bottom right corner of the matrix
    return matrix[len_a][len_b];
}

int main() {
    char word1[100];
    char word2[100];
    
    printf("Enter a word: ");
    scanf("%s", word1);
    
    printf("Enter another word: ");
    scanf("%s", word2);
    
    printf("The Levenshtein Distance between %s and %s is %d\n", word1, word2, levenshtein_distance(word1, word2));
    
    return 0;
}