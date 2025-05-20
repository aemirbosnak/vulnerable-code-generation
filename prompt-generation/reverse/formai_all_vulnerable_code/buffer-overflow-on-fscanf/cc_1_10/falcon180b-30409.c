//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 100
#define MAX_PRIORITY 10

// Task structure
typedef struct {
    int task_id;
    char task_name[30];
    int task_priority;
    int task_duration;
    int task_start_time;
    int task_end_time;
    int task_wait_time;
} Task;

// Function to compare task priorities
int compare_priority(const void *a, const void *b) {
    Task *task_a = (Task *)a;
    Task *task_b = (Task *)b;

    if (task_a->task_priority > task_b->task_priority) {
        return 1;
    } else if (task_a->task_priority < task_b->task_priority) {
        return -1;
    } else {
        return 0;
    }
}

// Function to schedule tasks using Round Robin scheduling algorithm
void schedule_tasks(Task tasks[], int num_tasks) {
    int current_time = 0;
    int completed_tasks = 0;
    int context_switches = 0;

    qsort(tasks, num_tasks, sizeof(Task), compare_priority);

    for (int i = 0; i < num_tasks; i++) {
        if (tasks[i].task_start_time <= current_time) {
            if (tasks[i].task_duration <= current_time - tasks[i].task_start_time) {
                printf("Task %d completed at time %d\n", tasks[i].task_id, current_time);
                completed_tasks++;
            } else {
                printf("Task %d started at time %d\n", tasks[i].task_id, current_time);
            }

            tasks[i].task_end_time = current_time + tasks[i].task_duration;
            tasks[i].task_wait_time = tasks[i].task_end_time - tasks[i].task_start_time;
        } else {
            break;
        }

        current_time += tasks[i].task_duration;
        context_switches++;
    }

    printf("Number of completed tasks: %d\n", completed_tasks);
    printf("Number of context switches: %d\n", context_switches);
}

// Function to read tasks from input file
void read_tasks(Task tasks[], int num_tasks) {
    FILE *fp;
    fp = fopen("tasks.txt", "r");

    if (fp == NULL) {
        printf("Unable to open tasks file\n");
        exit(0);
    }

    int task_id = 1;
    while (fscanf(fp, "%s %d %d %d", tasks[task_id].task_name, &tasks[task_id].task_priority, &tasks[task_id].task_duration, &tasks[task_id].task_start_time)!= EOF) {
        task_id++;
    }

    fclose(fp);
}

// Main function
int main() {
    Task tasks[MAX_TASKS];
    int num_tasks = 0;

    // Read tasks from input file
    read_tasks(tasks, MAX_TASKS);
    num_tasks = sizeof(tasks) / sizeof(tasks[0]);

    // Schedule tasks using Round Robin scheduling algorithm
    schedule_tasks(tasks, num_tasks);

    return 0;
}