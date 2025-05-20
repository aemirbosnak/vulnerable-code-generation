//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int min(int a, int b, int c) {
    return (a < b)? ((a < c)? a : c) : ((b < c)? b : c);
}

int levenshteinDistance(char* s1, char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int matrix[MAX_LENGTH][MAX_LENGTH];

    for (int i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }

    for (int j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = 1 + min(matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]);
            }
        }
    }

    return matrix[len1][len2];
}

int main() {
    char string1[MAX_LENGTH];
    char string2[MAX_LENGTH];

    printf("Enter first string: ");
    scanf("%s", string1);

    printf("Enter second string: ");
    scanf("%s", string2);

    int distance = levenshteinDistance(string1, string2);

    printf("Levenshtein distance between '%s' and '%s': %d\n", string1, string2, distance);

    return 0;
}