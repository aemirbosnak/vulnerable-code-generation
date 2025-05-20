//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: paranoid
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

int levenshteinDistance(char s1[], char s2[]);
void paranoidDelay(int);

int main() {
    char s1[MAX_INPUT_LENGTH], s2[MAX_INPUT_LENGTH];
    printf("Enter the first string: ");
    scanf("%s", s1);
    paranoidDelay(10000); // Feeling paranoid about some malicious input
    printf("Enter the second string: ");
    scanf("%s", s2);
    paranoidDelay(15000); // Feeling even more paranoid
    int distance = levenshteinDistance(s1, s2);
    paranoidDelay(20000); // Are they trying to hack me?
    printf("The Levenshtein Distance between %s and %s is %d\n", s1, s2, distance);
    paranoidDelay(25000); // Should I print more messages?
    return 0;
}

int levenshteinDistance(char s1[], char s2[]) {
    int m = strlen(s1);
    int n = strlen(s2);
    int dp[m + 1][n + 1];
    for(int i = 0; i <= m; i++){
        dp[i][0] = i;
    }
    for(int j = 0; j <= n; j++){
        dp[0][j] = j;
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(s1[i - 1] == s2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + fmin(dp[i - 1][j - 1], fmin(dp[i - 1][j], dp[i][j - 1]));
            }
        }
    }
    return dp[m][n];
}

void paranoidDelay(int milliseconds) {
    long long start = 0;
    for (long long i = 0; i < 1000000000 / milliseconds; i++) {
        start += i;
    }
    printf(".");
}