//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 100

typedef struct {
    char name[20];
    int priority;
    int period;
    int deadline;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int completion_time;
} Task;

void add_task(Task tasks[], int *num_tasks) {
    printf("Enter task name: ");
    scanf("%s", tasks[*num_tasks].name);
    printf("Enter task priority: ");
    scanf("%d", &tasks[*num_tasks].priority);
    printf("Enter task period: ");
    scanf("%d", &tasks[*num_tasks].period);
    printf("Enter task deadline: ");
    scanf("%d", &tasks[*num_tasks].deadline);
    printf("Enter task burst time: ");
    scanf("%d", &tasks[*num_tasks].burst_time);
    (*num_tasks)++;
}

void display_tasks(Task tasks[], int num_tasks) {
    printf("\nTask\tPriority\tPeriod\tDeadline\tBurst Time\tWaiting Time\tTurnaround Time\tCompletion Time\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", tasks[i].name, tasks[i].priority, tasks[i].period, tasks[i].deadline, tasks[i].burst_time, tasks[i].waiting_time, tasks[i].turnaround_time, tasks[i].completion_time);
    }
}

void sort_tasks(Task tasks[], int num_tasks) {
    for (int i = 0; i < num_tasks - 1; i++) {
        for (int j = i + 1; j < num_tasks; j++) {
            if (tasks[i].priority > tasks[j].priority) {
                Task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }
}

void execute_tasks(Task tasks[], int num_tasks, int quantum) {
    int current_time = 0;
    int completed_tasks = 0;
    int i = 0;

    while (completed_tasks < num_tasks) {
        if (tasks[i].burst_time > quantum) {
            tasks[i].burst_time -= quantum;
            current_time += quantum;
        } else {
            tasks[i].burst_time = tasks[i].burst_time - current_time + tasks[i].waiting_time;
            current_time += tasks[i].burst_time;
            completed_tasks++;
        }
        i++;
        if (i == num_tasks) {
            i = 0;
        }
    }
}

int main() {
    Task tasks[MAX_TASKS];
    int num_tasks = 0;

    add_task(tasks, &num_tasks);
    display_tasks(tasks, num_tasks);
    sort_tasks(tasks, num_tasks);
    execute_tasks(tasks, num_tasks, 2);

    return 0;
}