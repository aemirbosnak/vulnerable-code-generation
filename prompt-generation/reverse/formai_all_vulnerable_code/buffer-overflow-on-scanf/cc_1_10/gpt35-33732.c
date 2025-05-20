//FormAI DATASET v1.0 Category: Task Scheduler ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_TASKS 10
#define MAX_TIME 100

struct Task {
    int id;
    int time;
    int priority;
};

// Function that prints the current time and the list of tasks
void printTasks(int currentTime, struct Task tasks[], int numTasks) {
    printf("Current time: %d\n", currentTime);
    printf("Task List:\n");
    for (int i = 0; i < numTasks; i++) {
        printf("Task %d: %d seconds, priority %d\n", tasks[i].id, tasks[i].time, tasks[i].priority);
    }
}

// Function that sorts the tasks by priority (higher priority first)
void sortTasks(struct Task tasks[], int numTasks) {
    for (int i = 0; i < numTasks - 1; i++) {
        for (int j = 0; j < numTasks - i - 1; j++) {
            if (tasks[j].priority < tasks[j+1].priority) {
                // swap tasks
                struct Task temp = tasks[j];
                tasks[j] = tasks[j+1];
                tasks[j+1] = temp;
            }
        }
    }
}

// Function that runs the tasks in order of priority
void runTasks(struct Task tasks[], int numTasks) {
    for (int i = 0; i < numTasks; i++) {
        printf("Running task %d...\n", tasks[i].id);
        for (int j = 1; j <= tasks[i].time; j++) {
            printf("Task %d: %d seconds\n", tasks[i].id, j);
            sleep(1); // wait 1 second
        }
    }
}

int main() {
    int numTasks;
    printf("Enter number of tasks (max %d): ", MAX_TASKS);
    scanf("%d", &numTasks);

    if (numTasks > MAX_TASKS) {
        printf("Too many tasks!\n");
        return 1;
    }

    struct Task tasks[numTasks];

    for (int i = 0; i < numTasks; i++) {
        printf("Enter task %d time (max %d): ", i+1, MAX_TIME);
        scanf("%d", &tasks[i].time);
        printf("Enter task %d priority (1-10): ", i+1);
        scanf("%d", &tasks[i].priority);
        tasks[i].id = i+1;
    }

    int currentTime = 0;
    while (1) {
        printTasks(currentTime, tasks, numTasks);
        sortTasks(tasks, numTasks);
        runTasks(tasks, numTasks);

        int allDone = 1;
        for (int i = 0; i < numTasks; i++) {
            if (tasks[i].time > 0) {
                allDone = 0;
                break;
            }
        }
        if (allDone) break;

        currentTime++;
        if (currentTime > MAX_TIME) {
            printf("Time limit exceeded!\n");
            return 1;
        }
    }

    printf("All tasks completed in %d seconds.\n", currentTime);
    return 0;
}