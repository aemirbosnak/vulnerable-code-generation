//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define job structure
typedef struct Job {
    char name[32];
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int waitingTime;
    int turnaroundTime;
} Job;

// Function to calculate average waiting and turnaround time
void calculateAverages(Job jobs[], int numJobs, int quantum) {
    int totalWaitingTime = 0, totalTurnaroundTime = 0;

    for (int i = 0; i < numJobs; i++) {
        totalWaitingTime += jobs[i].waitingTime;
        totalTurnaroundTime += jobs[i].turnaroundTime;
    }

    float avgWaitingTime = (float) totalWaitingTime / numJobs;
    float avgTurnaroundTime = (float) totalTurnaroundTime / numJobs;

    printf("Average waiting time: %.2f\n", avgWaitingTime);
    printf("Average turnaround time: %.2f\n", avgTurnaroundTime);
}

// Function to sort jobs by their arrival time
void sortByArrivalTime(Job jobs[], int numJobs) {
    Job temp;

    for (int i = 0; i < numJobs; i++) {
        for (int j = 0; j < numJobs - 1; j++) {
            if (jobs[j].arrivalTime > jobs[j+1].arrivalTime) {
                temp = jobs[j];
                jobs[j] = jobs[j+1];
                jobs[j+1] = temp;
            }
        }
    }
}

// Function to simulate Round Robin CPU scheduling
void simulateRoundRobin(Job jobs[], int numJobs, int quantum) {
    int time = 0, finished = 0, currentJob = -1;
    int *remainingTime = (int*) malloc(numJobs * sizeof(int));
    int *started = (int*) malloc(numJobs * sizeof(int));
    memset(remainingTime, 0, numJobs * sizeof(int));
    memset(started, 0, numJobs * sizeof(int));

    while (finished < numJobs) {
        // Find next job to execute
        int nextJob = -1;

        for (int i = 0; i < numJobs; i++) {
            if (jobs[i].arrivalTime <= time && remainingTime[i] > 0 && (nextJob == -1 || remainingTime[i] < remainingTime[nextJob])) {
                nextJob = i;
            }
        }

        // If no job found, increment time and continue
        if (nextJob == -1) {
            time++;
            continue;
        }

        // If new job is chosen
        if (currentJob != nextJob) {
            // Update wait time for previous job
            if (currentJob != -1) {
                jobs[currentJob].waitingTime += time - started[currentJob];
            }
            // Start new job
            currentJob = nextJob;
            started[currentJob] = time;
        }

        // Run for quantum or remaining time, whichever is smaller
        int runTime = remainingTime[currentJob] < quantum ? remainingTime[currentJob] : quantum;
        time += runTime;
        remainingTime[currentJob] -= runTime;

        // If job is finished
        if (remainingTime[currentJob] == 0) {
            finished++;
            jobs[currentJob].turnaroundTime = time - jobs[currentJob].arrivalTime;
            currentJob = -1; // Mark no job as currently running
        }
    }

    calculateAverages(jobs, numJobs, quantum);

    // Free up memory
    free(remainingTime);
    free(started);
}

int main() {
    int numJobs, quantum;
    printf("Enter number of jobs: ");
    scanf("%d", &numJobs);

    Job jobs[numJobs];

    // Get job details from user
    for (int i = 0; i < numJobs; i++) {
        printf("Enter details for job %d:\n", i+1);
        printf("Name: ");
        scanf("%s", jobs[i].name);
        printf("Arrival time: ");
        scanf("%d", &jobs[i].arrivalTime);
        printf("Burst time: ");
        scanf("%d", &jobs[i].burstTime);
        jobs[i].remainingTime = jobs[i].burstTime;
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    sortByArrivalTime(jobs, numJobs);

    simulateRoundRobin(jobs, numJobs, quantum);

    return 0;
}