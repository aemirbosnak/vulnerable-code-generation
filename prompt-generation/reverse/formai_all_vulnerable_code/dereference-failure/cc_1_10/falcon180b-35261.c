//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_SIZE 1000

int levenshtein_distance(char *s1, char *s2, int size1, int size2);

int main() {
    char input1[MAX_SIZE], input2[MAX_SIZE];
    int size1, size2;

    printf("Enter the first string: ");
    fgets(input1, MAX_SIZE, stdin);
    size1 = strlen(input1);

    printf("Enter the second string: ");
    fgets(input2, MAX_SIZE, stdin);
    size2 = strlen(input2);

    int distance = levenshtein_distance(input1, input2, size1, size2);

    printf("The Levenshtein distance between '%s' and '%s' is %d\n", input1, input2, distance);

    return 0;
}

int levenshtein_distance(char *s1, char *s2, int size1, int size2) {
    int **matrix;
    int i, j;

    matrix = (int **) malloc(sizeof(int *) * (size1 + 1));
    for (i = 0; i <= size1; i++) {
        matrix[i] = (int *) malloc(sizeof(int) * (size2 + 1));
    }

    for (i = 0; i <= size1; i++) {
        matrix[i][0] = i;
    }
    for (j = 0; j <= size2; j++) {
        matrix[0][j] = j;
    }

    for (i = 1; i <= size1; i++) {
        for (j = 1; j <= size2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = matrix[i - 1][j] + 1;
            }
        }
    }

    int distance = matrix[size1][size2];

    for (i = 0; i <= size1; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return distance;
}