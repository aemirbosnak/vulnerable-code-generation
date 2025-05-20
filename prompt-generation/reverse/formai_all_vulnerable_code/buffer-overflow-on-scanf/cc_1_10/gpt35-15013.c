//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX_JOBS 100

typedef struct
{
    int deadline;
    int profit;

} job;

int cmp(const void *a, const void *b)
{
    return (((job*)b)->profit - ((job*)a)->profit);
}

int main()
{
    int n, i, j, maxDeadline = 0, totalProfit = 0;
    job jobs[MAX_JOBS], scheduledJobs[MAX_JOBS];

    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    printf("Enter the values of each job:\n");
    for (i = 0; i < n; i++)
    {
        printf("Job %d - Deadline: ", i+1);
        scanf("%d", &jobs[i].deadline);

        printf("Job %d - Profit: ", i+1);
        scanf("%d", &jobs[i].profit);

        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }

    // Sort the jobs by their profit in non-increasing order
    qsort(jobs, n, sizeof(job), cmp);

    // Schedule jobs according to their deadline and profit
    for (i = 0; i < maxDeadline; i++)
    {
        scheduledJobs[i] = jobs[i];

        for (j = i - 1; j >= 0; j--)
        {
            if (scheduledJobs[j].deadline <= scheduledJobs[j+1].deadline)
                break;

            job temp = scheduledJobs[j];
            scheduledJobs[j] = scheduledJobs[j+1];
            scheduledJobs[j+1] = temp;
        }
    }

    // Calculate the total profit of scheduled jobs
    for (i = 0; i < maxDeadline; i++)
    {
        if (scheduledJobs[i].deadline >= i+1)
            totalProfit += scheduledJobs[i].profit;
    }

    printf("Scheduled Jobs:\n");
    for (i = 0; i < maxDeadline; i++)
    {
        if (scheduledJobs[i].deadline >= i+1)
            printf("Job %d - Deadline: %d, Profit: %d\n", i+1, scheduledJobs[i].deadline, scheduledJobs[i].profit);
    }

    printf("\nTotal Profit: %d\n", totalProfit);

    return 0;
}