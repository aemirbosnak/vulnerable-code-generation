//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

void print_matrix(int **matrix, int size1, int size2) {
    for (int i = 0; i <= size1; i++) {
        for (int j = 0; j <= size2; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int min(int a, int b, int c) {
    return (a < b)? ((a < c)? a : c) : ((b < c)? b : c);
}

int levenshtein_distance(char *s1, char *s2) {
    int size1 = strlen(s1);
    int size2 = strlen(s2);

    int **matrix = (int **)malloc(sizeof(int *) * (size1 + 1));
    for (int i = 0; i <= size1; i++) {
        matrix[i] = (int *)malloc(sizeof(int) * (size2 + 1));
    }

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

    int result = matrix[size1][size2];

    for (int i = size1; i >= 0; i--) {
        free(matrix[i]);
    }
    free(matrix);

    return result;
}

int main() {
    char s1[MAX_SIZE], s2[MAX_SIZE];

    printf("Enter first string: ");
    scanf("%s", s1);

    printf("Enter second string: ");
    scanf("%s", s2);

    int distance = levenshtein_distance(s1, s2);

    printf("Levenshtein distance: %d\n", distance);

    return 0;
}