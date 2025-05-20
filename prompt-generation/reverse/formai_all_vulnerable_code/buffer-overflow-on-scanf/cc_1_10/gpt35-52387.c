//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

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

int levenshtein_distance(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int matrix[MAX_LEN][MAX_LEN];

    for (int i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }

    for (int j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int substitutionCost = s1[i - 1] == s2[j - 1] ? 0 : 1;
            matrix[i][j] = minimum(
                matrix[i - 1][j] + 1, // deletion
                matrix[i][j - 1] + 1, // insertion
                matrix[i - 1][j - 1] + substitutionCost // substitution
            );
        }
    }

    return matrix[len1][len2];
}

int main() {
    char s1[MAX_LEN], s2[MAX_LEN];
    printf("Enter string 1: ");
    scanf("%s", s1);
    printf("Enter string 2: ");
    scanf("%s", s2);
    int distance = levenshtein_distance(s1, s2);
    printf("Levenshtein distance: %d\n", distance);
    return 0;
}