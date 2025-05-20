//FormAI DATASET v1.0 Category: Task Scheduler ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct task {
  int id;
  char name[10];
  time_t exec_time;
  struct task *next;
} task_t;

task_t *task_list = NULL;

/* Adds a task to the task list */
void add_task(int id, const char *name, time_t exec_time) {
  task_t *task = (task_t *) malloc(sizeof(task_t));

  task->id = id;
  strncpy(task->name, name, 10);
  task->exec_time = exec_time;
  task->next = NULL;

  if (task_list == NULL) {
    task_list = task;
  } else {
    task_t *last_task = task_list;
    while (last_task->next != NULL) {
      last_task = last_task->next;
    }
    last_task->next = task;
  }
}

/* Removes the task from the task list */
void remove_task(task_t *task) {
  if (task_list == NULL) {
    return;
  }

  if (task == task_list) {
    task_list = task->next;
  } else {
    task_t *prev_task = task_list;
    while (prev_task->next != task) {
      prev_task = prev_task->next;
    }
    prev_task->next = task->next;
  }

  free(task);
}

/* Executes the tasks whose time of execution has come */
void execute_tasks() {
  time_t current_time = time(NULL);
  task_t *task = task_list;

  while (task != NULL && task->exec_time <= current_time) {
    printf("Executing task %s\n", task->name);
    task_t *next_task = task->next;
    remove_task(task);
    task = next_task;
  }
}

/* Prints the current task list */
void print_tasks() {
  task_t *task = task_list;

  while (task != NULL) {
    printf("Task id: %d, Task name: %s, Execution time: %s", task->id, task->name, ctime(&(task->exec_time)));
    task = task->next;
  }
}

int main() {
  /* Add some tasks to the task list */
  add_task(1, "Task 1", time(NULL) + 3);
  add_task(2, "Task 2", time(NULL) + 5);
  add_task(3, "Task 3", time(NULL) + 7);

  /* Execution loop */
  while (1) {
    execute_tasks();
    print_tasks();
    sleep(1);
  }

  return 0;
}