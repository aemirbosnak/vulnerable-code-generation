//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a job
typedef struct Job {
    int id;             // Job ID
    int arrivalTime;    // Arrival time of the job
    int processingTime; // Processing time of the job
} Job;

// Comparison function to sort jobs by arrival time
int compareArrivalTime(const void *a, const void *b) {
    const Job *job1 = (const Job *)a;
    const Job *job2 = (const Job *)b;
    return job1->arrivalTime - job2->arrivalTime;
}

// Function to find the minimum completion time of all jobs using greedy algorithm
int findMinCompletionTime(Job *jobs, int n) {
    // Sort jobs by arrival time
    qsort(jobs, n, sizeof(Job), compareArrivalTime);

    // Initialize the current time to 0
    int currentTime = 0;

    // Initialize the total completion time to 0
    int totalCompletionTime = 0;

    // Iterate over the jobs
    for (int i = 0; i < n; i++) {
        // If the current time is less than the arrival time of the job, then wait until the arrival time
        if (currentTime < jobs[i].arrivalTime) {
            currentTime = jobs[i].arrivalTime;
        }

        // Update the current time by adding the processing time of the job
        currentTime += jobs[i].processingTime;

        // Update the total completion time by adding the current time
        totalCompletionTime += currentTime;
    }

    // Return the total completion time
    return totalCompletionTime;
}

// Main function
int main() {
    // Input: number of jobs
    int n;
    scanf("%d", &n);

    // Input: jobs
    Job jobs[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &jobs[i].id, &jobs[i].arrivalTime, &jobs[i].processingTime);
    }

    // Find the minimum completion time of all jobs
    int minCompletionTime = findMinCompletionTime(jobs, n);

    // Output: minimum completion time
    printf("%d\n", minCompletionTime);

    return 0;
}