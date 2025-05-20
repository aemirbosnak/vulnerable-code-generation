//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

int min(int a, int b, int c) {
    return a < b? (a < c? a : c) : (b < c? b : c);
}

void print_matrix(int **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int levenshtein_distance(char *s1, char *s2) {
    int n = strlen(s1);
    int m = strlen(s2);

    int **matrix = (int **)malloc(sizeof(int *) * (n + 1));
    for (int i = 0; i <= n; i++) {
        matrix[i] = (int *)malloc(sizeof(int) * (m + 1));
    }

    for (int i = 0; i <= n; i++) {
        matrix[i][0] = i;
    }

    for (int j = 0; j <= m; j++) {
        matrix[0][j] = j;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] =
                    1 + min(matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]);
            }
        }
    }

    int distance = matrix[n][m];

    for (int i = n; i >= 0; i--) {
        for (int j = m; j >= 0; j--) {
            if (matrix[i][j] == distance) {
                if (i == n && j == m) {
                    printf("Distance: %d\n", distance);
                } else if (i == n) {
                    printf("Insert '%c'\n", s2[j]);
                } else if (j == m) {
                    printf("Delete '%c'\n", s1[i]);
                } else if (matrix[i - 1][j] + 1 == distance) {
                    printf("Replace '%c' with '%c'\n", s1[i - 1], s2[j - 1]);
                } else if (matrix[i][j - 1] + 1 == distance) {
                    printf("Replace '%c' with '%c'\n", s1[i - 1], s2[j - 1]);
                } else {
                    printf("Unknown operation\n");
                }
            }
        }
    }

    for (int i = 0; i <= n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return distance;
}

int main() {
    char s1[MAX_LENGTH];
    char s2[MAX_LENGTH];

    printf("Enter first string: ");
    scanf("%s", s1);

    printf("Enter second string: ");
    scanf("%s", s2);

    int distance = levenshtein_distance(s1, s2);

    return 0;
}