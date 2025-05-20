//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

int lev_distance(char *str1, char *str2);

int main(){
    printf("Welcome to the Levenshtein Distance Calculator 2077\n");

    char str1[30], str2[30];
    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);

    int distance = lev_distance(str1, str2);
    printf("\nCalculating...\n");
    printf("The Levenshtein Distance between %s and %s is: %d\n", str1, str2, distance);

    if(distance <= 10) {
        printf("Acceptable difference. Access granted.\n");
    } else {
        printf("Exceeded acceptable difference. Access denied. Initiating security protocol.\n");
        // code for initiating security protocol
    }

    return 0;
}

int lev_distance(char *str1, char *str2) {
    int len1 = strlen(str1) - 1;
    int len2 = strlen(str2) - 1;

    int dp[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0) {
                dp[i][j] = j;
            } else if (j == 0) {
                dp[i][j] = i;
            } else if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + (dp[i][j-1] > dp[i-1][j] ? dp[i-1][j] : dp[i][j-1]);
            }
        }
    }

    return dp[len1][len2];
}