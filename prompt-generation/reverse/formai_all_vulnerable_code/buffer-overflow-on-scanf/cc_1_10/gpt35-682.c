//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100

int min(int a, int b, int c) {
    int min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    return min;
}

int levenshtein_distance(char *s1, char *s2) {
    int m = strlen(s1);
    int n = strlen(s2);
    int dp[m+1][n+1];

    for(int i = 0; i <= m; i++) {
        dp[i][0] = i;
    }

    for(int j = 0; j <= n; j++) {
        dp[0][j] = j;
    }

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            int cost = (s1[i-1] == s2[j-1]) ? 0 : 1;
            dp[i][j] = min(dp[i-1][j] + 1,
                            dp[i][j-1] + 1,
                            dp[i-1][j-1] + cost);
        }
    }
    return dp[m][n];
}

int main() {
    char str1[MAX_STR_LEN];
    char str2[MAX_STR_LEN];

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    int distance = levenshtein_distance(str1, str2);

    printf("Levenshtein distance between %s and %s is %d\n", str1, str2, distance);

    return 0;
}