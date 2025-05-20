//Falcon2-11B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: interoperable
#include <stdio.h>
#include <string.h>

// Function to calculate Levenshtein distance
int levenshteinDistance(char* str1, char* str2) {
    int m = strlen(str1);
    int n = strlen(str2);

    // Create a 2D array to store the distances
    int dp[m+1][n+1];

    // Initialize the first row and column of the array with 0
    for (int i = 0; i <= m; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = j;
    }

    // Fill the array with the distances
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int cost = 0;

            // If characters are the same, cost = 0
            if (str1[i-1] == str2[j-1]) {
                cost = 0;
            }

            // If characters are different, cost = 1
            else {
                cost = 1;
            }

            // Calculate the minimum of three options:
            // 1. Insert a character at current position
            // 2. Delete a character at current position
            // 3. Replace a character at current position
            dp[i][j] = dp[i-1][j] + cost;
            dp[i][j] = dp[i][j-1] + cost;
            dp[i][j] = dp[i-1][j-1] + cost;
        }
    }

    return dp[m][n];
}

int main() {
    char str1[100], str2[100];

    printf("Enter two strings:\n");
    scanf("%s %s", str1, str2);

    int distance = levenshteinDistance(str1, str2);
    printf("Levenshtein distance: %d\n", distance);

    return 0;
}