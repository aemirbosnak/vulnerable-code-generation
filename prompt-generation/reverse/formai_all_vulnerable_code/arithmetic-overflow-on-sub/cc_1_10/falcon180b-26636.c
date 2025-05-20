//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_TASKS 100
#define PRIORITY_LEVELS 10

typedef struct task {
    int id;
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Task;

void sortTasks(Task tasks[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (tasks[i].priority > tasks[j].priority) {
                Task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of tasks: ");
    scanf("%d", &n);

    Task tasks[n];

    printf("Enter task details:\n");
    for (int i = 0; i < n; i++) {
        printf("Task %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &tasks[i].id);
        printf("Priority (1-10): ");
        scanf("%d", &tasks[i].priority);
        printf("Burst time: ");
        scanf("%d", &tasks[i].burst_time);
    }

    sortTasks(tasks, n);

    printf("\nTask ID\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        tasks[i].waiting_time = 0;
        tasks[i].turnaround_time = 0;
        for (int j = 0; j < i; j++) {
            if (tasks[j].priority >= tasks[i].priority) {
                tasks[i].waiting_time += tasks[j].burst_time;
            }
        }
        tasks[i].turnaround_time = tasks[i].waiting_time + tasks[i].burst_time;
        printf("%d\t%d\t%d\t%d\t%d\n", tasks[i].id, tasks[i].priority, tasks[i].burst_time, tasks[i].waiting_time, tasks[i].turnaround_time);
    }

    return 0;
}