//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

// A Job represents a task to be done with a given profit and deadline.
struct Job {
    int profit;
    int deadline;
};

// Comparison function to order jobs by their profit in descending order.
int compareJobs(const void *a, const void *b) {
    const struct Job *job1 = (const struct Job *)a;
    const struct Job *job2 = (const struct Job *)b;
    return job2->profit - job1->profit;
}

// Function to find the maximum profit that can be earned from a set of jobs.
int jobScheduling(struct Job jobs[], int n) {
    // Sort the jobs in descending order of their profit.
    qsort(jobs, n, sizeof(struct Job), compareJobs);

    // Initialize a table to store the maximum profit that can be earned from
    // the first i jobs.
    int dp[n + 1];
    dp[0] = 0;

    // Iterate over the jobs.
    for (int i = 1; i <= n; i++) {
        // Find the latest deadline for which the current job can be scheduled.
        int latestDeadline = jobs[i - 1].deadline;

        // Find the maximum profit that can be earned from the first i - 1 jobs.
        int maxProfit = dp[i - 1];

        // Iterate over the deadlines from the latest deadline to the first deadline.
        for (int j = latestDeadline; j >= 1; j--) {
            // If the current job can be scheduled at deadline j, then update the
            // maximum profit.
            if (j + 1 <= n) {
                maxProfit = fmax(maxProfit, dp[j] + jobs[i - 1].profit);
            }
        }

        // Store the maximum profit that can be earned from the first i jobs.
        dp[i] = maxProfit;
    }

    // Return the maximum profit that can be earned from all the jobs.
    return dp[n];
}

// Main function to test the jobScheduling function.
int main() {
    // Create an array of jobs.
    struct Job jobs[] = {
        { 10, 2 },
        { 5, 1 },
        { 15, 2 },
        { 25, 1 },
        { 15, 3 },
        { 20, 3 }
    };

    // Find the number of jobs.
    int n = sizeof(jobs) / sizeof(jobs[0]);

    // Find the maximum profit that can be earned from the jobs.
    int maxProfit = jobScheduling(jobs, n);

    // Print the maximum profit.
    printf("Maximum profit: %d\n", maxProfit);

    return 0;
}