//FormAI DATASET v1.0 Category: Task Scheduler ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_TASKS 10
#define MAX_LENGTH 50

typedef struct Task {
   char name[MAX_LENGTH];
   int priority;
   int arrival_time;
   int execution_time;
} Task;

Task task_list[MAX_TASKS];
int current_task = 0;

void add_task() {
   Task new_task;
   printf("Enter task name: ");
   scanf("%s", new_task.name);
   printf("Enter task priority: ");
   scanf("%d", &new_task.priority);
   printf("Enter task arrival time: ");
   scanf("%d", &new_task.arrival_time);
   printf("Enter task execution time: ");
   scanf("%d", &new_task.execution_time);
   if (current_task == MAX_TASKS) {
      printf("Task scheduler full! Task not added.\n");
      return;
   }
   task_list[current_task++] = new_task;
   printf("Task added successfully!\n");
}

void print_list() {
   printf("Task Name\tPriority\tArrival Time\tExecution Time\n");
   for (int i = 0; i < current_task; i++) {
      printf("%s\t\t%d\t%d\t\t%d\n", task_list[i].name, task_list[i].priority, task_list[i].arrival_time, task_list[i].execution_time);
   }
}

void run_scheduler() {
   printf("Running scheduler...\n");
   for (int i = 0; i < current_task; i++) {
      Task current = task_list[i];
      printf("%s starting...\n", current.name);
      for (int j = 0; j < current.execution_time; j++) {
         printf("%s execution time remaining: %d\n", current.name, current.execution_time - j);
      }
      printf("%s completed!\n", current.name);
   }
}

int main() {
   int choice;
   while (1) {
      printf("Task Scheduler Main Menu\n");
      printf("1. Add Task\n");
      printf("2. Print Task List\n");
      printf("3. Run Scheduler\n");
      printf("4. Exit\n");
      printf("Enter choice: ");
      scanf("%d", &choice);
      switch (choice) {
         case 1:
            add_task();
            break;
         case 2:
            print_list();
            break;
         case 3:
            run_scheduler();
            break;
         case 4:
            exit(0);
         default:
            printf("Invalid choice!\n");
            break;
      }
      printf("\n");
   }
   return 0;
}