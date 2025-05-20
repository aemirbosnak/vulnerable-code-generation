//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: energetic
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define NUM_TASKS 5

typedef struct Task {
  char name[20];
  int duration;
  void (*function)(void);
} Task;

void task_1(void) {
  printf("Task 1 is running!\n");
  sleep(2);
}

void task_2(void) {
  printf("Task 2 is running!\n");
  sleep(3);
}

void task_3(void) {
  printf("Task 3 is running!\n");
  sleep(4);
}

void task_4(void) {
  printf("Task 4 is running!\n");
  sleep(5);
}

void task_5(void) {
  printf("Task 5 is running!\n");
  sleep(6);
}

int main() {
  time_t now, then;
  struct Task tasks[NUM_TASKS] = {
    {"Task 1", 2, task_1},
    {"Task 2", 3, task_2},
    {"Task 3", 4, task_3},
    {"Task 4", 5, task_4},
    {"Task 5", 6, task_5}
  };

  now = time(NULL);
  for (int i = 0; i < NUM_TASKS; i++) {
    then = now + tasks[i].duration;
    printf("Starting task %s in %d seconds...\n", tasks[i].name, tasks[i].duration);
    sleep(tasks[i].duration);
    printf("Task %s completed!\n", tasks[i].name);
  }

  return 0;
}