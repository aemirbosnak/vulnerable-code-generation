//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: surprised
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRING_LENGTH 100
#define MAX_STRING_NUMBER 10

void print_matrix(int matrix[MAX_STRING_NUMBER + 1][MAX_STRING_NUMBER + 1]) {
    for (int i = 0; i <= MAX_STRING_NUMBER; i++) {
        for (int j = 0; j <= MAX_STRING_NUMBER; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int string_number;
    printf("Enter the number of strings: ");
    scanf("%d", &string_number);

    char *strings[MAX_STRING_NUMBER];
    for (int i = 0; i < string_number; i++) {
        char string[MAX_STRING_LENGTH];
        printf("Enter string %d: ", i + 1);
        scanf("%s", string);
        strings[i] = malloc(strlen(string) + 1);
        strcpy(strings[i], string);
    }

    int matrix[MAX_STRING_NUMBER + 1][MAX_STRING_NUMBER + 1];
    for (int i = 0; i <= string_number; i++) {
        matrix[i][0] = i;
    }

    for (int i = 1; i <= string_number; i++) {
        for (int j = 1; j <= string_number; j++) {
            int cost;
            if (i == j) {
                cost = 0;
            } else if (strcmp(strings[i - 1], strings[j - 1]) == 0) {
                cost = 0;
            } else {
                cost = 1;
            }

            matrix[i][j] = matrix[i - 1][j] + 1;
            for (int k = 1; k <= j; k++) {
                int temp = matrix[i - 1][k] + 1;
                if (temp < matrix[i][j]) {
                    matrix[i][j] = temp;
                }
            }
        }
    }

    printf("The Levenshtein distance matrix:\n");
    print_matrix(matrix);

    for (int i = 0; i < string_number; i++) {
        free(strings[i]);
    }

    return 0;
}