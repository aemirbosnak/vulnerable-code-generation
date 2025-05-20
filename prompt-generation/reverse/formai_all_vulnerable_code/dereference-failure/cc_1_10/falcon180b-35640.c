//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: artistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LENGTH 100

int levenshtein_distance(char *str1, char *str2, int n, int m) {
    int **matrix = (int **)malloc(sizeof(int *) * (n + 1));
    for (int i = 0; i <= n; i++) {
        matrix[i] = (int *)malloc(sizeof(int) * (m + 1));
        for (int j = 0; j <= m; j++) {
            matrix[i][j] = 0;
        }
    }

    for (int i = 0; i <= n; i++) {
        matrix[i][0] = i;
    }

    for (int j = 0; j <= m; j++) {
        matrix[0][j] = j;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = matrix[i - 1][j] + 1;
            }
        }
    }

    int result = matrix[n][m];

    for (int i = 0; i <= n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return result;
}

int main() {
    char str1[MAX_LENGTH], str2[MAX_LENGTH];

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int distance = levenshtein_distance(str1, str2, len1, len2);

    printf("Levenshtein distance between '%s' and '%s': %d\n", str1, str2, distance);

    return 0;
}