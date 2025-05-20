//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

void print_matrix(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int min(int a, int b, int c) {
    return (a < b)? ((a < c)? a : c) : ((b < c)? b : c);
}

int levenshtein_distance(char* s1, char* s2) {
    int n = strlen(s1);
    int m = strlen(s2);
    int** matrix = (int**) malloc(sizeof(int*) * (n + 1));
    for (int i = 0; i <= n; i++) {
        matrix[i] = (int*) malloc(sizeof(int) * (m + 1));
        for (int j = 0; j <= m; j++) {
            if (i == 0) {
                matrix[i][j] = j;
            } else if (j == 0) {
                matrix[i][j] = i;
            } else {
                if (s1[i-1] == s2[j-1]) {
                    matrix[i][j] = matrix[i-1][j-1];
                } else {
                    matrix[i][j] = 1 + min(matrix[i-1][j], matrix[i][j-1], matrix[i-1][j-1]);
                }
            }
        }
    }
    int distance = matrix[n][m];
    for (int i = 0; i <= n; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return distance;
}

int main() {
    char string1[MAX_LENGTH];
    char string2[MAX_LENGTH];
    printf("Enter first string: ");
    scanf("%s", string1);
    printf("Enter second string: ");
    scanf("%s", string2);
    int distance = levenshtein_distance(string1, string2);
    printf("Levenshtein distance between '%s' and '%s': %d\n", string1, string2, distance);
    return 0;
}