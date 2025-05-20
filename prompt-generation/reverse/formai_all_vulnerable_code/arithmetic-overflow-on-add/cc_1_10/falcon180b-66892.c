//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_TASK_NAME_LEN 20

typedef struct {
    char name[MAX_TASK_NAME_LEN];
    int priority;
    int period;
    int time_left;
    int next_execution_time;
} Task;

void init_task(Task* task, char* name, int priority, int period) {
    strncpy(task->name, name, MAX_TASK_NAME_LEN);
    task->priority = priority;
    task->period = period;
    task->time_left = period;
    task->next_execution_time = time(NULL) + period;
}

int compare_tasks(const void* a, const void* b) {
    const Task* task_a = (const Task*)a;
    const Task* task_b = (const Task*)b;
    return task_a->priority - task_b->priority;
}

void print_tasks(Task* tasks, int num_tasks) {
    printf("Tasks:\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("%s (priority %d, period %d)\n", tasks[i].name, tasks[i].priority, tasks[i].period);
    }
}

void execute_tasks(Task* tasks, int num_tasks, int current_time) {
    qsort(tasks, num_tasks, sizeof(Task), compare_tasks);
    for (int i = 0; i < num_tasks; i++) {
        Task* task = &tasks[i];
        if (task->time_left <= 0) {
            task->time_left = task->period;
            printf("%s executed at %d\n", task->name, current_time);
            if (task->next_execution_time > current_time) {
                task->next_execution_time = current_time;
            }
        } else {
            task->time_left--;
        }
    }
}

int main() {
    Task tasks[MAX_TASKS];
    int num_tasks = 0;

    init_task(&tasks[num_tasks], "Task A", 1, 5);
    num_tasks++;
    init_task(&tasks[num_tasks], "Task B", 2, 10);
    num_tasks++;
    init_task(&tasks[num_tasks], "Task C", 3, 15);
    num_tasks++;

    int current_time = 0;
    while (1) {
        printf("Current time: %d\n", current_time);
        print_tasks(tasks, num_tasks);
        execute_tasks(tasks, num_tasks, current_time);
        current_time += 1;
        sleep(1);
    }

    return 0;
}