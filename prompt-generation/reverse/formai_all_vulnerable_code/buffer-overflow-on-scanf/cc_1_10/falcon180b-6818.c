//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

int levenshtein_distance(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int i, j, k, cost;
    int **matrix;

    if (len1 == 0)
        return len2;
    if (len2 == 0)
        return len1;

    matrix = (int **) malloc(sizeof(int *) * (len1 + 1));
    for (i = 0; i <= len1; i++) {
        matrix[i] = (int *) malloc(sizeof(int) * (len2 + 1));
    }

    for (i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }
    for (j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = matrix[i - 1][j] + 1;
                matrix[i][j] = matrix[i][j - 1] + 1;
                matrix[i][j] = matrix[i - 1][j - 1] + cost;
            }
        }
    }

    free(matrix[0]);
    free(matrix);

    return matrix[len1][len2];
}

int main() {
    char s1[MAX_LENGTH], s2[MAX_LENGTH];

    printf("Enter first string: ");
    scanf("%s", s1);
    printf("Enter second string: ");
    scanf("%s", s2);

    int distance = levenshtein_distance(s1, s2);

    printf("Levenshtein distance between '%s' and '%s': %d\n", s1, s2, distance);

    return 0;
}