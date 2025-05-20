//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: relaxed
#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {
    if(a <= b && a <= c) {
        return a;
    } else if(b <= a && b <= c) {
        return b;
    } else {
        return c;
    }
}

int levenshtein_distance(char *word1, char *word2, int m, int n) {
    int cost;
    int dp[m+1][n+1];
    
    for(int i=0; i<=m; i++) {
        for(int j=0; j<=n; j++) {
            if(i == 0) {
                dp[i][j] = j;
            } else if(j == 0) {
                dp[i][j] = i;
            } else if(word1[i-1] == word2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                cost = 1;
                dp[i][j] = min(dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1]+cost);
            }
        }
    }

    return dp[m][n];
}

int main() {
    char word1[100], word2[100];
    printf("Enter word1: ");
    scanf("%s", word1);
    printf("Enter word2: ");
    scanf("%s", word2);

    int m = strlen(word1);
    int n = strlen(word2);

    int distance = levenshtein_distance(word1, word2, m, n);

    printf("Levenshtein Distance between %s and %s is %d\n", word1, word2, distance);
    return 0;
}