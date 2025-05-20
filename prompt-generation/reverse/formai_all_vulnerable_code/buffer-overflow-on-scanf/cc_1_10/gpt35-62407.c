//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Sherlock Holmes
#include<stdio.h>
#include<string.h>

// function to find the minimum of three integers
int min(int a, int b, int c) {
    if(a < b && a < c) {
        return a;
    } else if(b < a && b < c) {
        return b;
    } else {
        return c;
    }
}

// function to find the Levenshtein distance between two strings
int levenshteinDistance(char *s1, char *s2) {
    int m = strlen(s1);
    int n = strlen(s2);

    // dynamic programming matrix
    int dp[m+1][n+1];

    // initializing first row and column of the matrix
    for(int i = 0; i <= m; i++) {
        dp[i][0] = i;
    }

    for(int j = 0; j <= n; j++) {
        dp[0][j] = j;
    }

    // computing the matrix
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1;
            }
        }
    }

    // returning the final answer
    return dp[m][n];
}

int main() {
    printf("Welcome to the Levenshtein Distance Calculator program!\n");
    printf("Please input two strings to find their distance:\n");

    char s1[1000], s2[1000];
    scanf("%s %s", s1, s2);

    int distance = levenshteinDistance(s1, s2);
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", s1, s2, distance);

    printf("Thank you for using the program!\n");
    return 0;
}