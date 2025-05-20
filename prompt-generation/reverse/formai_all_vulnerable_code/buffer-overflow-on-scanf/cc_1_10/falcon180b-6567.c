//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Alan Turing
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_SIZE 100

int matrix[MAX_SIZE][MAX_SIZE];

void initialize_matrix(int n) {
    int i, j;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= n; j++) {
            matrix[i][j] = i;
        }
    }
}

int minimum(int a, int b, int c) {
    if (a <= b && a <= c) {
        return a;
    } else if (b <= a && b <= c) {
        return b;
    } else {
        return c;
    }
}

int levenshtein_distance(char *s1, char *s2) {
    int n1 = strlen(s1);
    int n2 = strlen(s2);
    int i, j;

    initialize_matrix(n1);
    for (i = 0; i <= n1; i++) {
        matrix[i][0] = i;
    }

    for (i = 0; i <= n2; i++) {
        matrix[0][i] = i;
    }

    for (i = 1; i <= n1; i++) {
        for (j = 1; j <= n2; j++) {
            if (s1[i-1] == s2[j-1]) {
                matrix[i][j] = matrix[i-1][j-1];
            } else {
                matrix[i][j] = minimum(matrix[i-1][j], matrix[i][j-1], matrix[i-1][j-1]) + 1;
            }
        }
    }

    return matrix[n1][n2];
}

int main() {
    char s1[MAX_SIZE], s2[MAX_SIZE];
    int distance;

    printf("Enter first string: ");
    scanf("%s", s1);
    printf("Enter second string: ");
    scanf("%s", s2);

    distance = levenshtein_distance(s1, s2);

    printf("Levenshtein distance: %d\n", distance);

    return 0;
}