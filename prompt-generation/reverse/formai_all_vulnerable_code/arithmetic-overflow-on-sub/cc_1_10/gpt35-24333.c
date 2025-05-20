//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Alan Touring
#include <stdio.h>

int main() {
  int n, k, i, min_cost = 0;
  
  // Prompt user for input
  printf("Enter number of jobs: ");
  scanf("%d", &n);
  printf("Enter number of workers: ");
  scanf("%d", &k);
  
  // Declare arrays to hold the cost of each job and worker availability
  int jobs[n];
  int workers[k];
  
  // Prompt user for job and worker availability
  for(i = 0; i < n; i++) {
    printf("Enter cost of job %d: ", i+1);
    scanf("%d", &jobs[i]);
  }
  
  for(i = 0; i < k; i++) {
    printf("Enter availability of worker %d (1 if available, 0 if not): ", i+1);
    scanf("%d", &workers[i]);
  }

  // Sort jobs in ascending order of cost
  for(i = 0; i < n-1; i++) {
    int j, min_index = i;
    for(j = i+1; j < n; j++) {
      if(jobs[j] < jobs[min_index]) {
        min_index = j;
      }
    }
    int temp = jobs[i];
    jobs[i] = jobs[min_index];
    jobs[min_index] = temp;
  }
  
  // Assign jobs to available workers starting from the cheapest job
  for(i = 0; i < n; i++) {
    int j = 0;
    while(j < k && !workers[j]) {
      j++;
    }
    if(j < k) {
      workers[j] = 0;
      min_cost += jobs[i];
    }
  }
  
  // Output the minimum cost of completing all jobs
  printf("\nMinimum cost of completing all jobs: %d\n", min_cost);
  
  return 0;
}