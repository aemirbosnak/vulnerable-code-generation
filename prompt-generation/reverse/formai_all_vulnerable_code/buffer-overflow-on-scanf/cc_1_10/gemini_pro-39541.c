//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: asynchronous
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>
#include <stddef.h>
#include <assert.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>

#define MAX_READY_SIZE (1000)
#define MAX_WAITING_SIZE (1000)

typedef struct {
  int64_t tid;
  int64_t burst_time;
  int64_t arrival_time;
  int64_t priority;
  bool complete;
  int64_t start_time;
  int64_t end_time;
  int64_t response_time;
  int64_t wait_time;
} task_t;

task_t tasks[MAX_READY_SIZE];
int64_t ready_size = 0;

pthread_cond_t ready_cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t ready_lock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t running_lock = PTHREAD_MUTEX_INITIALIZER;

void io_scheduler(void *arg) {
  while (true) {
    pthread_mutex_lock(&ready_lock);
    pthread_cond_wait(&ready_cond, &ready_lock);

    if (ready_size == 0) {
      pthread_mutex_unlock(&ready_lock);
      usleep(1);
      continue;
    }

    int64_t min_start_time = INT64_MAX;
    task_t *min_task = NULL;

    for (int64_t i = 0; i < ready_size; i++) {
      task_t *task = &tasks[i];
      if (task->complete) {
        continue;
      }
      if (task->start_time >= min_start_time) {
        continue;
      }

      min_start_time = task->start_time;
      min_task = task;
    }

    min_task->end_time = min_task->start_time + min_task->burst_time;
    min_task->response_time = min_task->start_time - min_task->arrival_time;
    min_task->wait_time = min_task->start_time - min_task->arrival_time - min_task->burst_time;
    min_task->complete = true;

    pthread_mutex_unlock(&ready_lock);

    usleep(min_task->burst_time * 1000);
  }
}

void cpu_scheduler(void *arg) {
  while (true) {
    pthread_mutex_lock(&ready_lock);

    while (ready_size == 0) {
      pthread_cond_wait(&ready_cond, &ready_lock);
    }

    int64_t min_priority = INT64_MAX;
    task_t *min_task = NULL;

    for (int64_t i = 0; i < ready_size; i++) {
      task_t *task = &tasks[i];
      if (task->complete) {
        continue;
      }
      if (task->priority >= min_priority) {
        continue;
      }

      min_priority = task->priority;
      min_task = task;
    }

    min_task->start_time = min_task->arrival_time;
    min_task->end_time = min_task->start_time + min_task->burst_time;
    min_task->response_time = min_task->start_time - min_task->arrival_time;
    min_task->wait_time = min_task->start_time - min_task->arrival_time - min_task->burst_time;
    min_task->complete = true;

    pthread_mutex_unlock(&ready_lock);

    usleep(min_task->burst_time * 1000);
  }
}

int64_t compute_avg_throughput(void) {
  int64_t total_burst_time = 0;
  int64_t total_completion_time = 0;

  for (int64_t i = 0; i < ready_size; i++) {
    task_t *task = &tasks[i];
    if (task->complete) {
      total_burst_time += task->burst_time;
      total_completion_time += task->end_time;
    }
  }

  return total_burst_time / total_completion_time;
}

int64_t compute_avg_response_time(void) {
  int64_t total_response_time = 0;
  int64_t num_completed_tasks = 0;

  for (int64_t i = 0; i < ready_size; i++) {
    task_t *task = &tasks[i];
    if (task->complete) {
      total_response_time += task->response_time;
      num_completed_tasks++;
    }
  }

  return total_response_time / num_completed_tasks;
}

int64_t compute_avg_wait_time(void) {
  int64_t total_wait_time = 0;
  int64_t num_completed_tasks = 0;

  for (int64_t i = 0; i < ready_size; i++) {
    task_t *task = &tasks[i];
    if (task->complete) {
      total_wait_time += task->wait_time;
      num_completed_tasks++;
    }
  }

  return total_wait_time / num_completed_tasks;
}

int main(int argc, char **argv) {
  int64_t num_tasks;
  scanf("%ld", &num_tasks);

  for (int64_t i = 0; i < num_tasks; i++) {
    scanf("%ld %ld %ld", &tasks[i].tid, &tasks[i].burst_time, &tasks[i].arrival_time);
    tasks[i].priority = 0;
    tasks[i].complete = false;
    tasks[i].start_time = INT64_MAX;
    tasks[i].end_time = INT64_MAX;
    tasks[i].response_time = INT64_MAX;
    tasks[i].wait_time = INT64_MAX;
  }

  ready_size = num_tasks;

  pthread_t io_scheduler_thread;
  pthread_create(&io_scheduler_thread, NULL, &io_scheduler, NULL);

  pthread_t cpu_scheduler_thread;
  pthread_create(&cpu_scheduler_thread, NULL, &cpu_scheduler, NULL);

  pthread_join(io_scheduler_thread, NULL);
  pthread_join(cpu_scheduler_thread, NULL);

  printf("Throughput: %ld tasks/second\n", compute_avg_throughput());
  printf("Average Response Time: %ld milliseconds\n", compute_avg_response_time());
  printf("Average Wait Time: %ld milliseconds\n", compute_avg_wait_time());

  return 0;
}