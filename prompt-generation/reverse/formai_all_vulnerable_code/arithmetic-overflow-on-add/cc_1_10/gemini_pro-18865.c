//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 100

struct task {
  char *name;
  int priority;
  time_t start_time;
  time_t end_time;
  int status;
};

struct task_scheduler {
  struct task *tasks[MAX_TASKS];
  int num_tasks;
};

struct task_scheduler *create_task_scheduler() {
  struct task_scheduler *scheduler = malloc(sizeof(struct task_scheduler));
  scheduler->num_tasks = 0;
  return scheduler;
}

void destroy_task_scheduler(struct task_scheduler *scheduler) {
  for (int i = 0; i < scheduler->num_tasks; i++) {
    free(scheduler->tasks[i]->name);
    free(scheduler->tasks[i]);
  }
  free(scheduler);
}

int add_task(struct task_scheduler *scheduler, struct task *task) {
  if (scheduler->num_tasks >= MAX_TASKS) {
    return -1;
  }
  scheduler->tasks[scheduler->num_tasks] = task;
  scheduler->num_tasks++;
  return 0;
}

void run_tasks(struct task_scheduler *scheduler) {
  while (scheduler->num_tasks > 0) {
    struct task *task = scheduler->tasks[0];
    for (int i = 1; i < scheduler->num_tasks; i++) {
      if (scheduler->tasks[i]->priority > task->priority) {
        task = scheduler->tasks[i];
      }
    }
    task->status = 1;
    printf("Running task %s\n", task->name);
    sleep(task->end_time - task->start_time);
    task->status = 2;
    for (int i = 0; i < scheduler->num_tasks; i++) {
      if (scheduler->tasks[i] == task) {
        for (int j = i; j < scheduler->num_tasks - 1; j++) {
          scheduler->tasks[j] = scheduler->tasks[j + 1];
        }
        scheduler->num_tasks--;
        break;
      }
    }
  }
}

int main() {
  struct task_scheduler *scheduler = create_task_scheduler();
  struct task *task1 = malloc(sizeof(struct task));
  task1->name = "Task 1";
  task1->priority = 1;
  task1->start_time = time(NULL);
  task1->end_time = time(NULL) + 10;
  task1->status = 0;
  add_task(scheduler, task1);
  struct task *task2 = malloc(sizeof(struct task));
  task2->name = "Task 2";
  task2->priority = 2;
  task2->start_time = time(NULL) + 5;
  task2->end_time = time(NULL) + 15;
  task2->status = 0;
  add_task(scheduler, task2);
  struct task *task3 = malloc(sizeof(struct task));
  task3->name = "Task 3";
  task3->priority = 3;
  task3->start_time = time(NULL) + 10;
  task3->end_time = time(NULL) + 20;
  task3->status = 0;
  add_task(scheduler, task3);
  run_tasks(scheduler);
  destroy_task_scheduler(scheduler);
  return 0;
}