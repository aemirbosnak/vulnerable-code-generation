//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int min(int a, int b, int c) {
    return a < b? (a < c? a : c) : (b < c? b : c);
}

void print_matrix(int **matrix, int size1, int size2) {
    int i, j;

    for (i = 0; i < size1; i++) {
        for (j = 0; j < size2; j++) {
            printf("%d ", *(matrix + i * size2 + j));
        }
        printf("\n");
    }
}

void levenshtein_distance(char *s1, char *s2, int **matrix) {
    int i, j, size1, size2;

    size1 = strlen(s1);
    size2 = strlen(s2);

    // Initialize the matrix
    for (i = 0; i <= size1; i++) {
        *(matrix + i * (size2 + 1)) = i;
    }
    for (j = 0; j <= size2; j++) {
        *(matrix + (size1 + 1) * j) = j;
    }

    // Fill the matrix
    for (i = 1; i <= size1; i++) {
        for (j = 1; j <= size2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                *(matrix + i * (size2 + 1) + j) = *(matrix + (i - 1) * (size2 + 1) + j - 1) + 1;
            } else {
                *(matrix + i * (size2 + 1) + j) =
                    min(*(matrix + (i - 1) * (size2 + 1) + j),
                        *(matrix + i * (size2 + 1) + j - 1),
                        *(matrix + (i - 1) * (size2 + 1) + j - 1)) + 1;
            }
        }
    }
}

int main() {
    char s1[MAX_SIZE], s2[MAX_SIZE];
    int **matrix;
    int size1, size2, distance;

    printf("Enter first string: ");
    scanf("%s", s1);

    printf("Enter second string: ");
    scanf("%s", s2);

    size1 = strlen(s1);
    size2 = strlen(s2);

    // Allocate memory for the matrix
    matrix = (int **)malloc(sizeof(int *) * (size1 + 1));
    for (int i = 0; i <= size1; i++) {
        *(matrix + i) = (int *)malloc(sizeof(int) * (size2 + 1));
    }

    // Calculate Levenshtein distance
    levenshtein_distance(s1, s2, matrix);

    // Print the matrix
    printf("Levenshtein distance matrix:\n");
    print_matrix(matrix, size1, size2);

    // Print the distance
    distance = *(matrix + size1 * (size2 + 1) - 1);
    printf("\nLevenshtein distance: %d\n", distance);

    // Free memory
    for (int i = 0; i <= size1; i++) {
        free(*(matrix + i));
    }
    free(matrix);

    return 0;
}