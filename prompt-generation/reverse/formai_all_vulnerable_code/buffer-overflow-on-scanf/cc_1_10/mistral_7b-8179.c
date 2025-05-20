//MISTRAL-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 100

void print_matrix(char str1[MAX_STRING_LENGTH], char str2[MAX_STRING_LENGTH], int matrix[MAX_STRING_LENGTH][MAX_STRING_LENGTH]) {
    int i, j;

    printf("\n\n");
    printf(" Levenshtein Distance Matrix:\n");
    printf("----------------------------------------------\n");
    printf(" %s | %s \n", str1, str2);
    printf("----------------------------------------------\n");

    for (i = 0; i <= strlen(str1); i++) {
        printf("%2d |", i);
    }
    printf("%s\n", str2);
    printf("----------------------------------------------\n");

    for (i = 0; i <= strlen(str1); i++) {
        printf("%2d ", i);
        for (j = 0; j <= strlen(str2); j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int calculate_levenshtein_distance(char str1[MAX_STRING_LENGTH], char str2[MAX_STRING_LENGTH], int matrix[MAX_STRING_LENGTH][MAX_STRING_LENGTH]) {
    int i, j, cost;

    for (i = 0; i <= strlen(str1); i++) {
        matrix[i][0] = i;
    }

    for (j = 0; j <= strlen(str2); j++) {
        matrix[0][j] = j;
    }

    for (i = 1; i <= strlen(str1); i++) {
        for (j = 1; j <= strlen(str2); j++) {
            if (tolower(str1[i - 1]) == tolower(str2[j - 1])) {
                cost = 0;
            } else {
                cost = 1;
            }

            matrix[i][j] = MIN(1 + MIN(matrix[i - 1][j], matrix[i][j - 1]), cost + matrix[i - 1][j - 1]);
        }
    }

    return matrix[strlen(str1)][strlen(str2)];
}

int MIN(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    char str1[MAX_STRING_LENGTH], str2[MAX_STRING_LENGTH];
    int levenshtein_distance;
    int matrix[MAX_STRING_LENGTH][MAX_STRING_LENGTH];

    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    levenshtein_distance = calculate_levenshtein_distance(str1, str2, matrix);

    print_matrix(str1, str2, matrix);

    printf("\nThe Levenshtein Distance between '%s' and '%s' is %d.\n", str1, str2, levenshtein_distance);

    return 0;
}