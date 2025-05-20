//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct task {
    char name[20];
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void execute_task(struct task task) {
    printf("\nExecuting task %s with priority %d\n", task.name, task.priority);
    sleep(task.burst_time);
}

void schedule_tasks(struct task tasks[], int n) {
    int i, j, min_index;
    for (i = 0; i < n; i++) {
        tasks[i].waiting_time = tasks[i].burst_time;
    }
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (tasks[i].priority > tasks[j].priority) {
                if (tasks[i].waiting_time > tasks[j].waiting_time) {
                    tasks[i].waiting_time -= tasks[j].burst_time;
                } else {
                    tasks[j].waiting_time -= tasks[i].burst_time;
                }
            }
        }
    }
    for (i = 0; i < n; i++) {
        tasks[i].turnaround_time = tasks[i].waiting_time + tasks[i].burst_time;
        printf("\nTask %s completed with turnaround time %d\n", tasks[i].name, tasks[i].turnaround_time);
    }
}

int main() {
    int n;
    printf("Enter number of tasks: ");
    scanf("%d", &n);
    struct task tasks[n];
    printf("\nEnter task name, priority and burst time:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d", tasks[i].name, &tasks[i].priority, &tasks[i].burst_time);
    }
    schedule_tasks(tasks, n);
    return 0;
}