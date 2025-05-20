//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#define MAX_LEN 100

int calculateLevenshteinDistance(char str1[], int len1, char str2[], int len2) {
    int i, j;
    int dp[MAX_LEN][MAX_LEN];

    for(i = 0; i <= len1; i++) {
        for(j = 0; j <= len2; j++) {
            if(i == 0) {
                dp[i][j] = j;
            } else if(j == 0) {
                dp[i][j] = i;
            } else if(str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + min(dp[i][j-1], dp[i-1][j-1], dp[i-1][j]);
            }
        }
    }

    return dp[len1][len2];
}

int min(int x, int y, int z) {
    if(x <= y && x <= z) {
        return x;
    } else if(y <= x && y <= z) {
        return y;
    } else {
        return z;
    }
}

int main() {
    char str1[MAX_LEN], str2[MAX_LEN];
    int len1, len2;

    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);

    len1 = strlen(str1);
    len2 = strlen(str2);

    int distance = calculateLevenshteinDistance(str1, len1, str2, len2);

    printf("The Levenshtein Distance between '%s' and '%s' is %d", str1, str2, distance);

    return 0;
}