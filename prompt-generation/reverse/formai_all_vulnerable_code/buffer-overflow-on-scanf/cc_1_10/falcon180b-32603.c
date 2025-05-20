//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 100

void print_matrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j <= size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int min(int a, int b) {
    return a < b? a : b;
}

int levenshtein_distance(char *str1, char *str2) {
    int size1 = strlen(str1);
    int size2 = strlen(str2);
    int **matrix = (int **)malloc(sizeof(int *) * size2);
    for (int i = 0; i < size2; i++) {
        matrix[i] = (int *)malloc(sizeof(int) * size1);
        memset(matrix[i], 0, sizeof(int) * size1);
    }
    for (int i = 0; i < size1; i++) {
        matrix[0][i] = i;
    }
    for (int i = 0; i < size2; i++) {
        matrix[i][0] = i;
    }
    for (int i = 1; i < size2; i++) {
        for (int j = 1; j < size1; j++) {
            if (str1[j - 1] == str2[i - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = min(matrix[i - 1][j], matrix[i][j - 1]) + 1;
            }
        }
    }
    int distance = matrix[size2 - 1][size1 - 1];
    for (int i = 0; i < size2; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return distance;
}

int main() {
    char str1[MAX_LENGTH];
    char str2[MAX_LENGTH];
    printf("Enter string 1: ");
    scanf("%s", str1);
    printf("Enter string 2: ");
    scanf("%s", str2);
    int distance = levenshtein_distance(str1, str2);
    printf("Levenshtein distance between \"%s\" and \"%s\": %d\n", str1, str2, distance);
    return 0;
}