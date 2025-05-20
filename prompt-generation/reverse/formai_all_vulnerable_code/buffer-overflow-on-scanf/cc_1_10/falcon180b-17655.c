//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

int min(int a, int b, int c) {
    int min_val = a;
    if (b < min_val) {
        min_val = b;
    }
    if (c < min_val) {
        min_val = c;
    }
    return min_val;
}

int levenshtein_distance(char *str1, char *str2) {
    int m = strlen(str1);
    int n = strlen(str2);
    int matrix[MAX_SIZE][MAX_SIZE];
    int i, j;

    for (i = 0; i <= m; i++) {
        matrix[i][0] = i;
    }
    for (j = 0; j <= n; j++) {
        matrix[0][j] = j;
    }

    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = min(matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]) + 1;
            }
        }
    }

    return matrix[m][n];
}

int main() {
    char str1[MAX_SIZE];
    char str2[MAX_SIZE];

    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);

    int distance = levenshtein_distance(str1, str2);

    printf("Levenshtein distance: %d\n", distance);

    return 0;
}