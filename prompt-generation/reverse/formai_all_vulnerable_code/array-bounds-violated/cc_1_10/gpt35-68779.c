//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: retro
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/* function to calculate the minimum of 3 integers */
int min(int x, int y, int z) {
    return (x < y) ? ((x < z) ? x : z) : ((y < z) ? y : z);
}

/* function to calculate the Levenshtein distance */
int levenshtein(const char *str1, const char *str2, int m, int n) {
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            /* if the first string is empty, insert all characters of the second string */
            if (i == 0) {
                dp[i][j] = j;
            }
            /* if the second string is empty, delete all characters of the first string */
            else if (j == 0) {
                dp[i][j] = i;
            }
            /* if the last characters are same, no operation required */
            else if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            /* if the last characters are different, find the minimum of all operations */
            else {
                dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]);
            }
        }
    }

    /* return the Levenshtein distance */
    return dp[m][n];
}

int main() {
    /* input the strings from the user */
    char str1[100], str2[100];
    printf("Enter first string: ");
    fgets(str1, 100, stdin);
    printf("Enter second string: ");
    fgets(str2, 100, stdin);

    /* convert the strings to lowercase */
    int m = strlen(str1), n = strlen(str2);
    for (int i = 0; i < m; i++) {
        str1[i] = tolower(str1[i]);
    }
    for (int i = 0; i < n; i++) {
        str2[i] = tolower(str2[i]);
    }

    /* remove newline character from the strings */
    if (str1[m - 1] == '\n') {
        str1[m - 1] = '\0';
    }
    if (str2[n - 1] == '\n') {
        str2[n - 1] = '\0';
    }

    /* calculate the Levenshtein distance */
    int distance = levenshtein(str1, str2, m, n);
    printf("Levenshtein distance: %d\n", distance);

    return 0;
}