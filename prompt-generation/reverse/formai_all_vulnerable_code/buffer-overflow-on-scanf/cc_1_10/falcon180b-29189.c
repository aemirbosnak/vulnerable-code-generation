//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

void print_matrix(int **matrix, int length1, int length2) {
    int i, j;
    for (i = 0; i <= length1; i++) {
        for (j = 0; j <= length2; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int min(int a, int b, int c) {
    return a < b? (a < c? a : c) : (b < c? b : c);
}

int levenshtein_distance(char *s1, char *s2) {
    int length1 = strlen(s1);
    int length2 = strlen(s2);
    int **matrix = malloc(sizeof(int *) * (length1 + 1));
    for (int i = 0; i <= length1; i++) {
        matrix[i] = malloc(sizeof(int) * (length2 + 1));
    }
    for (int i = 0; i <= length1; i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j <= length2; j++) {
        matrix[0][j] = j;
    }
    for (int i = 1; i <= length1; i++) {
        for (int j = 1; j <= length2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = 1 + min(matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]);
            }
        }
    }
    int distance = matrix[length1][length2];
    for (int i = 0; i <= length1; i++) {
        free(matrix[i]);
    }
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
    printf("Levenshtein distance between '%s' and '%s' is %d\n", s1, s2, distance);
    return 0;
}