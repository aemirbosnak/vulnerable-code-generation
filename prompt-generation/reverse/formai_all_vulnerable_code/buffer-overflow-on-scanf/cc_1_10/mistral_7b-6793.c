//MISTRAL-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

// Function to calculate the Levenshtein Distance using dynamic programming approach
int levenshtein_distance(char *str1, char *str2, int m, int n) {
    int matrix[m + 1][n + 1];

    // Initialization of the matrix with the first row and column
    for (int i = 0; i <= m; i++) {
        matrix[i][0] = i;
    }

    for (int j = 0; j <= n; j++) {
        matrix[0][j] = j;
    }

    // Calculate the Levenshtein Distance
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = 1 + min(matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]);
            }
        }
    }

    return matrix[m][n];
}

int min(int a, int b, int c) {
    if (a <= b && a <= c) {
        return a;
    } else if (b <= a && b <= c) {
        return b;
    } else {
        return c;
    }
}

// Function to check if the given strings are valid for the Levenshtein Distance Calculator
int is_valid_input(char *str1, char *str2) {
    int m = strlen(str1), n = strlen(str2);

    if (m <= MAX_STRING_LENGTH && n <= MAX_STRING_LENGTH) {
        return 1;
    } else {
        printf("Error: Input strings are too long.\n");
        return 0;
    }
}

int main() {
    char str1[MAX_STRING_LENGTH], str2[MAX_STRING_LENGTH];
    int distance;

    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    if (is_valid_input(str1, str2)) {
        distance = levenshtein_distance(str1, str2, strlen(str1), strlen(str2));
        printf("Levenshtein Distance: %d\n", distance);
    }

    return 0;
}