//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a structure to represent a job
typedef struct Job {
    int profit;
    int deadline;
    int id;
} Job;

// Compare two jobs based on their profits
int compare(const void *a, const void *b) {
    const Job *j1 = (Job *)a;
    const Job *j2 = (Job *)b;

    return j2->profit - j1->profit;
}

// Print the order of jobs to be executed
void printOrder(Job jobs[], int n) {
    // Sort the jobs based on their profits
    qsort(jobs, n, sizeof(Job), compare);

    // Initialize an array to store the order of jobs
    int order[n];

    // Initialize the current deadline
    int currentDeadline = 0;

    // Initialize the current job index
    int currentJobIndex = 0;

    // Iterate over the jobs in sorted order
    for (int i = 0; i < n; i++) {
        // If the current deadline is less than the deadline of the current job
        if (currentDeadline < jobs[i].deadline) {
            // Increment the current deadline by 1
            currentDeadline++;

            // Assign the current job to the current deadline
            order[currentDeadline] = jobs[i].id;

            // Increment the current job index
            currentJobIndex++;
        }
    }

    // Print the order of jobs
    for (int i = 1; i <= currentDeadline; i++) {
        printf("%d ", order[i]);
    }

    printf("\n");
}

// Main function
int main() {
    // Initialize the number of jobs
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    // Initialize the jobs array
    Job jobs[n];

    // Read the jobs from the input
    for (int i = 0; i < n; i++) {
        printf("Enter the profit and deadline for job %d: ", i + 1);
        scanf("%d %d", &jobs[i].profit, &jobs[i].deadline);
        jobs[i].id = i + 1;
    }

    // Print the order of jobs to be executed
    printOrder(jobs, n);

    return 0;
}