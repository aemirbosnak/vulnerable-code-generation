//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int min(int a, int b, int c) {
    if (a < b && a < c) {
        return a;
    } else if (b < c) {
        return b;
    } else {
        return c;
    }
}

int LevenshteinDistance(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int dp[MAX_LENGTH + 1][MAX_LENGTH + 1];

    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0) {
                dp[i][j] = j;
            } else if (j == 0) {
                dp[i][j] = i;
            } else if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
            }
        }
    }

    return dp[len1][len2];
}

int main() {
    char str1[MAX_LENGTH];
    char str2[MAX_LENGTH];

    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    int distance = LevenshteinDistance(str1, str2);

    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d\n", str1, str2, distance);

    return 0;
}