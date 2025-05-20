//FormAI DATASET v1.0 Category: Task Scheduler ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_TASKS 10
#define MAX_TASK_NAME 20
#define MAX_TASK_DESC 100

struct task {
  char name[MAX_TASK_NAME];
  char description[MAX_TASK_DESC];
  int priority;
  int frequency;
};

struct task task_list[MAX_TASKS];
int task_count = 0;

void add_task() {
  if(task_count == MAX_TASKS) {
    printf("Task list is full!\n");
    return;
  }

  struct task new_task;

  printf("Enter task name: ");
  scanf("%s", new_task.name);

  printf("Enter task description: ");
  scanf("%s", new_task.description);

  printf("Enter task priority: ");
  scanf("%d", &new_task.priority);

  printf("Enter task frequency (in seconds): ");
  scanf("%d", &new_task.frequency);

  task_list[task_count++] = new_task;
}

void remove_task() {
  if(task_count == 0) {
    printf("Task list is empty!\n");
    return;
  }

  int index, i;
  printf("Enter task index to remove: ");
  scanf("%d", &index);

  if(index < 0 || index >= task_count) {
    printf("Invalid task index!\n");
    return;
  }

  for(i = index; i < task_count - 1; i++) {
    task_list[i] = task_list[i+1];
  }

  task_count--;
}

void list_tasks() {
  if(task_count == 0) {
    printf("Task list is empty!\n");
    return;
  }

  int i;

  for(i = 0; i < task_count; i++) {
    printf("%d. %s - %s (Priority: %d, Frequency: %d seconds)\n", i, task_list[i].name, task_list[i].description, task_list[i].priority, task_list[i].frequency);
  }
}

void execute_task(struct task t) {
  printf("Executing task: %s - %s\n", t.name, t.description);
  sleep(t.frequency);
}

void schedule_tasks() {
  if(task_count == 0) {
    printf("Task list is empty!\n");
    return;
  }

  while(1) {
    int i, max_priority = -1, max_priority_index = -1;

    for(i = 0; i < task_count; i++) {
      if(task_list[i].priority > max_priority) {
        max_priority = task_list[i].priority;
        max_priority_index = i;
      }
    }

    execute_task(task_list[max_priority_index]);
  }
}

int main() {
  int option;

  while(1) {
    printf("1. Add Task\n");
    printf("2. Remove Task\n");
    printf("3. List Tasks\n");
    printf("4. Schedule Tasks\n");
    printf("5. Exit\n");
    printf("Select an option: ");
    scanf("%d", &option);

    switch(option) {
      case 1: 
        add_task();
        break;

      case 2:
        remove_task();
        break;

      case 3:
        list_tasks();
        break;

      case 4:
        schedule_tasks();
        break;

      case 5:
        exit(0);

      default:
        printf("Invalid option!\n");
        break;
    }
  }
  return 0;
}