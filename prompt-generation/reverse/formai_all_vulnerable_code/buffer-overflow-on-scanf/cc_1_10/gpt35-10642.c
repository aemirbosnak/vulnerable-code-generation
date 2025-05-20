//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: medieval
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

// Function to calculate the minimum of three values
int minimum(int a, int b, int c) {
    if (a <= b && a <= c) {
        return a;
    } else if (b <= a && b <= c) {
        return b;
    } else {
        return c;
    }
}

// Function to calculate the Levenshtein distance
int levenshtein_distance(char *string1, char *string2) {
    int m = strlen(string1);
    int n = strlen(string2);
    int matrix[MAX_LENGTH][MAX_LENGTH];
    int i, j, cost;

    // Initialize the matrix
    for (i = 0; i <= m; i++) {
        matrix[i][0] = i;
    }

    for (j = 1; j <= n; j++) {
        matrix[0][j] = j;
    }

    // Calculate the Levenshtein distance
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            cost = string1[i - 1] == string2[j - 1] ? 0 : 1;
            matrix[i][j] = minimum(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1, matrix[i - 1][j - 1] + cost);
        }
    }

    return matrix[m][n];
}

int main() {
    char string1[MAX_LENGTH], string2[MAX_LENGTH];
    int distance;

    printf("Input string 1: ");
    scanf("%s", string1);

    printf("Input string 2: ");
    scanf("%s", string2);

    distance = levenshtein_distance(string1, string2);

    printf("The Levenshtein distance between %s and %s is %d", string1, string2, distance);

    return 0;
}