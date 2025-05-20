//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

// Define a job structure
typedef struct job {
  int id;
  int profit;
  int deadline;
} Job;

// Compare jobs by their profit
int compare_jobs(const void *a, const void *b) {
  Job *job1 = (Job *)a;
  Job *job2 = (Job *)b;
  return job2->profit - job1->profit;
}

// Function to find the maximum profit
int find_max_profit(Job jobs[], int n) {
  // Sort the jobs by their profit in descending order
  qsort(jobs, n, sizeof(Job), compare_jobs);

  // Initialize the maximum profit to 0
  int max_profit = 0;

  // Create an array to store the selected jobs
  int selected_jobs[n];

  // Initialize the number of selected jobs to 0
  int num_selected_jobs = 0;

  // Iterate over the jobs
  for (int i = 0; i < n; i++) {
    // If the current job can be scheduled without violating its deadline
    if (num_selected_jobs < jobs[i].deadline) {
      // Select the job and add its profit to the maximum profit
      selected_jobs[num_selected_jobs++] = jobs[i].id;
      max_profit += jobs[i].profit;
    }
  }

  // Return the maximum profit
  return max_profit;
}

// Main function
int main() {
  // Initialize the number of jobs
  int n;

  // Get the number of jobs from the user
  scanf("%d", &n);

  // Create an array to store the jobs
  Job jobs[n];

  // Get the details of each job from the user
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", &jobs[i].id, &jobs[i].profit, &jobs[i].deadline);
  }

  // Find the maximum profit
  int max_profit = find_max_profit(jobs, n);

  // Print the maximum profit
  printf("%d\n", max_profit);

  // Return 0
  return 0;
}