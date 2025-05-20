//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int levenshtein_distance(char* str1, char* str2, int size1, int size2) {
    int** matrix = (int**)malloc(sizeof(int*) * (size1 + 1));
    for (int i = 0; i <= size1; i++) {
        matrix[i] = (int*)malloc(sizeof(int) * (size2 + 1));
        memset(matrix[i], 0, sizeof(int) * (size2 + 1));
    }

    // Initialize first row and column
    for (int i = 0; i <= size1; i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j <= size2; j++) {
        matrix[0][j] = j;
    }

    // Calculate Levenshtein distance
    for (int i = 1; i <= size1; i++) {
        for (int j = 1; j <= size2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = matrix[i - 1][j] + 1;
                matrix[i][j] = matrix[i][j - 1] + 1;
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            }
        }
    }

    // Free memory
    for (int i = 0; i <= size1; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return matrix[size1][size2];
}

int main() {
    char str1[MAX_SIZE], str2[MAX_SIZE];
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);

    int size1 = strlen(str1);
    int size2 = strlen(str2);

    int distance = levenshtein_distance(str1, str2, size1, size2);

    printf("Levenshtein distance between '%s' and '%s': %d\n", str1, str2, distance);

    return 0;
}