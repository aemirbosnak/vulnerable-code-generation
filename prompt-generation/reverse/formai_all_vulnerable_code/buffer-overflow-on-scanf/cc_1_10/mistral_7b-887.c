//MISTRAL-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000

// Function to find minimum of three integers
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

    // Initialization of first row and column
    for (int i = 0; i <= m; i++) {
        d[i][0] = i;
    }

    for (int j = 0; j <= n; j++) {
        d[0][j] = j;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;

            d[i][j] = min(d[i - 1][j] + 1,
                         d[i][j - 1] + 1,
                         d[i - 1][j - 1] + cost);
        }
    }

    return d[m][n];
}

int main() {
    char str1[MAX_STRING_LENGTH], str2[MAX_STRING_LENGTH];
    int m, n;

    printf("Enter first string: ");
    scanf("%s", str1);
    m = strlen(str1);

    printf("Enter second string: ");
    scanf("%s", str2);
    n = strlen(str2);

    printf("Levenshtein Distance between '%s' and '%s': %d\n", str1, str2, levenshtein_distance(str1, str2, m, n));

    return 0;
}