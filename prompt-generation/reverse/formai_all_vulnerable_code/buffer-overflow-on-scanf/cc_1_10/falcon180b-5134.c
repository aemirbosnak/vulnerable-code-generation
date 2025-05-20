//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_NAME_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    int priority;
    int period;
    int deadline;
    int burst;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
    int response_time;
    int completion_time;
    int start_time;
    int end_time;
} Task;

void init_tasks(Task tasks[], int num_tasks) {
    for (int i = 0; i < num_tasks; i++) {
        tasks[i].name[0] = '\0';
        tasks[i].priority = 0;
        tasks[i].period = 0;
        tasks[i].deadline = 0;
        tasks[i].burst = 0;
        tasks[i].remaining_time = 0;
        tasks[i].waiting_time = 0;
        tasks[i].turnaround_time = 0;
        tasks[i].response_time = 0;
        tasks[i].completion_time = 0;
        tasks[i].start_time = 0;
        tasks[i].end_time = 0;
    }
}

void print_tasks(Task tasks[], int num_tasks) {
    for (int i = 0; i < num_tasks; i++) {
        printf("Task %d: %s\n", i, tasks[i].name);
        printf("Priority: %d\n", tasks[i].priority);
        printf("Period: %d\n", tasks[i].period);
        printf("Deadline: %d\n", tasks[i].deadline);
        printf("Burst: %d\n", tasks[i].burst);
        printf("Remaining time: %d\n", tasks[i].remaining_time);
        printf("Waiting time: %d\n", tasks[i].waiting_time);
        printf("Turnaround time: %d\n", tasks[i].turnaround_time);
        printf("Response time: %d\n", tasks[i].response_time);
        printf("Completion time: %d\n", tasks[i].completion_time);
        printf("Start time: %d\n", tasks[i].start_time);
        printf("End time: %d\n", tasks[i].end_time);
        printf("\n");
    }
}

int compare_tasks(const void *a, const void *b) {
    Task task1 = *(Task*)a;
    Task task2 = *(Task*)b;
    return task1.priority - task2.priority;
}

void schedule(Task tasks[], int num_tasks) {
    qsort(tasks, num_tasks, sizeof(Task), compare_tasks);

    int current_time = 0;
    int completed_tasks = 0;
    while (completed_tasks < num_tasks) {
        Task current_task = tasks[current_time];
        if (current_task.remaining_time > 0) {
            current_time++;
        } else {
            current_task.end_time = current_time;
            current_time++;
            completed_tasks++;
        }
    }
}

int main() {
    Task tasks[MAX_TASKS];
    int num_tasks;

    printf("Enter number of tasks: ");
    scanf("%d", &num_tasks);

    init_tasks(tasks, num_tasks);

    for (int i = 0; i < num_tasks; i++) {
        printf("Enter task %d name: ", i);
        scanf("%s", tasks[i].name);
        printf("Enter task %d priority: ", i);
        scanf("%d", &tasks[i].priority);
        printf("Enter task %d period: ", i);
        scanf("%d", &tasks[i].period);
        printf("Enter task %d deadline: ", i);
        scanf("%d", &tasks[i].deadline);
        printf("Enter task %d burst: ", i);
        scanf("%d", &tasks[i].burst);
    }

    schedule(tasks, num_tasks);

    print_tasks(tasks, num_tasks);

    return 0;
}