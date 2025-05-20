//FormAI DATASET v1.0 Category: Task Scheduler ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct Task {
  char* name;
  int start_time;
  int duration;
  bool completed;
} Task;

void createTask(Task* task, char* name, int duration) {
  task->name = name;
  task->duration = duration;
  task->completed = false;
}

void printTask(Task* task) {
  printf("%s (%d minutes)\n", task->name, task->duration);
}

void runTask(Task* task) {
  printf("Running task '%s'...\n", task->name);
  task->completed = true;
}

int main() {
  srand(time(NULL)); // set random seed

  // create tasks
  Task task1, task2, task3, task4, task5;
  createTask(&task1, "Wake up", 10);
  createTask(&task2, "Brush teeth", 5);
  createTask(&task3, "Take a shower", 15);
  createTask(&task4, "Eat breakfast", 20);
  createTask(&task5, "Commute to work", 30);

  Task tasks[] = {task1, task2, task3, task4, task5};
  int numTasks = 5;

  // schedule tasks
  int currentTime = 0;
  while (true) {
    // choose random task
    int index = rand() % numTasks;
    Task* task = &tasks[index];

    // check if task is already completed
    if (task->completed) {
      continue;
    }

    // check if it's time to start the task
    if (currentTime < task->start_time) {
      printf("Waiting %d minutes to start task '%s'...\n", task->start_time - currentTime, task->name);
      currentTime = task->start_time;
    }

    // run the task
    runTask(task);

    // check if all tasks are completed
    bool allCompleted = true;
    for (int i = 0; i < numTasks; i++) {
      if (!tasks[i].completed) {
        allCompleted = false;
        break;
      }
    }
    if (allCompleted) {
      printf("All tasks completed!\n");
      break;
    }

    // update current time
    currentTime += task->duration;
  }

  return 0;
}