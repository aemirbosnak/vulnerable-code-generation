//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int levenshteinDistance(char* str1, char* str2, int size1, int size2) {
    int i, j, k, cost;
    int** matrix = (int**)malloc(sizeof(int*) * (size1 + 1));
    for(i = 0; i <= size1; i++) {
        matrix[i] = (int*)malloc(sizeof(int) * (size2 + 1));
        for(j = 0; j <= size2; j++) {
            matrix[i][j] = 0;
        }
    }

    for(i = 0; i <= size1; i++) {
        matrix[i][0] = i;
    }

    for(j = 0; j <= size2; j++) {
        matrix[0][j] = j;
    }

    for(i = 1; i <= size1; i++) {
        for(j = 1; j <= size2; j++) {
            if(str1[i - 1] == str2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = matrix[i - 1][j] + 1;
                matrix[i][j] = matrix[i][j - 1] + 1;
                matrix[i][j] = matrix[i - 1][j - 1] + cost;
            }
        }
    }

    free(matrix[0]);
    free(matrix);

    return matrix[size1][size2];
}

int main() {
    char str1[MAX_SIZE], str2[MAX_SIZE];
    int size1, size2;

    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);

    size1 = strlen(str1);
    size2 = strlen(str2);

    int distance = levenshteinDistance(str1, str2, size1, size2);

    printf("Levenshtein Distance: %d\n", distance);

    return 0;
}