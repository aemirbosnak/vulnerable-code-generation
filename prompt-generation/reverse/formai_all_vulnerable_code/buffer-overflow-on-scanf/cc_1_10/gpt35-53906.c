//FormAI DATASET v1.0 Category: Task Scheduler ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to execute a task
void doTask(int taskID) {
  printf("Executing task %d...Done!\n", taskID);
}

// Struct for tasks
typedef struct {
  int taskID;
  char taskName[50];
  int executionTime; // Time in seconds
} Task;

int main() {
  int numTasks;
  Task tasks[10];

  srand(time(0)); // Seed for random number generator

  printf("Welcome to the Task Scheduler! Let's add some tasks.\n");

  printf("How many tasks would you like to add? ");
  scanf("%d", &numTasks);

  printf("\n");

  // Loop to add tasks
  for(int i=0; i<numTasks; i++) {
    tasks[i].taskID = i+1;

    printf("What is the name of task %d? ", i+1);
    scanf("%s", tasks[i].taskName);

    tasks[i].executionTime = (rand() % 5) + 1; // Random execution time between 1 and 5 seconds

    printf("Task %d added successfully.\n", i+1);

    printf("\n");
  }

  // Loop to execute tasks
  for(int i=0; i<numTasks; i++) {
    printf("Time: %ld seconds\n", time(0)); // Displays current time

    printf("Executing task %d: %s\n", tasks[i].taskID, tasks[i].taskName);
    printf("Estimated execution time: %d seconds.\n", tasks[i].executionTime);

    sleep(tasks[i].executionTime); // Simulating task execution with sleep function

    printf("\n");

    if(i == numTasks-1) { // Last task executed
      printf("All tasks executed! Good job, task scheduler!\n");
    }
    else { // More tasks to execute
      printf("Task %d: %s completed! What's next?\n", tasks[i].taskID, tasks[i].taskName);
      printf("\n");
    }
  }

  return 0;
}