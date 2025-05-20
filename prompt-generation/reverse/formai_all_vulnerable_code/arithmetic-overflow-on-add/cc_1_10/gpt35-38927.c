//FormAI DATASET v1.0 Category: Task Scheduler ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_TASKS 1000

typedef struct Task {
  char name[50];
  time_t next_run;
  int frequency;
  bool active;
} Task;

Task task_list[MAX_TASKS];
int task_count = 0;

void add_task(char name[], time_t next_run, int frequency) {
  Task new_task = { .next_run = next_run, .frequency = frequency, .active = true };
  strcpy(new_task.name, name);
  task_list[task_count++] = new_task;
}

int main() {
  // Add some example tasks
  add_task("Task 1", time(NULL), 5);
  add_task("Task 2", time(NULL), 10);
  add_task("Task 3", time(NULL), 15);

  while (true) {
    // Check each task
    for (int i = 0; i < task_count; i++) {
      Task* task = &task_list[i];
      
      if (task->active) {
        time_t current_time = time(NULL);
        
        if (current_time >= task->next_run) {
          printf("%s is running...\n", task->name);
          task->next_run = current_time + task->frequency;
        }
      }
    }
    
    // Sleep for a short time to avoid using too much CPU
    usleep(10000);
  }
  
  return 0;
}