//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SIZE 100

bool isEqual(char a, char b) {
    return toupper(a) == toupper(b);
}

int min(int a, int b, int c) {
    return a < b? (a < c? a : c) : (b < c? b : c);
}

int levenshteinDistance(char* str1, char* str2) {
    int m = strlen(str1);
    int n = strlen(str2);
    int dp[MAX_SIZE][MAX_SIZE];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i <= m; i++) {
        dp[i][0] = i;
    }

    for (int j = 0; j <= n; j++) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (isEqual(str1[i - 1], str2[j - 1])) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
            }
        }
    }

    return dp[m][n];
}

int main() {
    char str1[MAX_SIZE];
    char str2[MAX_SIZE];

    printf("Enter string 1: ");
    scanf("%s", str1);

    printf("Enter string 2: ");
    scanf("%s", str2);

    int distance = levenshteinDistance(str1, str2);

    printf("Levenshtein distance between \"%s\" and \"%s\": %d\n", str1, str2, distance);

    return 0;
}