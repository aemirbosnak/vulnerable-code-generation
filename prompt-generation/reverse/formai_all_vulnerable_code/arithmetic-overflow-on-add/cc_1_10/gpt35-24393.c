//FormAI DATASET v1.0 Category: Task Scheduler ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <stdbool.h>

// Constants
#define NUM_TASKS 5
#define MAX_DELAY 5 // Max time in seconds to delay task execution

// Task struct
typedef struct task {
  int id;
  void (*callback)();
  time_t next_execution;
} Task;

// Initialize tasks
Task tasks[NUM_TASKS];

// Prototypes
void init_tasks();
void run_tasks();
void task_1();
void task_2();
void task_3();
void task_4();
void task_5();

int main() {
  // Initialize tasks
  init_tasks();

  // Run tasks
  run_tasks();

  return 0;
}

// Initialize tasks
void init_tasks() {
  tasks[0] = (Task){1, task_1, time(NULL) + rand() % MAX_DELAY};
  tasks[1] = (Task){2, task_2, time(NULL) + rand() % MAX_DELAY};
  tasks[2] = (Task){3, task_3, time(NULL) + rand() % MAX_DELAY};
  tasks[3] = (Task){4, task_4, time(NULL) + rand() % MAX_DELAY};
  tasks[4] = (Task){5, task_5, time(NULL) + rand() % MAX_DELAY};
}

// Run tasks
void run_tasks() {
  while (true) {
    time_t current_time = time(NULL);

    // Check if any tasks need to be executed
    for (int i = 0; i < NUM_TASKS; i++) {
      if (current_time >= tasks[i].next_execution) {
        tasks[i].callback();
        tasks[i].next_execution = current_time + rand() % MAX_DELAY;
      }
    }

    // Sleep for 1 second
    sleep(1);
  }
}

// Task 1
void task_1() {
  printf("Task 1 executed\n");
}

// Task 2
void task_2() {
  printf("Task 2 executed\n");
}

// Task 3
void task_3() {
  printf("Task 3 executed\n");
}

// Task 4
void task_4() {
  printf("Task 4 executed\n");
}

// Task 5
void task_5() {
  printf("Task 5 executed\n");
}