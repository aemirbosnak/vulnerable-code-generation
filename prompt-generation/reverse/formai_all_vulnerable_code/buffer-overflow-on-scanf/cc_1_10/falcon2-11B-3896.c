//Falcon2-11B DATASET v1.0 Category: Task Scheduler ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_TASKS 10
#define MAX_NAME_LEN 10
#define MAX_DELAY_LEN 5

#define SUCCESS 0
#define FAILURE -1

typedef struct {
    char name[MAX_NAME_LEN];
    char delay[MAX_DELAY_LEN];
    int delayValue;
    bool isCancelled;
    int priority;
} Task;

Task tasks[MAX_TASKS];
int taskCount = 0;

int getTaskCount() {
    return taskCount;
}

void addTask(char* name, char* delay, int delayValue, int priority) {
    Task task;
    task.name[0] = '\0';
    task.delay[0] = '\0';
    task.delayValue = delayValue;
    task.isCancelled = false;
    task.priority = priority;

    strcpy(task.name, name);
    strcpy(task.delay, delay);

    if (taskCount < MAX_TASKS) {
        tasks[taskCount] = task;
        taskCount++;
    } else {
        printf("Maximum number of tasks reached.\n");
    }
}

int getTaskByName(char* name) {
    for (int i = 0; i < taskCount; i++) {
        if (strcmp(tasks[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void cancelTask(int taskIndex) {
    tasks[taskIndex].isCancelled = true;
}

void executeTasks() {
    for (int i = 0; i < taskCount; i++) {
        if (!tasks[i].isCancelled) {
            printf("Executing task %s with delay %s...\n", tasks[i].name, tasks[i].delay);
            sleep(tasks[i].delayValue);
            printf("Task %s completed.\n", tasks[i].name);
        }
    }
}

int main() {
    int option, taskIndex, delayValue;
    char name[MAX_NAME_LEN], delay[MAX_DELAY_LEN];

    printf("Task Scheduler\n");
    printf("1. Add Task\n");
    printf("2. Get Task Count\n");
    printf("3. Execute Tasks\n");
    printf("4. Cancel Task\n");
    printf("5. Exit\n");

    do {
        printf("\nEnter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter task name: ");
                fgets(name, MAX_NAME_LEN, stdin);
                printf("Enter delay: ");
                fgets(delay, MAX_DELAY_LEN, stdin);
                printf("Enter delay value: ");
                scanf("%d", &delayValue);
                addTask(name, delay, delayValue, 0);
                break;
            case 2:
                printf("Task count: %d\n", getTaskCount());
                break;
            case 3:
                executeTasks();
                break;
            case 4:
                printf("Enter task index to cancel: ");
                scanf("%d", &taskIndex);
                cancelTask(taskIndex);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option.\n");
                break;
        }
    } while (option!= 5);

    return 0;
}