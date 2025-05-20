//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

// Structure to represent a job
struct Job {
    int id;
    int profit;
    int deadline;
};

// Function to sort jobs based on their deadlines
int compare(const void *a, const void *b) {
    struct Job *jobA = (struct Job *)a;
    struct Job *jobB = (struct Job *)b;
    return (jobA->deadline - jobB->deadline);
}

// Function to find the maximum profit job that can be done by the given deadline
int JobScheduling(struct Job jobs[], int n) {
    int slot = 0, i;

    // Sort all the jobs based on their deadlines
    qsort(jobs, n, sizeof(struct Job), compare);

    // Iterate through all the jobs
    for (i = 0; i < n; i++) {
        // If the given job can be done before or on the current deadline, then include it
        if (jobs[i].deadline > slot) {
            slot = jobs[i].deadline;
            printf("Job %d is scheduled at slot %d with a profit of %d\n", jobs[i].id, slot, jobs[i].profit);
        }
    }

    // Return the maximum profit
    return slot;
}

// Driver code
int main() {
    struct Job jobs[MAX];
    int n, i, profit;

    // Read the number of jobs
    scanf("%d", &n);

    // Read the details of all the jobs
    for (i = 0; i < n; i++) {
        scanf("%d%d", &jobs[i].id, &jobs[i].profit);
        jobs[i].deadline = jobs[i].profit;
    }

    // Call the JobScheduling function
    profit = JobScheduling(jobs, n);

    // Print the maximum profit
    printf("The maximum profit is %d", profit);

    return 0;
}