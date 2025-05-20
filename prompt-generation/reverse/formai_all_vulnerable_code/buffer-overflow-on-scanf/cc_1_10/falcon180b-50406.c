//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000

int** create_matrix(int size) {
    int **matrix = (int **)malloc(sizeof(int *) * size);
    for (int i = 0; i < size; i++) {
        matrix[i] = (int *)malloc(sizeof(int) * size);
        for (int j = 0; j < size; j++) {
            matrix[i][j] = 0;
        }
    }
    return matrix;
}

void destroy_matrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int min(int a, int b, int c) {
    return a < b? (a < c? a : c) : (b < c? b : c);
}

int levenshtein_distance(char *s1, char *s2) {
    int size1 = strlen(s1);
    int size2 = strlen(s2);

    if (size1 == 0 || size2 == 0) {
        return abs(size1 - size2);
    }

    int **matrix = create_matrix(size1 + 1);

    for (int i = 0; i <= size1; i++) {
        matrix[i][0] = i;
    }

    for (int j = 0; j <= size2; j++) {
        matrix[0][j] = j;
    }

    for (int i = 1; i <= size1; i++) {
        for (int j = 1; j <= size2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = 1 + min(matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]);
            }
        }
    }

    destroy_matrix(matrix, size1 + 1);

    return matrix[size1][size2];
}

int main() {
    char s1[MAX_SIZE];
    char s2[MAX_SIZE];

    printf("Enter string 1: ");
    scanf("%s", s1);

    printf("Enter string 2: ");
    scanf("%s", s2);

    int distance = levenshtein_distance(s1, s2);

    printf("Levenshtein distance between '%s' and '%s': %d\n", s1, s2, distance);

    return 0;
}