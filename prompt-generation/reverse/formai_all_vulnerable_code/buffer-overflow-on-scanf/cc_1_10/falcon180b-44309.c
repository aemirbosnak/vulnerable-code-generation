//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, max_profit = 0;
    int jobs[20][3]; // job id, deadline, profit

    // read input
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d %d %d", &jobs[i][0], &jobs[i][1], &jobs[i][2]);
    }

    // sort jobs by deadline
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (jobs[i][1] > jobs[j][1]) {
                int temp = jobs[i][0];
                jobs[i][0] = jobs[j][0];
                jobs[j][0] = temp;
                temp = jobs[i][1];
                jobs[i][1] = jobs[j][1];
                jobs[j][1] = temp;
                temp = jobs[i][2];
                jobs[i][2] = jobs[j][2];
                jobs[j][2] = temp;
            }
        }
    }

    // calculate maximum profit
    for (i = 0; i < n; i++) {
        if (jobs[i][1] <= jobs[i][0]) {
            max_profit += jobs[i][2];
        } else {
            int j;
            for (j = i + 1; j < n; j++) {
                if (jobs[j][1] <= jobs[i][0]) {
                    jobs[j][0] += jobs[i][0] - jobs[i][1] + 1;
                    jobs[j][1] += jobs[i][0] - jobs[i][1] + 1;
                    jobs[i][0] = jobs[i][1] + 1;
                }
            }
            max_profit += jobs[i][2];
        }
    }

    printf("Maximum profit: %d\n", max_profit);
    return 0;
}