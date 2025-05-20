//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10

struct task {
    char name[20];
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void execute_task(struct task *task) {
    printf("Executing task: %s\n", task->name);
}

void add_task(struct task *tasks, int index) {
    printf("Enter task name: ");
    scanf("%s", tasks[index].name);
    printf("Enter task priority: ");
    scanf("%d", &tasks[index].priority);
    printf("Enter task burst time: ");
    scanf("%d", &tasks[index].burst_time);
}

void display_tasks(struct task *tasks, int num_tasks) {
    printf("\nTasks:\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("Task %d: %s\n", i+1, tasks[i].name);
        printf("Priority: %d, Burst Time: %d\n", tasks[i].priority, tasks[i].burst_time);
    }
}

void schedule_tasks(struct task *tasks, int num_tasks) {
    int completed_tasks = 0;
    while (completed_tasks < num_tasks) {
        int shortest_burst_time = 9999;
        int shortest_task_index = -1;
        for (int i = 0; i < num_tasks; i++) {
            if (tasks[i].burst_time <= shortest_burst_time && tasks[i].waiting_time == 0) {
                shortest_burst_time = tasks[i].burst_time;
                shortest_task_index = i;
            }
        }
        if (shortest_task_index!= -1) {
            execute_task(&tasks[shortest_task_index]);
            tasks[shortest_task_index].burst_time--;
            tasks[shortest_task_index].waiting_time = 0;
            completed_tasks++;
        } else {
            printf("No task to execute\n");
        }
    }
}

int main() {
    struct task tasks[MAX_TASKS];
    int num_tasks;

    printf("Enter number of tasks (maximum %d): ", MAX_TASKS);
    scanf("%d", &num_tasks);

    for (int i = 0; i < num_tasks; i++) {
        add_task(tasks, i);
    }

    display_tasks(tasks, num_tasks);

    schedule_tasks(tasks, num_tasks);

    return 0;
}