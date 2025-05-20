//FormAI DATASET v1.0 Category: Task Scheduler ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 50

/* Structure for the Task */
typedef struct {
  char name[50];
  int priority;
  int duration;
  time_t start_time;
} Task;

/* Global Variables */
Task task_list[MAX_TASKS];
int num_tasks = 0;

/* Function Declarations */
void add_task();
void print_tasks();
void execute_tasks();

/* Main function */
int main() {
  int choice;
  do {
    printf("---- Task Scheduler ----\n");
    printf("1. Add Task\n");
    printf("2. Print Tasks\n");
    printf("3. Execute Tasks\n");
    printf("4. Exit\n");

    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        add_task();
        break;
      case 2:
        print_tasks();
        break;
      case 3:
        execute_tasks();
        break;
      case 4:
        exit(0);
        break;
      default:
        printf("Invalid choice!\n");
        break;
    }
  } while (choice != 4);

  return 0;
}

/* Function to add a task to the task_list */
void add_task() {
  if (num_tasks == MAX_TASKS) {
    printf("Task list is full!\n");
    return;
  }

  Task new_task;
  printf("Enter name of the task: ");
  scanf("%s", new_task.name);
  printf("Enter priority of the task (1-10): ");
  scanf("%d", &new_task.priority);
  printf("Enter duration of the task (in seconds): ");
  scanf("%d", &new_task.duration);

  new_task.start_time = time(NULL);

  task_list[num_tasks++] = new_task;

  printf("Task added!\n");
}

/* Function to print all the tasks */
void print_tasks() {
  if (num_tasks == 0) {
    printf("No tasks added yet!\n");
    return;
  }

  printf("Task Name\tPriority\tDuration\tStart Time\n");

  for (int i = 0; i < num_tasks; i++) {
    printf("%s\t\t%d\t\t%d seconds\t%s", task_list[i].name, task_list[i].priority, task_list[i].duration, ctime(&task_list[i].start_time));
  }
}

/* Function to execute all the tasks */
void execute_tasks() {
  if (num_tasks == 0) {
    printf("No tasks added yet!\n");
    return;
  }

  for (int i = 0; i < num_tasks; i++) {
    printf("Executed Task: %s\n", task_list[i].name);
    task_list[i].start_time = time(NULL);
  }
}