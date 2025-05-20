//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

int min(int a, int b, int c) {
    return a < b? (a < c? a : c) : (b < c? b : c);
}

int levenshtein_distance(char *str1, char *str2) {
    int i, j, cost, length1, length2, **matrix;

    length1 = strlen(str1);
    length2 = strlen(str2);

    if (length1 == 0) {
        return length2;
    } else if (length2 == 0) {
        return length1;
    }

    matrix = (int **)malloc(sizeof(int *) * (length1 + 1));
    for (i = 0; i <= length1; i++) {
        matrix[i] = (int *)malloc(sizeof(int) * (length2 + 1));
        for (j = 0; j <= length2; j++) {
            if (i == 0 || j == 0) {
                matrix[i][j] = i + j;
            } else if (str1[i - 1] == str2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                cost = 1;
                matrix[i][j] = min(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1, matrix[i - 1][j - 1] + cost);
            }
        }
    }

    free(matrix[length1]);
    free(matrix);

    return matrix[length1][length2];
}

int main() {
    char str1[MAX_LENGTH], str2[MAX_LENGTH];

    printf("Enter string 1: ");
    scanf("%s", str1);

    printf("Enter string 2: ");
    scanf("%s", str2);

    int distance = levenshtein_distance(str1, str2);

    printf("Levenshtein distance between '%s' and '%s': %d\n", str1, str2, distance);

    return 0;
}