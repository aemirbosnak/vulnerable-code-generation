//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Structure to store a job
typedef struct Job {
    int id;         // Job ID
    int weight;     // Job weight
    int profit;     // Job profit
} Job;

// Structure to store the results of each thread
typedef struct ThreadResult {
    int thread_id;     // Thread ID
    int total_weight;  // Total weight of jobs assigned to the thread
    int total_profit;  // Total profit of jobs assigned to the thread
    Job **jobs;       // Array of jobs assigned to the thread
} ThreadResult;

// Function to compare jobs by weight
int compare_by_weight(const void *a, const void *b) {
    const Job *j1 = (const Job *)a;
    const Job *j2 = (const Job *)b;
    return j1->weight - j2->weight;
}

// Function to compare jobs by profit
int compare_by_profit(const void *a, const void *b) {
    const Job *j1 = (const Job *)a;
    const Job *j2 = (const Job *)b;
    return j1->profit - j2->profit;
}

// Function to compare thread results
int compare_by_total_profit(const void *a, const void *b) {
    const ThreadResult *r1 = (const ThreadResult *)a;
    const ThreadResult *r2 = (const ThreadResult *)b;
    return r1->total_profit - r2->total_profit;
}

// Function to be executed by each thread
void *thread_function(void *arg) {
    // Retrieve the thread's job list and job count
    ThreadResult *result = (ThreadResult *)arg;
    Job **jobs = result->jobs;
    int job_count = result->thread_id + 1;

    // Sort the jobs by weight
    qsort(jobs, job_count, sizeof(Job), compare_by_weight);

    // Assign jobs to the thread
    int total_weight = 0;
    int total_profit = 0;
    for (int i = 0; i < job_count; i++) {
        if (total_weight + jobs[i]->weight <= result->total_weight) {
            total_weight += jobs[i]->weight;
            total_profit += jobs[i]->profit;
        } else {
            break;
        }
    }

    // Update the thread's results
    result->total_weight = total_weight;
    result->total_profit = total_profit;

    // Return the thread's results
    return (void *)result;
}

int main() {
    // Read the number of jobs and the maximum weight capacity
    int num_jobs;
    printf("Enter the number of jobs: ");
    scanf("%d", &num_jobs);
    int max_weight;
    printf("Enter the maximum weight capacity: ");
    scanf("%d", &max_weight);

    // Create an array of jobs
    Job *jobs = (Job *)malloc(num_jobs * sizeof(Job));
    for (int i = 0; i < num_jobs; i++) {
        printf("Enter the weight of job %d: ", i + 1);
        scanf("%d", &jobs[i].weight);
        printf("Enter the profit of job %d: ", i + 1);
        scanf("%d", &jobs[i].profit);
        jobs[i].id = i + 1;
    }

    // Sort the jobs by weight
    qsort(jobs, num_jobs, sizeof(Job), compare_by_weight);

    // Create threads and assign jobs to each thread
    int num_threads;
    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);
    pthread_t *threads = (pthread_t *)malloc(num_threads * sizeof(pthread_t));
    ThreadResult *results = (ThreadResult *)malloc(num_threads * sizeof(ThreadResult));
    for (int i = 0; i < num_threads; i++) {
        results[i].thread_id = i;
        results[i].total_weight = max_weight / num_threads;
        results[i].jobs = (Job **)malloc(results[i].total_weight * sizeof(Job));
        pthread_create(&threads[i], NULL, thread_function, &results[i]);
    }

    // Wait for all threads to complete
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Sort the results by total profit
    qsort(results, num_threads, sizeof(ThreadResult), compare_by_total_profit);

    // Print the results
    printf("Thread Results:\n");
    for (int i = 0; i < num_threads; i++) {
        printf("Thread %d:\n", results[i].thread_id);
        printf("Total Weight: %d\n", results[i].total_weight);
        printf("Total Profit: %d\n", results[i].total_profit);
        printf("Jobs Assigned:\n");
        for (int j = 0; j < results[i].total_weight; j++) {
            printf("Job %d (Weight: %d, Profit: %d)\n", 
                results[i].jobs[j]->id, results[i].jobs[j]->weight, results[i].jobs[j]->profit);
        }
        printf("\n");
    }

    // Clean up
    for (int i = 0; i < num_threads; i++) {
        free(results[i].jobs);
    }
    free(results);
    free(threads);
    free(jobs);

    return 0;
}