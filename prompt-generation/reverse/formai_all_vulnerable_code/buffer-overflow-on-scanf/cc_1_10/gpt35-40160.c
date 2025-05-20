//FormAI DATASET v1.0 Category: Task Scheduler ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_TASKS 10 //maximum number of tasks that can be scheduled
#define MAX_TASK_NAME_LEN 20 //maximum length of task name

typedef struct task {
    int id;
    char name[MAX_TASK_NAME_LEN];
    int priority;
    int interval;
    bool enabled;
    int time_remaining;
} Task;

Task taskList[MAX_TASKS];
int numTasks = 0;

void addTask() {
    if (numTasks >= MAX_TASKS) {
        printf("No more tasks can be scheduled.\n");
        return;
    }

    Task newTask;
    newTask.id = numTasks + 1;

    printf("Enter task name: ");
    scanf("%s", newTask.name);

    printf("Enter task priority (1-10): ");
    scanf("%d", &newTask.priority);

    printf("Enter task interval (in seconds): ");
    scanf("%d", &newTask.interval);

    newTask.enabled = true;
    newTask.time_remaining = newTask.interval;

    taskList[numTasks++] = newTask;
}

void removeTask() {
    int taskId;

    printf("Enter task ID to remove: ");
    scanf("%d", &taskId);

    if (taskId > numTasks || taskId <= 0) {
        printf("Invalid task ID.\n");
        return;
    }

    for (int i = taskId - 1; i < numTasks - 1; i++) {
        taskList[i] = taskList[i + 1];
    }

    numTasks--;
}

void displayTaskList() {
    printf("ID\tName\tPriority\tInterval\tEnabled\n");

    for (int i = 0; i < numTasks; i++) {
        printf("%d\t%s\t%d\t\t%d\t\t%s\n", taskList[i].id, taskList[i].name, taskList[i].priority, taskList[i].interval, taskList[i].enabled ? "Yes" : "No");
    }
}

void runTask(Task* task) {
    printf("Running task %s\n", task->name);
}

int main() {
    int choice;

    do {
        printf("\n*** Task Scheduler ***\n");
        printf("1. Add Task\n");
        printf("2. Remove Task\n");
        printf("3. Display Task List\n");
        printf("4. Run Tasks\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                removeTask();
                break;
            case 3:
                displayTaskList();
                break;
            case 4:
                printf("Running scheduled tasks...\n");

                for (int i = 0; i < numTasks; i++) {
                    if (taskList[i].enabled) {
                        taskList[i].time_remaining--;

                        if (taskList[i].time_remaining == 0) {
                            runTask(&taskList[i]);
                            taskList[i].time_remaining = taskList[i].interval;
                        }
                    }
                }

                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    } while (true);

    return 0;
}