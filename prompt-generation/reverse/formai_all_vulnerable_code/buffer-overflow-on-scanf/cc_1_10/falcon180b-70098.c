//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int levenshtein_distance(char *str1, char *str2, int size) {
    int i, j, cost, **matrix;
    char *string1 = strdup(str1);
    char *string2 = strdup(str2);
    int len1 = strlen(string1);
    int len2 = strlen(string2);

    if (len1 > size || len2 > size) {
        printf("Error: Strings are too long.\n");
        exit(EXIT_FAILURE);
    }

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
            if (string1[i - 1] == string2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                cost = matrix[i - 1][j] + 1;
                if (cost > matrix[i][j - 1] + 1) {
                    matrix[i][j] = matrix[i - 1][j] + 1;
                } else if (cost < matrix[i][j - 1] + 1) {
                    matrix[i][j] = matrix[i][j - 1] + 1;
                } else {
                    matrix[i][j] = matrix[i - 1][j];
                }
            }
        }
    }

    free(string1);
    free(string2);
    for (i = 0; i <= len1; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return matrix[len1][len2];
}

int main(int argc, char **argv) {
    char *str1, *str2;
    int size;

    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    printf("Enter the maximum size: ");
    scanf("%d", &size);

    int distance = levenshtein_distance(str1, str2, size);

    printf("Levenshtein distance: %d\n", distance);

    return 0;
}