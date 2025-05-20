//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX_STR_LEN 1000
#define MIN_STR_LEN 1

typedef struct {
    char *str;
    int len;
} string_t;

int levenshtein_distance(string_t str1, string_t str2) {
    int i, j, k, n, m, c, d, cost;
    int **matrix;

    n = str1.len;
    m = str2.len;

    matrix = (int **) malloc((n + 1) * sizeof(int *));
    for (i = 0; i <= n; i++) {
        matrix[i] = (int *) malloc((m + 1) * sizeof(int));
    }

    for (i = 0; i <= n; i++) {
        matrix[i][0] = i;
    }

    for (j = 0; j <= m; j++) {
        matrix[0][j] = j;
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            c = tolower(str1.str[i - 1]) - tolower(str2.str[j - 1]);
            if (c == 0) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = matrix[i - 1][j] + 1;
            }
        }
    }

    return matrix[n][m];
}

int main() {
    string_t str1, str2;

    printf("Enter first string: ");
    scanf("%s", str1.str);

    printf("Enter second string: ");
    scanf("%s", str2.str);

    int distance = levenshtein_distance(str1, str2);

    printf("Levenshtein Distance: %d\n", distance);

    return 0;
}