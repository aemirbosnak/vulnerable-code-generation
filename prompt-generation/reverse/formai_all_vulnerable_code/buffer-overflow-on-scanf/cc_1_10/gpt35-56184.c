//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int minimum(int a, int b, int c) {
    // Returns the minimum value among a, b and c
    return (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
}

int levenshteinDistance(char *s1, char *s2) {
    // Calculate the Levenshtein Distance for two given strings
    
    int n1 = strlen(s1), n2 = strlen(s2);
    int ldMatrix[MAX_LEN][MAX_LEN];

    // Initialize the matrix
    for (int i = 0; i <= n1; i++) {
        for (int j = 0; j <= n2; j++) {
            if (i == 0) {
                ldMatrix[i][j] = j;
            } else if (j == 0) {
                ldMatrix[i][j] = i;
            } else {
                ldMatrix[i][j] = 0;
            }
        }
    }

    // Fill the dynamic programming table
    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                ldMatrix[i][j] = ldMatrix[i - 1][j - 1];
            } else {
                ldMatrix[i][j] = 1 + minimum(ldMatrix[i - 1][j], ldMatrix[i][j - 1], ldMatrix[i - 1][j - 1]);
            }
        }
    }

    return ldMatrix[n1][n2];
}

int main() {
    char s1[MAX_LEN], s2[MAX_LEN];
    printf("Enter the first string: ");
    scanf("%s", s1);
    printf("Enter the second string: ");
    scanf("%s", s2);
    printf("The Levenshtein Distance between '%s' and '%s' is %d.\n", s1, s2, levenshteinDistance(s1, s2));
    return 0;
}