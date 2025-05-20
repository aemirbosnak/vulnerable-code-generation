//FormAI DATASET v1.0 Category: Task Scheduler ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define TASK_SIZE 10

typedef struct task_t {
  void (*function)(void);
  time_t time;
} task_t;

task_t tasks[TASK_SIZE];
int num_tasks = 0;

void add_task(void (*function)(void), time_t time) {
  if (num_tasks < TASK_SIZE) {
    tasks[num_tasks].function = function;
    tasks[num_tasks].time = time;
    num_tasks++;
  } else {
    printf("Task scheduler is full\n");
  }
}

bool is_task_ready(task_t task) {
  time_t now = time(NULL);
  return task.time <= now;
}

void execute_task(task_t task) {
  (*task.function)();
}

void remove_task(int index) {
  for (int i = index; i < num_tasks - 1; i++) {
    tasks[i] = tasks[i + 1];
  }
  num_tasks--;
}

void check_tasks() {
  for (int i = 0; i < num_tasks; i++) {
    if (is_task_ready(tasks[i])) {
      execute_task(tasks[i]);
      remove_task(i);
      i--;
    }
  }
}

void task1() {
  printf("Task 1 executed\n");
}

void task2() {
  printf("Task 2 executed\n");
}

int main() {
  add_task(&task1, time(NULL) + 5);
  add_task(&task2, time(NULL) + 10);

  while (true) {
    check_tasks();
  }

  return 0;
}