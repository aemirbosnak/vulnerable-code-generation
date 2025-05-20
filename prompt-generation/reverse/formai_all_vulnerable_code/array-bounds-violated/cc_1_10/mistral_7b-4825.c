//MISTRAL-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 100

void print_matrix(int matrix[MAX_LENGTH][MAX_LENGTH], int x, int y) {
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j <= y; j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int levenshtein_distance(char *str1, char *str2, int len1, int len2) {
    int matrix[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }

    for (int j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            matrix[i][j] = 1 + min(matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1] + cost);
        }
    }

    return matrix[len1][len2];
}

int main(void) {
    char str1[MAX_LENGTH];
    char str2[MAX_LENGTH];
    int len1, len2;

    printf("Enter first string: ");
    fgets(str1, MAX_LENGTH, stdin);
    len1 = strlen(str1) - 1;

    printf("Enter second string: ");
    fgets(str2, MAX_LENGTH, stdin);
    len2 = strlen(str2) - 1;

    int distance = levenshtein_distance(str1, str2, len1, len2);

    printf("Levenshtein Distance: %d\n", distance);

    int matrix[len1 + 1][len2 + 1];
    print_matrix(matrix, len1, len2);

    return EXIT_SUCCESS;
}

int min(int x, int y, int z) {
    if (x <= y && x <= z) {
        return x;
    } else if (y <= x && y <= z) {
        return y;
    } else {
        return z;
    }
}