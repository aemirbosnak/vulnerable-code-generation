//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int levenshtein_distance(char* s1, char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int matrix[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }

    for (int j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    int substitutionCost;
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                substitutionCost = 0;
            } else {
                substitutionCost = 1;
            }
            matrix[i][j] = fmin(matrix[i - 1][j] + 1,
                                 fmin(matrix[i][j - 1] + 1,
                                      matrix[i - 1][j - 1] + substitutionCost));
        }
    }

    return matrix[len1][len2];
}

int main() {
    char string1[100];
    char string2[100];

    printf("Enter the first string: ");
    scanf("%s", string1);

    printf("Enter the second string: ");
    scanf("%s", string2);

    int distance = levenshtein_distance(string1, string2);

    printf("The Levenshtein Distance between %s and %s is: %d\n", string1, string2, distance);

    return 0;
}