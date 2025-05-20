//MISTRAL-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

// Function to find minimum of three numbers
int min(int x, int y, int z) {
    if (x <= y && x <= z)
        return x;
    else if (y <= x && y <= z)
        return y;
    else
        return z;
}

// Function to calculate Levenshtein Distance
int levenshtein_distance(char *str1, char *str2, int m, int n) {
    int d[m + 1][n + 1];

    // Initialization of matrix
    int i, j;
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0)
                d[i][j] = j;
            else if (j == 0)
                d[i][j] = i;
            else if (str1[i - 1] == str2[j - 1])
                d[i][j] = d[i - 1][j - 1];
            else
                d[i][j] = 1 + min(d[i - 1][j], d[i][j - 1], d[i - 1][j - 1]);
        }
    }

    return d[m][n];
}

// Function to check if two strings are identical
int is_identical(char *str1, char *str2, int length1, int length2) {
    if (length1 != length2)
        return 0;

    for (int i = 0; i < length1; i++)
        if (str1[i] != str2[i])
            return 0;

    return 1;
}

// Function to print the result
void print_result(char *str1, char *str2, int distance) {
    if (is_identical(str1, str2, strlen(str1), strlen(str2)))
        printf("The strings are identical.\n");
    else {
        printf("The Levenshtein Distance between %s and %s is %d.\n", str1, str2, distance);
    }
}

int main() {
    char str1[MAX_LENGTH], str2[MAX_LENGTH];
    int length1, length2;

    printf("Enter first string: ");
    scanf("%s", str1);
    length1 = strlen(str1);

    printf("Enter second string: ");
    scanf("%s", str2);
    length2 = strlen(str2);

    int distance = levenshtein_distance(str1, str2, length1, length2);
    print_result(str1, str2, distance);

    return 0;
}