//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000

int main() {
    char str1[MAX_SIZE], str2[MAX_SIZE];
    int len1, len2, i, j, k, min_len, cost;
    int **matrix;

    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    len1 = strlen(str1);
    len2 = strlen(str2);

    if (len1 == 0 || len2 == 0) {
        printf("Error: strings must not be empty.\n");
        return 1;
    }

    if (len1 > len2) {
        printf("Error: first string must not be longer than second string.\n");
        return 1;
    }

    min_len = len1;
    matrix = (int **)malloc(sizeof(int *) * (min_len + 1));
    for (i = 0; i <= min_len; i++) {
        matrix[i] = (int *)malloc(sizeof(int) * (min_len + 1));
    }

    for (i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }

    for (j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                cost = 0;
            } else {
                cost = 1;
            }

            matrix[i][j] = matrix[i - 1][j] + 1;

            for (k = 1; k < i; k++) {
                if (matrix[k][j] + 1 < matrix[i][j]) {
                    matrix[i][j] = matrix[k][j] + 1;
                }
            }

            for (k = 1; k < j; k++) {
                if (matrix[i][k] + 1 < matrix[i][j]) {
                    matrix[i][j] = matrix[i][k] + 1;
                }
            }
        }
    }

    printf("Levenshtein distance: %d\n", matrix[len1][len2]);

    for (i = 0; i <= len1; i++) {
        free(matrix[i]);
    }

    free(matrix);

    return 0;
}