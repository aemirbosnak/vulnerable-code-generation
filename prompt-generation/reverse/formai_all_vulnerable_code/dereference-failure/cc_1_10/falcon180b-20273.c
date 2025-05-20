//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: happy
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 1000

int min(int a, int b, int c) {
    return (a < b)? ((a < c)? a : c) : ((b < c)? b : c);
}

void print_matrix(int **matrix, int size1, int size2) {
    int i, j;
    for(i = 0; i < size1; i++) {
        for(j = 0; j < size2; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int levenshtein_distance(char *s1, char *s2) {
    int size1 = strlen(s1);
    int size2 = strlen(s2);
    int **matrix = (int **)malloc(sizeof(int *) * size1);
    for(int i = 0; i < size1; i++) {
        matrix[i] = (int *)malloc(sizeof(int) * size2);
    }
    int *prev_row = (int *)malloc(sizeof(int) * size2);
    for(int i = 0; i < size2; i++) {
        prev_row[i] = i;
    }
    for(int i = 0; i < size1; i++) {
        matrix[i][0] = i;
    }
    for(int i = 1; i < size2; i++) {
        for(int j = 1; j < size1; j++) {
            if(s1[j - 1] == s2[i - 1]) {
                matrix[j][i] = matrix[j - 1][i - 1];
            } else {
                matrix[j][i] = 1 + min(matrix[j - 1][i], matrix[j][i - 1], prev_row[i - 1]);
            }
            prev_row[i] = matrix[j][i];
        }
    }
    free(prev_row);
    for(int i = 0; i < size1; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return matrix[size1 - 1][size2 - 1];
}

int main() {
    char s1[MAX_SIZE];
    char s2[MAX_SIZE];
    printf("Enter string 1: ");
    scanf("%s", s1);
    printf("Enter string 2: ");
    scanf("%s", s2);
    int distance = levenshtein_distance(s1, s2);
    printf("Levenshtein distance between \"%s\" and \"%s\": %d\n", s1, s2, distance);
    return 0;
}