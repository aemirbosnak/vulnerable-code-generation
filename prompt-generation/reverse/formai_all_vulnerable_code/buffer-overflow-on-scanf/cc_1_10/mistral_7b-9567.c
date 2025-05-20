//MISTRAL-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

void print_matrix(int **matrix, int row, int col) {
    int i, j;

    printf("\nLevenshtein Distance Matrix:\n");
    for (i = 0; i <= row; i++) {
        for (j = 0; j <= col; j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int levenshtein_distance(char *str1, char *str2, int m, int n) {
    int i, j, cost;
    int **matrix;

    matrix = (int **)malloc((m + 1) * sizeof(int *));
    for (i = 0; i <= m; i++) {
        matrix[i] = (int *)malloc((n + 1) * sizeof(int));
    }

    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0)
                matrix[i][j] = j;

            if (j == 0)
                matrix[i][j] = i;

            if (str1[i - 1] == str2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                cost = 1;
                if (str1[i - 1] != '\0')
                    cost += matrix[i - 1][j];
                if (str2[j - 1] != '\0')
                    cost += matrix[i][j - 1];

                matrix[i][j] = min(min(matrix[i - 1][j], matrix[i][j - 1]), cost);
            }
        }
    }

    return matrix[m][n];
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    char str1[MAX_SIZE], str2[MAX_SIZE];
    int len1, len2, dist;

    printf("Enter first string: ");
    scanf("%s", str1);
    len1 = strlen(str1);

    printf("Enter second string: ");
    scanf("%s", str2);
    len2 = strlen(str2);

    dist = levenshtein_distance(str1, str2, len1, len2);

    printf("Levenshtein Distance: %d\n", dist);

    int **matrix = (int **)calloc((len1 + 1), sizeof(int *));
    for (int i = 0; i <= len1; i++) {
        matrix[i] = (int *)calloc((len2 + 1), sizeof(int));
    }

    print_matrix(matrix, len1, len2);

    for (int i = 0; i <= len1; i++)
        free(matrix[i]);
    free(matrix);

    return 0;
}