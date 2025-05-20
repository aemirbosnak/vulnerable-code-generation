//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main() {
    int n, m, i, j, k, max_profit = 0;
    int jobs[MAX_SIZE][4]; //job id, start time, end time, profit

    //input jobs
    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter job id, start time, end time and profit for job %d: ", i+1);
        scanf("%d %d %d %d", &jobs[i][0], &jobs[i][1], &jobs[i][2], &jobs[i][3]);
    }

    //sort jobs by end time
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (jobs[j][2] > jobs[j+1][2]) {
                //swap jobs
                int temp = jobs[j][0];
                jobs[j][0] = jobs[j+1][0];
                jobs[j+1][0] = temp;

                temp = jobs[j][1];
                jobs[j][1] = jobs[j+1][1];
                jobs[j+1][1] = temp;

                temp = jobs[j][2];
                jobs[j][2] = jobs[j+1][2];
                jobs[j+1][2] = temp;

                temp = jobs[j][3];
                jobs[j][3] = jobs[j+1][3];
                jobs[j+1][3] = temp;
            }
        }
    }

    //greedy algorithm to find maximum profit
    for (i = 0; i < n; i++) {
        int job_profit = jobs[i][3];
        for (j = i+1; j < n; j++) {
            if (jobs[j][1] >= jobs[i][2]) { //make sure job j starts after job i ends
                job_profit += jobs[j][3];
            }
        }
        if (job_profit > max_profit) {
            max_profit = job_profit;
            m = i;
        }
    }

    printf("Maximum profit: %d\n", max_profit);
    printf("Jobs in the optimal solution: ");
    for (i = 0; i <= m; i++) {
        printf("%d ", jobs[i][0]);
    }
    printf("\n");

    return 0;
}