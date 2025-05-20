//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int main() {
    int n, i, j, k, count = 0, index = 0;
    int jobs[MAX], profit[MAX], deadline[MAX];
    int job_index[MAX], available_time[MAX];

    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    printf("Enter the details of the jobs:\n");
    for (i = 0; i < n; i++) {
        printf("Job %d:\n", i+1);
        printf("Enter the profit: ");
        scanf("%d", &profit[i]);
        printf("Enter the deadline: ");
        scanf("%d", &deadline[i]);
    }

    printf("Enter the number of time slots available: ");
    scanf("%d", &k);

    for (i = 0; i < k; i++) {
        available_time[i] = i + 1;
    }

    for (i = 0; i < n; i++) {
        job_index[i] = -1;
    }

    printf("Job  Index  Deadline  Profit\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < k; j++) {
            if (deadline[i] <= available_time[j]) {
                if (j == 0) {
                    job_index[i] = j;
                    printf("%d  %d  %d  %d\n", i+1, j, deadline[i], profit[i]);
                } else if (profit[i] > profit[job_index[i]]) {
                    job_index[i] = j;
                    printf("%d  %d  %d  %d\n", i+1, j, deadline[i], profit[i]);
                }
            }
        }
    }

    printf("\nThe selected jobs are:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", job_index[i]);
    }

    return 0;
}