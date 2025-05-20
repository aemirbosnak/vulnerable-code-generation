//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int levenshtein_distance(char *str1, char *str2, int length1, int length2) {
    int i, j, cost, **matrix;
    int min_cost = 0;

    if (length1 > MAX_LENGTH || length2 > MAX_LENGTH) {
        printf("Error: Input strings are too long.\n");
        return -1;
    }

    matrix = (int **)malloc(sizeof(int *) * (length1 + 1));
    for (i = 0; i <= length1; i++) {
        matrix[i] = (int *)malloc(sizeof(int) * (length2 + 1));
    }

    for (i = 0; i <= length1; i++) {
        matrix[i][0] = i;
    }

    for (j = 0; j <= length2; j++) {
        matrix[0][j] = j;
    }

    for (i = 1; i <= length1; i++) {
        for (j = 1; j <= length2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                cost = 0;
            } else {
                cost = 1;
            }

            matrix[i][j] = matrix[i - 1][j] + 1;

            if (matrix[i - 1][j] > matrix[i][j - 1] + cost) {
                matrix[i][j] = matrix[i - 1][j];
            }

            if (matrix[i][j - 1] > matrix[i - 1][j] + cost) {
                matrix[i][j] = matrix[i][j - 1];
            }

            if (matrix[i][j] < min_cost) {
                min_cost = matrix[i][j];
            }
        }
    }

    free(matrix[0]);
    free(matrix);

    return min_cost;
}

int main() {
    char str1[MAX_LENGTH], str2[MAX_LENGTH];

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    int length1 = strlen(str1);
    int length2 = strlen(str2);

    int distance = levenshtein_distance(str1, str2, length1, length2);

    if (distance == -1) {
        return 1;
    }

    printf("Levenshtein distance: %d\n", distance);

    return 0;
}