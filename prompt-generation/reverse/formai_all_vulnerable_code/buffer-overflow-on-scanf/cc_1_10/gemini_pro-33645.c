//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct job_t {
  int id;
  int profit;
  int deadline;
} job;

int cmp(const void *a, const void *b) {
  return ((job *)a)->profit - ((job *)b)->profit;
}

int main() {
  int n, i;
  job *jobs;

  printf("Enter the number of jobs: ");
  scanf("%d", &n);

  jobs = malloc(sizeof(job) * n);

  printf("Enter the jobs in the following format (id, profit, deadline):\n");
  for (i = 0; i < n; i++) {
    scanf("%d %d %d", &jobs[i].id, &jobs[i].profit, &jobs[i].deadline);
  }

  qsort(jobs, n, sizeof(job), cmp);

  int max_deadline = 0;
  for (i = 0; i < n; i++) {
    if (jobs[i].deadline > max_deadline)
      max_deadline = jobs[i].deadline;
  }

  int *slots = malloc(sizeof(int) * max_deadline);
  for (i = 0; i < max_deadline; i++)
    slots[i] = -1;

  int profit = 0;
  for (i = 0; i < n; i++) {
    int j = jobs[i].deadline - 1;
    while (j >= 0 && slots[j] != -1)
      j--;

    if (j >= 0) {
      slots[j] = jobs[i].id;
      profit += jobs[i].profit;
    }
  }

  printf("The maximum profit is: %d\n", profit);
  printf("The jobs scheduled are:\n");
  for (i = 0; i < max_deadline; i++) {
    if (slots[i] != -1)
      printf("%d ", slots[i]);
  }

  printf("\n");

  free(jobs);
  free(slots);

  return 0;
}