//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct Interval {
    int start;
    int end;
    int profit;
};

int compare(const void *a, const void *b) {
    struct Interval *ia = (struct Interval *)a;
    struct Interval *ib = (struct Interval *)b;
    if (ia->end < ib->end) {
        return -1;
    } else if (ia->end > ib->end) {
        return 1;
    } else {
        return 0;
    }
}

int maxProfit(int *profit, int n) {
    qsort(profit, n, sizeof(int), compare);
    int max_profit = 0;
    for (int i = 0; i < n; i++) {
        max_profit += profit[i];
    }
    return max_profit;
}

int main() {
    int n;
    scanf("%d", &n);
    struct Interval *intervals = (struct Interval *)malloc(n * sizeof(struct Interval));
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &intervals[i].start, &intervals[i].end, &intervals[i].profit);
    }
    int *profits = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        profits[i] = intervals[i].profit;
    }
    int max_profit = maxProfit(profits, n);
    printf("%d\n", max_profit);
    free(intervals);
    free(profits);
    return 0;
}