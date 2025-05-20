//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: shocked
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 100

void print_matrix(char **matrix, int n, int m) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int min(int a, int b, int c) {
    return a < b? (a < c? a : c) : (b < c? b : c);
}

int levenshtein_distance(char *str1, char *str2) {
    int n = strlen(str1);
    int m = strlen(str2);

    char **matrix = (char **)malloc(sizeof(char *) * (n + 1));
    for (int i = 0; i <= n; i++) {
        matrix[i] = (char *)malloc(sizeof(char) * (m + 1));
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
                matrix[i][j] = 1 + min(matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]);
            }
        }
    }

    free(matrix[0]);
    free(matrix);

    return matrix[n][m];
}

int main() {
    char str1[MAX_LENGTH], str2[MAX_LENGTH];

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    int distance = levenshtein_distance(str1, str2);

    printf("Levenshtein distance between \"%s\" and \"%s\": %d\n", str1, str2, distance);

    return 0;
}