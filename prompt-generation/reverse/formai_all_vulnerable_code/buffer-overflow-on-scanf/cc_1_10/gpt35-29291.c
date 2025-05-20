//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: asynchronous
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

// async function to calculate Levenshtein Distance
void async_levenshtein(char* str1, char* str2, int* result) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int dp[MAX_LEN][MAX_LEN];
    memset(dp, 0, sizeof(dp));

    // initialize the dp array
    for(int i=0; i<=len1; i++) {
        for(int j=0; j<=len2; j++) {
            if(i==0) {
                dp[i][j] = j;
            }
            else if(j==0) {
                dp[i][j] = i;
            }
            else if(str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                dp[i][j] = 1 + min(min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]);
            }
        }
    }

    // return the result
    *result = dp[len1][len2];
}

// helper function to calculate min of 3 integers
int min(int a, int b) {
    return a<b ? a : b;
}

// main function
int main() {

    // inputs
    char str1[MAX_LEN], str2[MAX_LEN];
    int result;

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    // async call to levenshtein distance calculator
    async_levenshtein(str1, str2, &result);

    // wait for the result
    printf("\nCalculating Levenshtein Distance asynchronously...\n");

    for(int i=0; i<3; i++) {
        printf(".");
        fflush(stdout);
        sleep(1);
    }

    // print the result
    printf("\nLevenshtein Distance between \"%s\" and \"%s\" is %d", str1, str2, result);

    return 0;
}