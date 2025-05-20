//Code Llama-13B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: post-apocalyptic
/*
 * Apocalyptic CPU Scheduler
 *
 * A simple CPU scheduler that assigns tasks to processors
 * in a post-apocalyptic world where resources are limited.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSORS 10
#define MAX_TASKS 20

typedef struct {
    int id;
    char name[20];
    int priority;
    int deadline;
    int duration;
} Task;

typedef struct {
    int id;
    char name[20];
    int num_tasks;
    Task tasks[MAX_TASKS];
} Processor;

void schedule_tasks(Processor processors[], int num_processors, Task tasks[], int num_tasks) {
    int i, j;
    for (i = 0; i < num_processors; i++) {
        for (j = 0; j < num_tasks; j++) {
            if (processors[i].num_tasks < MAX_TASKS) {
                if (tasks[j].priority > 0 && tasks[j].deadline > 0) {
                    processors[i].tasks[processors[i].num_tasks++] = tasks[j];
                    tasks[j].priority--;
                    tasks[j].deadline--;
                }
            }
        }
    }
}

int main() {
    Processor processors[MAX_PROCESSORS];
    Task tasks[MAX_TASKS];
    int num_processors, num_tasks;

    printf("Enter the number of processors: ");
    scanf("%d", &num_processors);

    for (int i = 0; i < num_processors; i++) {
        printf("Enter the name of processor %d: ", i + 1);
        scanf("%s", processors[i].name);
        processors[i].num_tasks = 0;
    }

    printf("Enter the number of tasks: ");
    scanf("%d", &num_tasks);

    for (int i = 0; i < num_tasks; i++) {
        printf("Enter the name of task %d: ", i + 1);
        scanf("%s", tasks[i].name);
        printf("Enter the priority of task %d: ", i + 1);
        scanf("%d", &tasks[i].priority);
        printf("Enter the deadline of task %d: ", i + 1);
        scanf("%d", &tasks[i].deadline);
        printf("Enter the duration of task %d: ", i + 1);
        scanf("%d", &tasks[i].duration);
    }

    schedule_tasks(processors, num_processors, tasks, num_tasks);

    printf("Scheduled tasks:\n");
    for (int i = 0; i < num_processors; i++) {
        printf("Processor %s:", processors[i].name);
        for (int j = 0; j < processors[i].num_tasks; j++) {
            printf(" %s (priority: %d, deadline: %d, duration: %d)",
                   processors[i].tasks[j].name,
                   processors[i].tasks[j].priority,
                   processors[i].tasks[j].deadline,
                   processors[i].tasks[j].duration);
        }
        printf("\n");
    }

    return 0;
}