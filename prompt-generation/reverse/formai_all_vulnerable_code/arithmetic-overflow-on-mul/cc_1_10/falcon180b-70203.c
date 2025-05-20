//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: Linus Torvalds
/* This is a C program to implement the Greedy Algorithm for the Fractional Knapsack problem. */

#include <stdio.h>
#include <limits.h>

/* Function to find the GCD of two numbers */
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

/* Function to find the LCM of two numbers */
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

/* Function to find the maximum value among two numbers */
int max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

/* Function to implement the Greedy Algorithm for Fractional Knapsack problem */
void fractionalKnapsack(int W, int wt[], int val[], int n) {
    int i, j;
    printf("Value of the items in the knapsack : ");
    for (i = 0; i < n; i++)
        printf("%d ", val[i]);
    printf("\n");
    printf("Weight of the items in the knapsack : ");
    for (i = 0; i < n; i++)
        printf("%d ", wt[i]);
    printf("\n");
    printf("Capacity of the knapsack : %d\n", W);
    for (i = 0; i < n; i++) {
        for (j = 0; j <= W; j++) {
            if (i == 0 || j == 0)
                printf("%d ", 0);
            else if (wt[i] <= j)
                printf("%d ", (val[i] * j) / wt[i]);
            else
                printf("%d ", ((j / wt[i]) * val[i]));
        }
        printf("\n");
    }
    printf("Maximum value that can be obtained : %d\n", (W * max(val[0], val[1])) / lcm(wt[0], wt[1]));
}

/* Driver program to test above functions */
int main() {
    int W, n, i, j;
    printf("Enter the capacity of the knapsack : ");
    scanf("%d", &W);
    printf("Enter the number of items in the knapsack : ");
    scanf("%d", &n);
    int wt[n], val[n];
    printf("Enter the weight and value of each item : ");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &wt[i], &val[i]);
    }
    fractionalKnapsack(W, wt, val, n);
    return 0;
}