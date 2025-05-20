//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COINS 5

int main() {
    int n, i, j, k, count, max_count = 0;
    int coins[MAX_COINS];
    int dp[MAX_COINS][1000] = {0};

    printf("Enter the number of coins: ");
    scanf("%d", &n);

    printf("Enter the values of %d coins:\n", n);
    for(i=0; i<n; i++) {
        scanf("%d", &coins[i]);
    }

    for(i=0; i<n; i++) {
        for(j=0; j<MAX_COINS; j++) {
            dp[j][0] = 0;
        }
        dp[0][0] = 1;
        for(k=1; k<=j; k++) {
            for(int l=0; l<MAX_COINS; l++) {
                if(l < k) {
                    dp[l][k] = dp[l][k-1];
                } else if(l == k) {
                    dp[l][k] = (dp[l][k-1] + dp[l-1][k-1]) % 1000000007;
                } else {
                    dp[l][k] = dp[l-1][k];
                }
            }
        }
        count = 0;
        for(k=0; k<MAX_COINS; k++) {
            if(dp[k][j]!= 0) {
                count++;
            }
        }
        if(count > max_count) {
            max_count = count;
        }
    }

    printf("The maximum number of coins that can be made is: %d\n", max_count);

    return 0;
}