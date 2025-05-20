//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int levenshteinDistance(char* s1, char* s2);

int main() {
    char string1[MAX_LENGTH], string2[MAX_LENGTH];

    printf("Enter first string: ");
    scanf("%s", string1);

    printf("Enter second string: ");
    scanf("%s", string2);

    int distance = levenshteinDistance(string1, string2);

    printf("Levenshtein distance: %d\n", distance);

    return 0;
}

int levenshteinDistance(char* s1, char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    int matrix[len1+1][len2+1];

    for (int i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }

    for (int j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (s1[i-1] == s2[j-1]) {
                matrix[i][j] = matrix[i-1][j-1];
            } else {
                matrix[i][j] = matrix[i-1][j] + 1;
            }
        }
    }

    return matrix[len1][len2];
}