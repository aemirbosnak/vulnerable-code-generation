//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: configurable
#include <stdio.h>

// A struct to represent a job
struct Job {
    int id;
    int deadline;
    int profit;
};

// Function to sort jobs based on profit in descending order
void sortJobsByProfit(struct Job jobs[], int numJobs) {
    int i, j;
    struct Job tempJob;
    for (i = 0; i < numJobs - 1; i++) {
        for (j = i + 1; j < numJobs; j++) {
            if (jobs[i].profit < jobs[j].profit) {
                tempJob = jobs[i];
                jobs[i] = jobs[j];
                jobs[j] = tempJob;
            }
        }
    }
}

// Function to schedule jobs by deadline using Greedy Algorithm
void scheduleJobsByDeadline(struct Job jobs[], int numJobs) {
    int i, j, k;
    int maxDeadline = 0;
    int totalProfit = 0;
    int scheduledJobs[numJobs];
    // Initialize all jobs as not scheduled
    for (i = 0; i < numJobs; i++) {
        scheduledJobs[i] = 0;
    }
    // Sort jobs by profit in descending order
    sortJobsByProfit(jobs, numJobs);
    // Find maximum deadline among all jobs
    for (i = 0; i < numJobs; i++) {
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
        }
    }
    // Schedule jobs for each deadline in descending order
    for (i = maxDeadline; i >= 1; i--) {
        // Find the job with maximum profit among all unscheduled jobs
        for (j = 0; j < numJobs; j++) {
            if (!scheduledJobs[j] && jobs[j].deadline >= i) {
                break;
            }
        }
        // Schedule the job if it exists
        if (j < numJobs) {
            totalProfit += jobs[j].profit;
            scheduledJobs[j] = 1;
        }
    }
    // Print the scheduled jobs and total profit
    printf("Scheduled jobs:\n");
    for (i = 0; i < numJobs; i++) {
        if (scheduledJobs[i]) {
            printf("Job %d\n", jobs[i].id);
        }
    }
    printf("Total profit: %d\n", totalProfit);
}

// Driver function
int main() {
    int numJobs, i;
    printf("Enter the number of jobs: ");
    scanf("%d", &numJobs);
    struct Job jobs[numJobs];
    // Read data for each job from user
    for (i = 0; i < numJobs; i++) {
        printf("Enter data for Job %d:\n", i + 1);
        printf("Deadline: ");
        scanf("%d", &jobs[i].deadline);
        printf("Profit: ");
        scanf("%d", &jobs[i].profit);
        jobs[i].id = i + 1;
    }
    // Schedule jobs by deadline using Greedy Algorithm
    scheduleJobsByDeadline(jobs, numJobs);
    return 0;
}