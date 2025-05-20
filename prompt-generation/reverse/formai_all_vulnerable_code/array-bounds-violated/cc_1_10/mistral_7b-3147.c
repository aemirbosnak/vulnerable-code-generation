//MISTRAL-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Function to calculate the Levenshtein Distance
int levenshtein_distance(const char *str1, const char *str2, int m, int n) {
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0)
                dp[i][j] = j;

            if (j == 0)
                dp[i][j] = i;

            if (tolower(str1[i - 1]) == tolower(str2[j - 1])) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
            }
        }
    }

    return dp[m][n];
}

// Function to find the minimum of three integers
int min(int x, int y, int z) {
    if (x <= y && x <= z)
        return x;

    if (y <= x && y <= z)
        return y;

    return z;
}

int main() {
    char str1[MAX_SIZE];
    char str2[MAX_SIZE];

    printf("Enter first string: ");
    fgets(str1, MAX_SIZE, stdin);
    str1[strcspn(str1, "\n")] = '\0';

    printf("Enter second string: ");
    fgets(str2, MAX_SIZE, stdin);
    str2[strcspn(str2, "\n")] = '\0';

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 > len2) {
        int temp = len1;
        len1 = len2;
        len2 = temp;
    }

    printf("Levenshtein Distance: %d\n", levenshtein_distance(str1, str2, len1, len2));

    return 0;
}