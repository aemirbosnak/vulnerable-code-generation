//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

int levenshtein_distance(char *str1, char *str2, int size1, int size2) {
    int matrix[MAX_SIZE][MAX_SIZE];
    int i, j;

    // Initialize the matrix
    for (i = 0; i <= size1; i++) {
        matrix[i][0] = i;
    }
    for (j = 0; j <= size2; j++) {
        matrix[0][j] = j;
    }

    // Fill the matrix
    for (i = 1; i <= size1; i++) {
        for (j = 1; j <= size2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = matrix[i - 1][j] + 1;
            }
        }
    }

    return matrix[size1][size2];
}

int main() {
    char str1[MAX_SIZE];
    char str2[MAX_SIZE];
    int size1, size2;

    printf("Enter string 1: ");
    scanf("%s", str1);
    size1 = strlen(str1);

    printf("Enter string 2: ");
    scanf("%s", str2);
    size2 = strlen(str2);

    int distance = levenshtein_distance(str1, str2, size1, size2);

    printf("Levenshtein distance between \"%s\" and \"%s\": %d\n", str1, str2, distance);

    return 0;
}