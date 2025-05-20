//FormAI DATASET v1.0 Category: Task Scheduler ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// Task structure
typedef struct {
    int id;
    int time;
    int priority;
    int status;
} task;

// Scheduler functions
void addTask(task* taskList, int n, task t);
void removeTask(task* taskList, int n, int id);
void sortByPriority(task* taskList, int n);
void executeTasks(task* taskList, int n);

int main() {
    int n, i, choice, id;
    task* taskList;
    task t;

    printf("Enter the number of tasks: ");
    scanf("%d", &n);

    // Allocate memory for task list
    taskList = (task*)malloc(n * sizeof(task));

    // Initialize tasks
    for (i = 0; i < n; i++) {
        taskList[i].id = i + 1;
        printf("Enter the duration and priority for Task %d: ", taskList[i].id);
        scanf("%d %d", &taskList[i].time, &taskList[i].priority);
        taskList[i].status = 0;
    }

    printf("Task List successfully created!\n");

    // Menu
    do {
        printf("\n1. Add Task\n");
        printf("2. Remove Task\n");
        printf("3. Execute Tasks\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the duration and priority for new Task: ");
            scanf("%d %d", &t.time, &t.priority);
            t.status = 0;
            addTask(taskList, n, t);
            n++;
            printf("Task successfully added!\n");
            break;

        case 2:
            printf("Enter the ID of the Task to be removed: ");
            scanf("%d", &id);
            removeTask(taskList, n, id);
            n--;
            printf("Task successfully removed!\n");
            break;

        case 3:
            executeTasks(taskList, n);
            printf("All tasks successfully executed!\n");
            break;

        case 4:
            printf("Exiting...\n");
            exit(0);
            break;

        default:
            printf("Invalid choice, please try again!\n");
        }
    } while (choice != 4);

    // Free dynamically allocated memory
    free(taskList);

    return 0;
}

// Add task function
void addTask(task* taskList, int n, task t) {
    taskList[n] = t;
    sortByPriority(taskList, n + 1);
}

// Remove task function
void removeTask(task* taskList, int n, int id) {
    int i, j;
    for (i = 0; i < n; i++) {
        if (taskList[i].id == id) {
            for (j = i; j < n - 1; j++) {
                taskList[j] = taskList[j + 1];
            }
            break;
        }
    }
}

// Sort by priority function (descending order)
void sortByPriority(task* taskList, int n) {
    int i, j;
    task temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (taskList[j].priority < taskList[j + 1].priority) {
                temp = taskList[j];
                taskList[j] = taskList[j + 1];
                taskList[j + 1] = temp;
            }
        }
    }
}

// Execute tasks function
void executeTasks(task* taskList, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Executing Task %d with duration %d seconds...\n", taskList[i].id, taskList[i].time);
        taskList[i].status = 1;
    }
}