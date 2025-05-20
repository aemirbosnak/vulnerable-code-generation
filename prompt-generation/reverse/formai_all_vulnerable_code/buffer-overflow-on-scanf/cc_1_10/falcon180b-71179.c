//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 100
#define MAX_PRIORITY 10

typedef struct {
    int taskId;
    int priority;
    int duration;
} Task;

void schedule(Task tasks[], int numTasks) {
    int i, j;
    Task temp;

    for (i = 0; i < numTasks - 1; i++) {
        for (j = 0; j < numTasks - i - 1; j++) {
            if (tasks[j].priority < tasks[j+1].priority) {
                temp = tasks[j];
                tasks[j] = tasks[j+1];
                tasks[j+1] = temp;
            }
        }
    }
}

void execute(Task tasks[], int numTasks) {
    int i;
    for (i = 0; i < numTasks; i++) {
        printf("Executing task %d with priority %d for %d seconds...\n", tasks[i].taskId, tasks[i].priority, tasks[i].duration);
        fflush(stdout);
        sleep(tasks[i].duration);
    }
}

int main() {
    int numTasks;
    printf("Enter the number of tasks: ");
    scanf("%d", &numTasks);

    Task tasks[MAX_TASKS];

    printf("Enter task ID, priority (1-10), and duration (in seconds) for each task:\n");
    for (int i = 0; i < numTasks; i++) {
        scanf("%d %d %d", &tasks[i].taskId, &tasks[i].priority, &tasks[i].duration);
    }

    schedule(tasks, numTasks);

    printf("Scheduled tasks:\n");
    for (int i = 0; i < numTasks; i++) {
        printf("Task %d with priority %d for %d seconds\n", tasks[i].taskId, tasks[i].priority, tasks[i].duration);
    }

    execute(tasks, numTasks);

    return 0;
}