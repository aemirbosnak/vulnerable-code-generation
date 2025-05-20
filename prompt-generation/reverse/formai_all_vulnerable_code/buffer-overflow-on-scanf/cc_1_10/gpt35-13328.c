//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100
#define MAX_K 1000

int P[MAX_N], B[MAX_N], N, K;

int comp(const void *a, const void *b) {
    int x = *(int*)a, y = *(int*)b;
    return y - x;
}

int solve() {
    int i, j, max, res = 0;

    for (i = 1; i <= N; i++) {
        max = 0;
        for (j = 1; j <= N; j++) {
            if (max < P[j] && B[j] <= K) {
                max = P[j];
                res += P[j];
                K -= B[j];
            }
        }
    }

    return res;
}

int main() {
    int i;

    printf("Enter the number of items: ");
    scanf("%d", &N);

    printf("Enter the capacity of the bag: ");
    scanf("%d", &K);

    printf("Enter the weight and profit of each item:\n");
    for (i = 1; i <= N; i++) {
        scanf("%d %d", &B[i], &P[i]);
    }

    qsort(P + 1, N, sizeof(int), comp);

    printf("The maximum profit that can be obtained is: %d\n", solve());
    
    return 0;
}