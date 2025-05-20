//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int min3(int a, int b, int c) {
    return a < b? (a < c? a : c) : (b < c? b : c);
}

void print_matrix(int **matrix, int n1, int n2) {
    for (int i = 0; i <= n1; i++) {
        for (int j = 0; j <= n2; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int levenshtein_distance(char *s1, char *s2) {
    int n1 = strlen(s1);
    int n2 = strlen(s2);
    int **matrix = malloc(sizeof(int *) * (n1 + 1));
    for (int i = 0; i <= n1; i++) {
        matrix[i] = malloc(sizeof(int) * (n2 + 1));
    }

    for (int i = 0; i <= n1; i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j <= n2; j++) {
        matrix[0][j] = j;
    }

    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = 1 + min3(matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]);
            }
        }
    }

    int distance = matrix[n1][n2];

    for (int i = n1 - 1; i >= 0; i--) {
        if (matrix[i][n2] == distance) {
            if (s1[i] == s2[n2 - 1]) {
                distance--;
            }
        }
    }

    for (int j = n2 - 1; j >= 0; j--) {
        if (matrix[n1][j] == distance) {
            if (s1[n1 - 1] == s2[j]) {
                distance--;
            }
        }
    }

    free(matrix[0]);
    free(matrix);

    return distance;
}

int main() {
    char s1[MAX_LENGTH];
    char s2[MAX_LENGTH];

    printf("Enter string 1: ");
    scanf("%s", s1);
    printf("Enter string 2: ");
    scanf("%s", s2);

    int distance = levenshtein_distance(s1, s2);

    printf("Levenshtein distance: %d\n", distance);

    return 0;
}