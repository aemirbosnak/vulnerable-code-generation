//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_TASKS 5
#define TASK_DELAY 1000

struct Task {
  char name[20];
  int priority;
  time_t start_time;
  time_t end_time;
  void (*func)(void);
};

void task_a(void) {
  printf("Task A is running\n");
}

void task_b(void) {
  printf("Task B is running\n");
}

void task_c(void) {
  printf("Task C is running\n");
}

void task_d(void) {
  printf("Task D is running\n");
}

void task_e(void) {
  printf("Task E is running\n");
}

void scheduler(struct Task tasks[]) {
  int i;
  time_t current_time = time(NULL);

  for (i = 0; i < NUM_TASKS; i++) {
    if (tasks[i].start_time <= current_time && tasks[i].end_time >= current_time) {
      tasks[i].func();
    }
  }
}

int main() {
  struct Task tasks[NUM_TASKS] = {
    {"Task A", 1, time(NULL) - TASK_DELAY, time(NULL), task_a},
    {"Task B", 2, time(NULL) - TASK_DELAY, time(NULL) + TASK_DELAY, task_b},
    {"Task C", 3, time(NULL) - TASK_DELAY, time(NULL) + TASK_DELAY, task_c},
    {"Task D", 4, time(NULL) - TASK_DELAY, time(NULL) + TASK_DELAY, task_d},
    {"Task E", 5, time(NULL) - TASK_DELAY, time(NULL) + TASK_DELAY, task_e}
  };

  scheduler(tasks);

  return 0;
}