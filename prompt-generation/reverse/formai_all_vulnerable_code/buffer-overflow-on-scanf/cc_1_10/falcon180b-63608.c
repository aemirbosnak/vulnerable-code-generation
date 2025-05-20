//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 1000

int min(int a, int b, int c) {
    return a < b? (a < c? a : c) : (b < c? b : c);
}

void print_matrix(int **matrix, int length1, int length2) {
    for (int i = 0; i <= length1; i++) {
        for (int j = 0; j <= length2; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int levenshtein_distance(char *str1, char *str2) {
    int length1 = strlen(str1);
    int length2 = strlen(str2);

    int **matrix = (int **)malloc(sizeof(int *) * (length1 + 1));
    for (int i = 0; i <= length1; i++) {
        matrix[i] = (int *)malloc(sizeof(int) * (length2 + 1));
    }

    for (int i = 0; i <= length1; i++) {
        matrix[i][0] = i;
    }

    for (int j = 0; j <= length2; j++) {
        matrix[0][j] = j;
    }

    for (int i = 1; i <= length1; i++) {
        for (int j = 1; j <= length2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = 1 + min(matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]);
            }
        }
    }

    int distance = matrix[length1][length2];

    for (int i = length1 - 1; i >= 0; i--) {
        if (matrix[i][length2] == distance) {
            if (str1[i] == str2[length2 - 1]) {
                strcat(str1, &str2[length2 - 1]);
            } else {
                strcat(str1, "");
            }
            break;
        }
    }

    for (int j = length2 - 1; j >= 0; j--) {
        if (matrix[length1][j] == distance) {
            if (str2[j] == str1[length1 - 1]) {
                strcat(str2, &str1[length1 - 1]);
            } else {
                strcat(str2, "");
            }
            break;
        }
    }

    free(matrix[0]);
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

    printf("Levenshtein distance: %d\n", distance);

    return 0;
}