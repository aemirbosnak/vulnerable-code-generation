//GEMINI-pro DATASET v1.0 Category: Threading Library Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Structure to hold thread arguments
typedef struct {
  int id;
  int *array;
  int size;
} thread_args_t;

// Thread function to sum a portion of the array
void *thread_func(void *args) {
  thread_args_t *thread_args = (thread_args_t *)args;

  int start = thread_args->id * (thread_args->size / thread_args->id);
  int end = (thread_args->id + 1) * (thread_args->size / thread_args->id);

  int sum = 0;
  for (int i = start; i < end; i++) {
    sum += thread_args->array[i];
  }

  // Return the partial sum
  return (void *)sum;
}

int main() {
  // Get the number of threads from the user
  int num_threads;
  printf("Enter the number of threads: ");
  scanf("%d", &num_threads);

  // Create an array of size 10000
  int array[10000];
  for (int i = 0; i < 10000; i++) {
    array[i] = i;
  }

  // Create thread arguments for each thread
  thread_args_t thread_args[num_threads];
  for (int i = 0; i < num_threads; i++) {
    thread_args[i].id = i;
    thread_args[i].array = array;
    thread_args[i].size = 10000;
  }

  // Create threads
  pthread_t threads[num_threads];
  for (int i = 0; i < num_threads; i++) {
    pthread_create(&threads[i], NULL, thread_func, (void *)&thread_args[i]);
  }

  // Join threads
  int total_sum = 0;
  for (int i = 0; i < num_threads; i++) {
    void *result;
    pthread_join(threads[i], &result);
    total_sum += (int)result;
  }

  // Print the total sum of the array
  printf("Total sum: %d\n", total_sum);

  return 0;
}