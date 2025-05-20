//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 100

struct task {
    char name[20];
    int priority;
    int start_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void init_task(struct task *task, char *name, int priority, int burst_time) {
    strcpy(task->name, name);
    task->priority = priority;
    task->burst_time = burst_time;
    task->start_time = 0;
    task->waiting_time = 0;
    task->turnaround_time = 0;
}

int compare_priority(const void *a, const void *b) {
    struct task *task_a = (struct task *)a;
    struct task *task_b = (struct task *)b;

    if (task_a->priority > task_b->priority) {
        return 1;
    } else if (task_a->priority < task_b->priority) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    int num_tasks, i;
    struct task tasks[MAX_TASKS];
    char input[50];

    printf("Enter the number of tasks: ");
    scanf("%d", &num_tasks);

    for (i = 0; i < num_tasks; i++) {
        printf("Enter the name of task %d: ", i + 1);
        scanf("%s", input);
        init_task(&tasks[i], input, rand() % 10 + 1, rand() % 50 + 1);
    }

    qsort(tasks, num_tasks, sizeof(struct task), compare_priority);

    int current_time = 0;
    int completed_tasks = 0;

    while (completed_tasks < num_tasks) {
        int min_burst_time = tasks[0].burst_time;
        int min_index = 0;

        for (i = 1; i < num_tasks; i++) {
            if (tasks[i].burst_time < min_burst_time) {
                min_burst_time = tasks[i].burst_time;
                min_index = i;
            }
        }

        if (current_time >= tasks[min_index].start_time) {
            tasks[min_index].waiting_time = current_time - tasks[min_index].start_time;
            tasks[min_index].turnaround_time = tasks[min_index].waiting_time + tasks[min_index].burst_time;
            completed_tasks++;
        }

        current_time += tasks[min_index].burst_time;
        tasks[min_index].start_time += tasks[min_index].burst_time;
    }

    printf("\nTask\tPriority\tStart Time\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (i = 0; i < num_tasks; i++) {
        printf("%s\t%d\t%d\t%d\t%d\t%d\n", tasks[i].name, tasks[i].priority, tasks[i].start_time, tasks[i].burst_time, tasks[i].waiting_time, tasks[i].turnaround_time);
    }

    return 0;
}