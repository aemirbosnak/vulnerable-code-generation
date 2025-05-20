//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10

// Structure for a task
struct task {
    char name[20];
    int priority;
    int duration;
    int start_time;
    int end_time;
};

// Function to compare task priorities
int compare_priorities(const void *a, const void *b) {
    struct task *task_a = (struct task *)a;
    struct task *task_b = (struct task *)b;
    return task_a->priority - task_b->priority;
}

// Function to schedule tasks using Round Robin scheduling algorithm
void schedule_tasks(struct task tasks[], int num_tasks) {
    int current_task = 0;
    int quantum = 2; // Time slice for each task

    printf("Scheduling tasks:\n");
    qsort(tasks, num_tasks, sizeof(struct task), compare_priorities);

    for (int i = 0; i < num_tasks; i++) {
        printf("Task %s scheduled at %d\n", tasks[i].name, tasks[i].start_time);
    }

    while (current_task < num_tasks) {
        int completed_tasks = 0;

        while (completed_tasks < num_tasks && tasks[current_task].start_time <= tasks[current_task].end_time) {
            if (tasks[current_task].start_time == tasks[current_task].end_time) {
                printf("Task %s completed at %d\n", tasks[current_task].name, tasks[current_task].end_time);
                current_task++;
            } else {
                tasks[current_task].start_time += quantum;
            }
            completed_tasks++;
        }

        if (current_task < num_tasks) {
            printf("Switching to task %s at %d\n", tasks[current_task].name, tasks[current_task].start_time);
        }
    }
}

int main() {
    struct task tasks[MAX_TASKS];
    int num_tasks = 0;

    // Read tasks from input file
    FILE *input_file = fopen("tasks.txt", "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    while (fscanf(input_file, "%s %d %d %d", tasks[num_tasks].name, &tasks[num_tasks].priority, &tasks[num_tasks].duration, &tasks[num_tasks].start_time)!= EOF) {
        num_tasks++;
        if (num_tasks >= MAX_TASKS) {
            printf("Error: Maximum number of tasks exceeded.\n");
            exit(1);
        }
    }

    fclose(input_file);

    // Schedule tasks
    schedule_tasks(tasks, num_tasks);

    return 0;
}