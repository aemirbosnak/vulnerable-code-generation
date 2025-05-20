//Code Llama-13B DATASET v1.0 Category: Task Scheduler ; Style: all-encompassing
/*
 * C Task Scheduler
 *
 * Author: [Your Name]
 * Date:   [Today's Date]
 *
 * Description:
 *  A simple task scheduler that allows users to schedule tasks to run at
 *  specific times.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Task structure
struct Task {
  char name[100];
  time_t start_time;
  time_t end_time;
};

// Schedule structure
struct Schedule {
  struct Task* tasks;
  int num_tasks;
};

// Function prototypes
void add_task(struct Schedule* schedule, struct Task* task);
void run_schedule(struct Schedule* schedule);

int main() {
  struct Schedule schedule;
  schedule.tasks = NULL;
  schedule.num_tasks = 0;

  // Add tasks to the schedule
  struct Task task1;
  strcpy(task1.name, "Task 1");
  task1.start_time = time(NULL);
  task1.end_time = task1.start_time + 5;
  add_task(&schedule, &task1);

  struct Task task2;
  strcpy(task2.name, "Task 2");
  task2.start_time = task1.end_time;
  task2.end_time = task2.start_time + 10;
  add_task(&schedule, &task2);

  struct Task task3;
  strcpy(task3.name, "Task 3");
  task3.start_time = task2.end_time;
  task3.end_time = task3.start_time + 15;
  add_task(&schedule, &task3);

  // Run the schedule
  run_schedule(&schedule);

  return 0;
}

void add_task(struct Schedule* schedule, struct Task* task) {
  // Reallocate memory for the tasks array
  schedule->tasks = realloc(schedule->tasks, sizeof(struct Task) * (schedule->num_tasks + 1));

  // Add the task to the end of the array
  schedule->tasks[schedule->num_tasks] = *task;
  schedule->num_tasks++;
}

void run_schedule(struct Schedule* schedule) {
  // Loop through the tasks in the schedule
  for (int i = 0; i < schedule->num_tasks; i++) {
    // Get the current task
    struct Task* task = &schedule->tasks[i];

    // Wait until the task's start time
    time_t current_time = time(NULL);
    while (current_time < task->start_time) {
      sleep(1);
      current_time = time(NULL);
    }

    // Run the task
    printf("Running task %s\n", task->name);
    sleep(task->end_time - task->start_time);
  }
}