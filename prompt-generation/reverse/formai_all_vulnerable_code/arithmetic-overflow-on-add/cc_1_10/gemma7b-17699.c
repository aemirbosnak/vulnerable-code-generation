//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: happy
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define NUM_TASKS 5

struct Task {
  char name[20];
  int duration;
  void (*function)(void);
};

void task1(void) {
  printf("Task 1 is running!\n");
  sleep(2);
}

void task2(void) {
  printf("Task 2 is running!\n");
  sleep(3);
}

void task3(void) {
  printf("Task 3 is running!\n");
  sleep(4);
}

void task4(void) {
  printf("Task 4 is running!\n");
  sleep(5);
}

void task5(void) {
  printf("Task 5 is running!\n");
  sleep(6);
}

int main() {
  struct Task tasks[NUM_TASKS] = {
    {"Task 1", 2, task1},
    {"Task 2", 3, task2},
    {"Task 3", 4, task3},
    {"Task 4", 5, task4},
    {"Task 5", 6, task5}
  };

  time_t now = time(NULL);
  for (int i = 0; i < NUM_TASKS; i++) {
    time_t scheduled_time = now + tasks[i].duration;
    printf("Task %s scheduled to run at %ld\n", tasks[i].name, scheduled_time);
  }

  return 0;
}