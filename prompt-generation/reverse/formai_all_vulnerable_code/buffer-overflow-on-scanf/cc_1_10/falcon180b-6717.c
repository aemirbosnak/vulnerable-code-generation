//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 100
#define MAX_PRIORITY 10
#define MAX_NAME_LEN 20

struct task {
    char name[MAX_NAME_LEN];
    int priority;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int completion_time;
    int current_time;
};

void sort_tasks(struct task tasks[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (tasks[i].arrival_time > tasks[j].arrival_time) {
                struct task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }
}

void execute_tasks(struct task tasks[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Executing task %s\n", tasks[i].name);
        tasks[i].current_time = tasks[i].arrival_time;
        while (tasks[i].current_time < tasks[i].arrival_time + tasks[i].burst_time) {
            tasks[i].current_time++;
        }
        tasks[i].waiting_time = tasks[i].current_time - tasks[i].arrival_time - tasks[i].burst_time;
        tasks[i].turnaround_time = tasks[i].completion_time - tasks[i].arrival_time;
        tasks[i].completion_time = tasks[i].current_time;
    }
}

int main() {
    struct task tasks[MAX_TASKS];
    int n = 0;

    printf("Enter the number of tasks: ");
    scanf("%d", &n);

    printf("Enter the tasks:\n");
    for (int i = 0; i < n; i++) {
        printf("Task %d:\n", i + 1);
        printf("Enter the name: ");
        scanf("%s", tasks[i].name);
        printf("Enter the priority: ");
        scanf("%d", &tasks[i].priority);
        printf("Enter the arrival time: ");
        scanf("%d", &tasks[i].arrival_time);
        printf("Enter the burst time: ");
        scanf("%d", &tasks[i].burst_time);
    }

    sort_tasks(tasks, n);
    execute_tasks(tasks, n);

    return 0;
}