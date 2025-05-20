//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int x, int y, int z) {
    if (x <= y && x <= z) return x;
    if (y <= x && y <= z) return y;
    return z;
}

int levenshtein(char *s1, char *s2) {
    int len_s1 = strlen(s1);
    int len_s2 = strlen(s2);
    int **matrix = (int **) malloc((len_s1 + 1) * sizeof(int*));
    for (int i = 0; i <= len_s1; i++) {
        matrix[i] = (int *) malloc((len_s2 + 1) * sizeof(int));
    }
    for (int i = 1; i <= len_s1; i++) {
        matrix[i][0] = i;
    }
    for (int j = 1; j <= len_s2; j++) {
        matrix[0][j] = j;
    }
    for (int i = 1; i <= len_s1; i++) {
        for (int j = 1; j <= len_s2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = min(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1, matrix[i - 1][j - 1] + 1);
            }
        }
    }
    int distance = matrix[len_s1][len_s2];
    for (int i = 0; i <= len_s1; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return distance;
}

int main(void) {
    char s1[100];
    char s2[100];

    printf("Enter first string: ");
    scanf("%s", s1);

    printf("Enter second string: ");
    scanf("%s", s2);

    int distance = levenshtein(s1, s2);
    printf("Levenshtein distance between %s and %s is %d\n", s1, s2, distance);

    return 0;
}