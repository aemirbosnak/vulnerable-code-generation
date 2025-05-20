//GEMINI-pro DATASET v1.0 Category: Threading Library Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

#define MAX_THREADS 10

typedef struct {
  int start;
  int end;
  int sum;
} thread_args_t;

pthread_mutex_t sum_lock;
int sum = 0;

void *worker(void *args) {
  thread_args_t *t_args = (thread_args_t *) args;
  int local_sum = 0;

  for (int i = t_args->start; i <= t_args->end; i++) {
    local_sum += i;
  }

  pthread_mutex_lock(&sum_lock);
  sum += local_sum;
  pthread_mutex_unlock(&sum_lock);

  free(t_args);
  return NULL;
}

int main() {
  pthread_t threads[MAX_THREADS];
  thread_args_t t_args[MAX_THREADS];

  pthread_mutex_init(&sum_lock, NULL);

  int num_threads, num_tasks;
  printf("Enter the number of threads: ");
  scanf("%d", &num_threads);
  printf("Enter the number of tasks: ");
  scanf("%d", &num_tasks);

  int task_size = num_tasks / num_threads;
  int remaining_tasks = num_tasks % num_threads;

  for (int i = 0; i < num_threads; i++) {
    t_args[i].start = i * task_size;
    t_args[i].end = (i + 1) * task_size - 1;
    pthread_create(&threads[i], NULL, worker, &t_args[i]);
  }

  if (remaining_tasks > 0) {
    t_args[num_threads].start = num_threads * task_size;
    t_args[num_threads].end = num_tasks - 1;
    pthread_create(&threads[num_threads], NULL, worker, &t_args[num_threads]);
  }

  for (int i = 0; i < num_threads; i++) {
    pthread_join(threads[i], NULL);
  }

  printf("The sum of the first %d natural numbers is: %d\n", num_tasks, sum);

  pthread_mutex_destroy(&sum_lock);
  return 0;
}