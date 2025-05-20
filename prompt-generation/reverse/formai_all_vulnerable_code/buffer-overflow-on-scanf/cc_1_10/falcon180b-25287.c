//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 100

typedef struct {
    int id;
    char name[20];
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int completion_time;
} Task;

void add_task(Task* task, int count) {
    printf("Enter task id: ");
    scanf("%d", &task->id);
    printf("Enter task name: ");
    scanf("%s", task->name);
    printf("Enter task priority: ");
    scanf("%d", &task->priority);
    printf("Enter task burst time: ");
    scanf("%d", &task->burst_time);
}

int compare_priority(const void* a, const void* b) {
    const Task* task1 = (const Task*)a;
    const Task* task2 = (const Task*)b;
    return task1->priority - task2->priority;
}

void execute_tasks(Task tasks[], int count) {
    qsort(tasks, count, sizeof(Task), compare_priority);

    int completed_tasks = 0;
    int current_time = 0;

    while (completed_tasks < count) {
        int i;
        for (i = 0; i < count; i++) {
            if (tasks[i].burst_time > current_time && tasks[i].waiting_time == 0) {
                tasks[i].waiting_time = current_time;
                break;
            }
        }

        current_time += 1;

        for (i = 0; i < count; i++) {
            if (tasks[i].burst_time > current_time && tasks[i].waiting_time > 0) {
                tasks[i].waiting_time -= 1;
            } else if (tasks[i].burst_time <= current_time) {
                tasks[i].completion_time = current_time;
                completed_tasks++;
            }
        }
    }
}

int main() {
    Task tasks[MAX_TASKS];
    int count = 0;

    while (count < MAX_TASKS) {
        Task task;
        add_task(&task, count);
        tasks[count] = task;
        count++;
    }

    execute_tasks(tasks, count);

    return 0;
}