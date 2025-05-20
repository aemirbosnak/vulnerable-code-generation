//FormAI DATASET v1.0 Category: Task Scheduler ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int taskCount = 0;

struct Task {
    int taskNumber;
    char taskName[50];
    int taskPriority;
};

void addTask() {
    struct Task task;
    task.taskNumber = taskCount + 1;
    printf("Please enter task name: ");
    scanf("%s", task.taskName);
    printf("Please enter task priority (1-10): ");
    scanf("%d", &task.taskPriority);
    printf("\nTask created: Task %d - %s (Priority: %d)\n\n", task.taskNumber, task.taskName, task.taskPriority);
    taskCount++;
}

void executeTasks() {
    if(taskCount == 0) {
        printf("\nNo tasks to execute.\n\n");
        return;
    }
    printf("\nExecuting tasks:\n\n");
    srand(time(0));
    for(int i = 0; i < taskCount; i++) {
        int taskIndex = rand() % taskCount;
        struct Task task = {taskIndex + 1};
        printf("Task %d - %s (Priority: %d) is being executed.\n", task.taskNumber, task.taskName, task.taskPriority);
    }
    printf("\nAll tasks executed.\n\n");
    taskCount = 0;
}

int main() {
    char option = ' ';
    while(option != 'E') {
        printf("Sherlock Holmes Task Scheduler\n");
        printf("------------------------------\n");
        printf("A - Add task\n");
        printf("E - Exit/Execute tasks\n");
        printf("------------------------------\n");
        printf("Please select an option: ");
        scanf(" %c", &option);

        switch(option) {
            case 'A':
                addTask();
                break;
            case 'E':
                executeTasks();
                break;
            default:
                printf("Invalid option.\n\n");
        }
    }
    return 0;
}