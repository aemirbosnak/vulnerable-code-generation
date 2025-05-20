//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int levenshtein_distance(char *str1, char *str2) {
    int m = strlen(str1);
    int n = strlen(str2);
    int cost = 0;
    int mat[MAX_LEN][MAX_LEN] = {0};
    
    // Initialize the matrix
    for (int i = 0; i <= m; i++) {
        mat[i][0] = i;
    }
    for (int j = 0; j <= n; j++) {
        mat[0][j] = j;
    }
    
    // Calculate the Levenshtein distance
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= m; i++) {
            if (str1[i-1] == str2[j-1]) {
                cost = 0;
            } else {
                cost = 1;
            }
            mat[i][j] = minimum(mat[i-1][j] + 1, // Deletion
                                 mat[i][j-1] + 1, // Insertion
                                 mat[i-1][j-1] + cost); // Substitution
        }
    }
    
    // Return the Levenshtein distance
    return mat[m][n];
}

int minimum(int a, int b, int c) {
    int min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    return min;
}

int main() {
    char str1[MAX_LEN], str2[MAX_LEN];
    
    // Get input from the user
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);
    
    // Calculate the Levenshtein distance and print the result
    printf("Levenshtein distance: %d\n", levenshtein_distance(str1, str2));
    
    return 0;
}