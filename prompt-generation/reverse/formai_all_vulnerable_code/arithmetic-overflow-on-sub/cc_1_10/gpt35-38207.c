//FormAI DATASET v1.0 Category: Task Scheduler ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define TASK_NUM 10

typedef struct {
  int id;
  int duration_secs;
  bool is_running;
  time_t start_time;
} Task;

void run(Task* task) {
  task->is_running = true;
  task->start_time = time(NULL);
  printf("Task %d is running...\n", task->id);
}

void complete(Task* task) {
  task->is_running = false;
  time_t end_time = time(NULL);
  printf("Task %d completed in %ld seconds.\n", task->id, end_time - task->start_time);
}

int main() {
  Task tasks[TASK_NUM] = {
    {1, 3, false, 0},
    {2, 6, false, 0},
    {3, 10, false, 0},
    {4, 2, false, 0},
    {5, 8, false, 0},
    {6, 4, false, 0},
    {7, 5, false, 0},
    {8, 7, false, 0},
    {9, 1, false, 0},
    {10, 9, false, 0}
  };
  
  int i = 0;
  while (true) {
    for (i = 0; i < TASK_NUM; i++) {
      if (tasks[i].is_running) {
        if (time(NULL) - tasks[i].start_time >= tasks[i].duration_secs) {
          complete(&tasks[i]);
        }
      } else {
        run(&tasks[i]);
      }
    }
  }
  
  return 0;
}