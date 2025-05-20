//FormAI DATASET v1.0 Category: Task Scheduler ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a task
struct Task {
  int id;           // ID of task
  int priority;     // Priority of task
  int duration;     // Duration of task (in seconds)
  time_t deadline;  // Deadline of task
};

// Function to add a new task
void addTask(struct Task **tasks, int *numTasks) {
  *numTasks += 1;
  *tasks = (struct Task*)realloc(*tasks, *numTasks * sizeof(struct Task));
  
  // Getting input parameters
  printf("Enter task ID: ");
  scanf("%d", &(*tasks)[*numTasks-1].id);
  
  printf("Enter task priority: ");
  scanf("%d", &(*tasks)[*numTasks-1].priority);
  
  printf("Enter task duration (in seconds): ");
  scanf("%d", &(*tasks)[*numTasks-1].duration);
  
  printf("Enter task deadline (in UTC time): ");
  scanf("%ld", &(*tasks)[*numTasks-1].deadline);
  
  printf("Task added successfully!\n");
}

// Function to display all tasks
void displayTasks(struct Task *tasks, int numTasks) {
  if(numTasks == 0) {
    printf("No tasks found!\n");
    return;
  }
  
  printf("ID\tPriority\tDuration\tDeadline\n");
  for(int i=0;i<numTasks;i++) {
    printf("%d\t%d\t\t%d\t\t%ld\n", tasks[i].id, tasks[i].priority, tasks[i].duration, tasks[i].deadline);
  }
}

// Function to execute tasks
void executeTasks(struct Task *tasks, int numTasks) {
  if(numTasks == 0) {
    printf("No tasks found!\n");
    return;
  }
  
  // Sorting tasks based on priority (higher priority first)
  for(int i=0;i<numTasks-1;i++) {
    for(int j=0;j<numTasks-i-1;j++) {
      if(tasks[j].priority < tasks[j+1].priority) {
        struct Task temp = tasks[j];
        tasks[j] = tasks[j+1];
        tasks[j+1] = temp;
      }
    }
  }
  
  // Executing tasks one by one
  for(int i=0;i<numTasks;i++) {
    printf("Task %d started!\n", tasks[i].id);
    sleep(tasks[i].duration);  // Emulating task processing time
    printf("Task %d completed!\n", tasks[i].id);
    
    // Checking for deadline
    if(time(NULL) > tasks[i].deadline) {
      printf("Task %d missed deadline!\n", tasks[i].id);
    }
  }
}

int main() {
  // Initialization
  struct Task *tasks = NULL;
  int numTasks = 0;
  
  // Displaying menu
  while(1) {
    printf("\nTask Scheduler\n");
    printf("1. Add task\n");
    printf("2. Display all tasks\n");
    printf("3. Execute tasks\n");
    printf("4. Exit\n");
    printf("Enter choice: ");
    
    int choice;
    scanf("%d", &choice);
    
    switch(choice) {
      case 1:
        addTask(&tasks, &numTasks);
        break;
      case 2:
        displayTasks(tasks, numTasks);
        break;
      case 3:
        executeTasks(tasks, numTasks);
        break;
      case 4:
        printf("Exiting program...\n");
        exit(0);
      default:
        printf("Invalid choice!\n");
    }
  }
  
  return 0;
}