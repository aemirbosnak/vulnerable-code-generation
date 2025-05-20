//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: peaceful
#include <stdio.h>
#include <string.h>

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

int levenshtein_distance(char *str1, int len1, char *str2, int len2) {
    int matrix[len1 + 1][len2 + 1];
    int i, j;

    for (i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }
    for (j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = 1 + minimum(
                    matrix[i - 1][j], 
                    matrix[i][j - 1], 
                    matrix[i - 1][j - 1]
                );
            }
        }
    }

    return matrix[len1][len2];
}

int main() {
    char str1[100], str2[100];
    int distance;

    printf("Enter the first string: ");
    fgets(str1, 100, stdin);
    printf("Enter the second string: ");
    fgets(str2, 100, stdin);

    int len1 = strlen(str1) - 1;
    int len2 = strlen(str2) - 1;

    distance = levenshtein_distance(str1, len1, str2, len2);

    printf("Levenshtein Distance between '%s' and '%s' is %d", str1, str2, distance);

    return 0;
}