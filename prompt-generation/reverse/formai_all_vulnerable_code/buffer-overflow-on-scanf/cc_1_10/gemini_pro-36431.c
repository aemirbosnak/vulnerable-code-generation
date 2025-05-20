//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_TASKS 100
#define MAX_TASK_LENGTH 100

typedef struct {
    char name[MAX_TASK_LENGTH];
    int priority;
    int duration;
} Task;

Task tasks[MAX_TASKS];
int num_tasks = 0;

int main() {
    // Greet the user
    printf("Hark! I am the taskmaster of this royal court.\n");
    printf("Pray thee, enter thy tasks and I shall schedule them accordingly.\n");

    // Get the tasks from the user
    while (num_tasks < MAX_TASKS) {
        // Get the task name
        printf("Enter the name of the task: ");
        scanf("%s", tasks[num_tasks].name);

        // Get the task priority
        printf("Enter the priority of the task (1-10): ");
        scanf("%d", &tasks[num_tasks].priority);

        // Get the task duration
        printf("Enter the duration of the task (in minutes): ");
        scanf("%d", &tasks[num_tasks].duration);

        // Increment the number of tasks
        num_tasks++;
    }

    // Sort the tasks by priority
    for (int i = 0; i < num_tasks; i++) {
        for (int j = i + 1; j < num_tasks; j++) {
            if (tasks[i].priority < tasks[j].priority) {
                Task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }

    // Print the scheduled tasks
    printf("The tasks have been scheduled as follows:\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("%d. %s (%d minutes)\n", i + 1, tasks[i].name, tasks[i].duration);
    }

    return 0;
}