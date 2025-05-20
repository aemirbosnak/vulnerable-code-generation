//FormAI DATASET v1.0 Category: Task Scheduler ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of tasks
#define MAX_TASKS 10

// Struct to hold a single task
typedef struct {
  int id;
  char description[100];
  time_t deadline;
  int completed;
} Task;

// Function to add a new task to the task scheduler
void addTask(Task tasks[], int *num_tasks) {
  if (*num_tasks < MAX_TASKS) {
    Task new_task;
    new_task.id = (*num_tasks) + 1;
    printf("Please enter a description for the new task:\n");
    scanf("%99s", new_task.description);
    printf("Please enter the deadline for the new task (YYYY-MM-DD):\n");
    scanf("%ld", &new_task.deadline);
    new_task.completed = 0;
    
    tasks[*num_tasks] = new_task;
    (*num_tasks)++;
    printf("Task added successfully!\n\n");
  } else {
    printf("Maximum number of tasks reached!\n\n");
  }
}

// Function to print all the tasks in the task scheduler
void printTasks(Task tasks[], int num_tasks) {
  printf("ID   Description                       Deadline       Completed?\n");
  printf("-----------------------------------------------------------------\n");
  for (int i = 0; i < num_tasks; i++) {
    printf("%-4d %-32s %-14ld", tasks[i].id, tasks[i].description, tasks[i].deadline);
    if (tasks[i].completed == 1) {
      printf(" Yes\n");
    } else {
      printf(" No\n");
    }
  }
  printf("\n");
}

// Function to mark a task as completed
void completeTask(Task tasks[], int num_tasks) {
  int task_id;
  printf("Please enter the ID of the task you wish to mark as completed:\n");
  scanf("%d", &task_id);
  
  // Loop through all the tasks and mark the one with the given ID as completed
  for (int i = 0; i < num_tasks; i++) {
    if (tasks[i].id == task_id) {
      tasks[i].completed = 1;
      printf("Task with ID %d marked as completed!\n\n", task_id);
      return;
    }
  }
  
  // If we reach this point, the task with the given ID was not found
  printf("Task with ID %d not found!\n\n", task_id);
}

int main() {
  Task tasks[MAX_TASKS];
  int num_tasks = 0;
  int choice;
  
  printf("Welcome to the Task Scheduler!\n\n");
  
  // Main menu loop
  while (1) {
    printf("Please choose an option:\n");
    printf(" 1. Add a new task\n");
    printf(" 2. Print all tasks\n");
    printf(" 3. Mark a task as completed\n");
    printf(" 4. Exit\n");
    scanf("%d", &choice);
    
    switch (choice) {
      case 1:
        addTask(tasks, &num_tasks);
        break;
      case 2:
        printTasks(tasks, num_tasks);
        break;
      case 3:
        completeTask(tasks, num_tasks);
        break;
      case 4:
        printf("Goodbye!\n");
        exit(0);
      default:
        printf("Invalid choice!\n\n");
        break;
    }
  }
  
  return 0;
}