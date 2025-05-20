//Code Llama-13B DATASET v1.0 Category: Task Scheduler ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Task {
  char name[50];
  int time;
  int priority;
};

struct TaskList {
  struct Task* tasks;
  int num_tasks;
};

struct TaskList* create_task_list() {
  struct TaskList* list = malloc(sizeof(struct TaskList));
  list->num_tasks = 0;
  list->tasks = NULL;
  return list;
}

void add_task(struct TaskList* list, struct Task* task) {
  list->num_tasks++;
  list->tasks = realloc(list->tasks, sizeof(struct Task) * list->num_tasks);
  list->tasks[list->num_tasks - 1] = *task;
}

void schedule_task(struct TaskList* list) {
  for (int i = 0; i < list->num_tasks; i++) {
    struct Task* task = &list->tasks[i];
    if (task->time <= 0) {
      printf("Task %s is done\n", task->name);
      list->num_tasks--;
      for (int j = i; j < list->num_tasks; j++) {
        list->tasks[j] = list->tasks[j + 1];
      }
      i--;
    } else {
      printf("Task %s will run in %d seconds\n", task->name, task->time);
      task->time--;
    }
  }
}

int main() {
  struct TaskList* list = create_task_list();
  struct Task task1 = {"Task 1", 5, 1};
  struct Task task2 = {"Task 2", 10, 2};
  struct Task task3 = {"Task 3", 15, 3};
  add_task(list, &task1);
  add_task(list, &task2);
  add_task(list, &task3);
  schedule_task(list);
  schedule_task(list);
  schedule_task(list);
  free(list);
  return 0;
}