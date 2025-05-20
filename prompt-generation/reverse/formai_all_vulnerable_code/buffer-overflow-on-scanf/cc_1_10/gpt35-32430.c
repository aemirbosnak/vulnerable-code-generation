//FormAI DATASET v1.0 Category: Task Scheduler ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct ScheduledTask {
  int id;
  char name[50];
  int priority;
  int duration;
  time_t scheduled_time;
} ScheduledTask;

void add_task(ScheduledTask tasks[], int num_tasks) {
  ScheduledTask new_task;
  new_task.id = num_tasks;
  printf("Enter task name: ");
  scanf("%s", new_task.name);
  printf("Enter task priority (1-5): ");
  scanf("%d", &new_task.priority);
  printf("Enter task duration (in minutes): ");
  scanf("%d", &new_task.duration);
  new_task.scheduled_time = time(NULL);
  tasks[num_tasks] = new_task;
  printf("\nTask added successfully.\n\n");
}

void reschedule_task(ScheduledTask tasks[], int num_tasks) {
  int task_id;
  printf("Enter ID of task to reschedule: ");
  scanf("%d", &task_id);
  if (task_id >= num_tasks) {
    printf("\nInvalid task ID.\n\n");
    return;
  }
  ScheduledTask task = tasks[task_id];
  printf("Current scheduled time is: %s", ctime(&task.scheduled_time));
  printf("Enter new scheduled time (YYYY-MM-DD HH:MM:SS): ");
  char new_time_str[20];
  scanf("%s", new_time_str);
  struct tm new_time = {0};
  strptime(new_time_str, "%Y-%m-%d %H:%M:%S", &new_time);
  time_t new_time_t = mktime(&new_time);
  task.scheduled_time = new_time_t;
  tasks[task_id] = task;
  printf("\nTask successfully rescheduled.\n\n");
}

void print_all_tasks(ScheduledTask tasks[], int num_tasks) {
  printf("\nID | Name                     | Priority  | Duration  | Scheduled Time\n");
  printf("---------------------------------------------------------------------\n");
  for (int i = 0; i < num_tasks; i++) {
    ScheduledTask task = tasks[i];
    printf("%2d | %-24s | %2d        | %2d min    | %s", task.id, task.name, task.priority, task.duration, ctime(&task.scheduled_time));
  }
  printf("---------------------------------------------------------------------\n\n");
}

int main() {
  ScheduledTask tasks[10];
  int num_tasks = 0;
  while (1) {
    printf("Enter command (add/reschedule/print/exit): ");
    char command[20];
    scanf("%s", command);
    if (strcmp(command, "add") == 0) {
      add_task(tasks, num_tasks);
      num_tasks++;
    } else if (strcmp(command, "reschedule") == 0) {
      reschedule_task(tasks, num_tasks);
    } else if (strcmp(command, "print") == 0) {
      print_all_tasks(tasks, num_tasks);
    } else if (strcmp(command, "exit") == 0) {
      printf("\nGoodbye!\n");
      exit(0);
    } else {
      printf("\nInvalid command.\n\n");
    }
  }
  return 0;
}