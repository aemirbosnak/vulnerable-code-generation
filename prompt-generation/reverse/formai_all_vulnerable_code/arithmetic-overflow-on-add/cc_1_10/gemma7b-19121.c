//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: energetic
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define NUM_TASKS 5

struct Task {
  char name[20];
  int priority;
  void (*function)(void);
};

void task_a() {
  printf("Task A is running!\n");
  sleep(2);
}

void task_b() {
  printf("Task B is running!\n");
  sleep(3);
}

void task_c() {
  printf("Task C is running!\n");
  sleep(4);
}

void task_d() {
  printf("Task D is running!\n");
  sleep(5);
}

void task_e() {
  printf("Task E is running!\n");
  sleep(6);
}

int main() {
  struct Task tasks[NUM_TASKS] = {
    {"Task A", 1, task_a},
    {"Task B", 2, task_b},
    {"Task C", 3, task_c},
    {"Task D", 4, task_d},
    {"Task E", 5, task_e}
  };

  time_t now = time(NULL);
  int i = 0;

  // Simulate task scheduling
  for (i = 0; i < NUM_TASKS; i++) {
    sleep((int)now + tasks[i].priority);
    tasks[i].function();
  }

  return 0;
}