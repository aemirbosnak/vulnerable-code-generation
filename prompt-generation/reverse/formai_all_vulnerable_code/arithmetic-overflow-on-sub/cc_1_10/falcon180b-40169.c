//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MAX 100

int n, m, w[MAX], v[MAX];
int dp[MAX][MAX+1];

// Function to find maximum value of two integers
int max(int a, int b) {
    return (a > b)? a : b;
}

// Function to implement greedy algorithm
void knapSack(int idx, int wt) {
    if (idx == 0 || wt == 0)
        return;

    // Check if the current item can be included in the bag
    if (v[idx-1] <= wt) {
        dp[idx-1][wt] = max(dp[idx-1][wt], dp[idx-1][wt-v[idx-1]] + v[idx-1]);
    }

    // Exclude the current item and try for remaining capacity
    knapSack(idx-1, wt);
}

// Function to print the solution
void printSolution(int n, int w[], int v[], int dp[]) {
    printf("Item\tWeight\tValue\n");
    for (int i=0; i<n; i++) {
        if (dp[n-1][w]!= dp[n-1][w-v[i]]) {
            printf("%d\t%d\t%d\n", i+1, v[i], dp[n-1][w-v[i]]);
            w[i] = w[i] - v[i];
        }
    }
}

int main() {
    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the weight and value of each item:\n");
    for (int i=0; i<n; i++) {
        scanf("%d %d", &w[i], &v[i]);
    }

    printf("Enter the maximum weight capacity of the bag: ");
    scanf("%d", &m);

    // Initialize dp array with -1
    for (int i=0; i<=n; i++)
        for (int j=0; j<=m; j++)
            dp[i][j] = -1;

    // Apply greedy algorithm
    knapSack(n, m);

    // Print the solution
    printf("\nThe maximum value that can be obtained is: %d\n", dp[n][m]);
    printSolution(n, w, v, dp);

    return 0;
}