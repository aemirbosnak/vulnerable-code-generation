//Code Llama-13B DATASET v1.0 Category: Task Scheduler ; Style: all-encompassing
// TaskScheduler.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_TASK_NAME_LENGTH 20

typedef struct {
    char name[MAX_TASK_NAME_LENGTH];
    int start_time;
    int end_time;
    int priority;
} Task;

void print_tasks(Task tasks[], int num_tasks) {
    printf("Tasks:\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("%s: %d-%d (%d)\n", tasks[i].name, tasks[i].start_time, tasks[i].end_time, tasks[i].priority);
    }
}

void schedule_tasks(Task tasks[], int num_tasks) {
    int schedule[MAX_TASKS][2];
    int i, j;

    for (i = 0; i < num_tasks; i++) {
        schedule[i][0] = tasks[i].start_time;
        schedule[i][1] = tasks[i].end_time;
    }

    for (i = 0; i < num_tasks - 1; i++) {
        for (j = i + 1; j < num_tasks; j++) {
            if (schedule[i][1] > schedule[j][0]) {
                int temp = schedule[i][1];
                schedule[i][1] = schedule[j][0];
                schedule[j][0] = temp;
            }
        }
    }

    printf("Schedule:\n");
    for (i = 0; i < num_tasks; i++) {
        printf("%s: %d-%d\n", tasks[i].name, schedule[i][0], schedule[i][1]);
    }
}

int main() {
    Task tasks[MAX_TASKS];
    int num_tasks;

    printf("Enter number of tasks: ");
    scanf("%d", &num_tasks);

    for (int i = 0; i < num_tasks; i++) {
        printf("Enter task %d: ", i + 1);
        scanf("%s %d %d", tasks[i].name, &tasks[i].start_time, &tasks[i].end_time);
    }

    print_tasks(tasks, num_tasks);
    schedule_tasks(tasks, num_tasks);

    return 0;
}