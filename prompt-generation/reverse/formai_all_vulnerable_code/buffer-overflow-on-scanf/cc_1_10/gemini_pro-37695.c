//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a job
typedef struct job {
    int id;         // Job ID
    int arrival;    // Arrival time
    int deadline;   // Deadline
    int profit;     // Profit
} Job;

// Compare jobs by their deadlines
int compare_jobs(const void *a, const void *b) {
    const Job *job1 = (const Job *)a;
    const Job *job2 = (const Job *)b;

    return job1->deadline - job2->deadline;
}

// Schedule jobs using the greedy algorithm
void schedule_jobs(Job *jobs, int n) {
    // Sort jobs by their deadlines
    qsort(jobs, n, sizeof(Job), compare_jobs);

    // Initialize the schedule
    int schedule[n];
    for (int i = 0; i < n; i++) {
        schedule[i] = -1;
    }

    // Iterate over the jobs
    int current_time = 0;
    for (int i = 0; i < n; i++) {
        // Find the first available slot in the schedule
        int slot = -1;
        for (int j = 0; j < n; j++) {
            if (schedule[j] == -1 && jobs[i].arrival <= current_time + j) {
                slot = j;
                break;
            }
        }

        // If a slot is found, schedule the job
        if (slot != -1) {
            schedule[slot] = jobs[i].id;
            current_time += jobs[i].deadline - jobs[i].arrival;
        }
    }

    // Print the schedule
    printf("Schedule:\n");
    for (int i = 0; i < n; i++) {
        if (schedule[i] != -1) {
            printf("Job %d scheduled at time %d\n", schedule[i], current_time);
        }
    }
}

// Main function
int main() {
    // Input: number of jobs
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    // Input: jobs' arrival times, deadlines, and profits
    Job jobs[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the arrival time, deadline, and profit of job %d: ", i + 1);
        scanf("%d %d %d", &jobs[i].arrival, &jobs[i].deadline, &jobs[i].profit);
        jobs[i].id = i + 1;
    }

    // Schedule the jobs
    schedule_jobs(jobs, n);

    return 0;
}