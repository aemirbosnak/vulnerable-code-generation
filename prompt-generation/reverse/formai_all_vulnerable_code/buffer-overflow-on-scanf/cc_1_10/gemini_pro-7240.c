//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JOBS 100
#define MAX_TIME 1000

struct job {
  int arrival_time;
  int processing_time;
  int job_id;
};

int compare_jobs(const void *a, const void *b) {
  const struct job *job1 = a;
  const struct job *job2 = b;

  return job1->arrival_time - job2->arrival_time;
}

int main() {
  int num_jobs;
  struct job jobs[MAX_JOBS];

  // Read the input
  scanf("%d", &num_jobs);
  for (int i = 0; i < num_jobs; i++) {
    scanf("%d %d", &jobs[i].arrival_time, &jobs[i].processing_time);
    jobs[i].job_id = i + 1;
  }

  // Sort the jobs in ascending order of arrival time
  qsort(jobs, num_jobs, sizeof(struct job), compare_jobs);

  // Initialize the current time to 0
  int current_time = 0;

  // Initialize the completion times of all jobs to -1
  int completion_times[MAX_JOBS];
  for (int i = 0; i < num_jobs; i++) {
    completion_times[i] = -1;
  }

  // Process the jobs
  for (int i = 0; i < num_jobs; i++) {
    // If the current time is greater than or equal to the arrival time of the job,
    // then process the job
    if (current_time >= jobs[i].arrival_time) {
      // Calculate the completion time of the job
      completion_times[i] = current_time + jobs[i].processing_time;

      // Update the current time
      current_time = completion_times[i];
    }
  }

  // Print the completion times of all jobs
  for (int i = 0; i < num_jobs; i++) {
    printf("%d %d\n", jobs[i].job_id, completion_times[i]);
  }

  return 0;
}