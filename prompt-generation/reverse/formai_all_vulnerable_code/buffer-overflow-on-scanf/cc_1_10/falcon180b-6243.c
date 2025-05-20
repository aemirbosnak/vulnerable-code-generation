//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

struct task {
    int id;
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void execute_task(struct task *task) {
    printf("Executing task %d with burst time %d\n", task->id, task->burst_time);
    sleep(task->burst_time / (task->priority + 1));
}

void schedule_tasks(struct task tasks[], int n) {
    int completed = 0;
    int current_time = 0;

    while (completed < n) {
        int i;
        for (i = 0; i < n; i++) {
            if (tasks[i].id == completed && tasks[i].waiting_time == 0) {
                execute_task(&tasks[i]);
                completed++;
                break;
            }
        }

        if (i == n) {
            current_time++;

            for (i = 0; i < n; i++) {
                if (tasks[i].id == completed && tasks[i].waiting_time > 0) {
                    tasks[i].waiting_time--;
                }
            }
        }
    }
}

void print_schedule(struct task tasks[], int n) {
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", tasks[i].id, tasks[i].burst_time, tasks[i].waiting_time, tasks[i].turnaround_time);
    }
}

int main() {
    struct task tasks[MAX];
    int n;

    printf("Enter the number of tasks: ");
    scanf("%d", &n);

    printf("Enter task details:\n");

    for (int i = 0; i < n; i++) {
        printf("For task %d:\n", i + 1);
        printf("Enter burst time: ");
        scanf("%d", &tasks[i].burst_time);

        printf("Enter priority (higher value means higher priority): ");
        scanf("%d", &tasks[i].priority);
    }

    for (int i = 0; i < n; i++) {
        tasks[i].id = i + 1;
        tasks[i].waiting_time = 0;
    }

    schedule_tasks(tasks, n);

    printf("\nSchedule:\n");
    print_schedule(tasks, n);

    return 0;
}