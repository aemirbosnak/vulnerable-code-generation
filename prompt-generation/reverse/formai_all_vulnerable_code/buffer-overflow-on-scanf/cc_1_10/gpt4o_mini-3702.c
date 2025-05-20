//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_JOBS 100

typedef struct Job {
    int id;
    int deadline;
    int profit;
} Job;

Job jobs[MAX_JOBS];
int n;  // Number of jobs
int slots[MAX_JOBS]; // To keep track of free time slots
int max_profit = 0;

// Function to compare jobs based on profit
int compareJobs(const void *a, const void *b) {
    Job *job1 = (Job *)a;
    Job *job2 = (Job *)b;
    
    return job2->profit - job1->profit; // Sort in descending order of profit
}

// Function to assign jobs to time slots
void *scheduleJobs(void *arg) {
    for (int i = 0; i < n; i++) {
        for (int j = (jobs[i].deadline < n ? jobs[i].deadline : n) - 1; j >= 0; j--) {
            if (slots[j] == -1) { // If slot is free
                slots[j] = jobs[i].id; // Assign job to this slot
                max_profit += jobs[i].profit; // Add profit
                break; // Exit inner loop when job is assigned
            }
        }
    }
    return NULL;
}

void printJobSchedule() {
    printf("Scheduled jobs: \n");
    for (int i = 0; i < n; i++) {
        if (slots[i] != -1) {
            printf("Job ID: %d\n", slots[i]);
        }
    }
    printf("Maximum Profit: %d\n", max_profit);
}

int main() {
    pthread_t thread;

    // Input number of jobs
    printf("Enter number of jobs: ");
    scanf("%d", &n);
    
    // Input jobs details
    printf("Enter jobs in the format (JobID Deadline Profit):\n");
    for (int i = 0; i < n; i++) {
        jobs[i].id = i + 1; // Assign JobID starting from 1
        scanf("%d %d %d", &jobs[i].deadline, &jobs[i].profit);
    }

    // Initialize slots to -1
    memset(slots, -1, sizeof(slots));
    
    // Sort jobs based on profit
    qsort(jobs, n, sizeof(Job), compareJobs);
    
    // Create thread to schedule jobs
    if (pthread_create(&thread, NULL, scheduleJobs, NULL)) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }
  
    // Wait for the thread to finish
    if (pthread_join(thread, NULL)) {
        fprintf(stderr, "Error joining thread\n");
        return 1;
    }

    // Print results
    printJobSchedule();
    
    return 0;
}