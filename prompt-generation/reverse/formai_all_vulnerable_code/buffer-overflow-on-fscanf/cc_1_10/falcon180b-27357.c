//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of tasks that can be scheduled
#define MAX_TASKS 10

// Define the structure for a task
typedef struct {
    char name[20]; // Task name
    int priority; // Task priority
    time_t start_time; // Task start time
    time_t end_time; // Task end time
} Task;

// Function to compare tasks based on their priority
int compare_tasks(const void *a, const void *b) {
    const Task *task_a = (const Task *)a;
    const Task *task_b = (const Task *)b;

    if (task_a->priority > task_b->priority) {
        return -1;
    } else if (task_a->priority < task_b->priority) {
        return 1;
    } else {
        return 0;
    }
}

// Function to schedule tasks using round-robin algorithm
void schedule_tasks(Task tasks[], int num_tasks) {
    int current_task = 0;
    time_t current_time = time(NULL);

    while (current_time < tasks[current_task].end_time) {
        if (current_time >= tasks[current_task].start_time) {
            printf("Executing task %s with priority %d\n", tasks[current_task].name, tasks[current_task].priority);
        } else {
            printf("Waiting for task %s to start\n", tasks[current_task].name);
        }

        current_time += tasks[current_task].end_time - tasks[current_task].start_time;
        current_task = (current_task + 1) % num_tasks;
    }
}

// Function to read tasks from a file
int read_tasks_from_file(Task tasks[], int num_tasks, FILE *file) {
    int i = 0;

    while (i < num_tasks && fscanf(file, "%s %d %ld %ld", tasks[i].name, &tasks[i].priority, &tasks[i].start_time, &tasks[i].end_time) == 4) {
        i++;
    }

    return i;
}

// Function to write tasks to a file
void write_tasks_to_file(Task tasks[], int num_tasks, FILE *file) {
    for (int i = 0; i < num_tasks; i++) {
        fprintf(file, "%s %d %ld %ld\n", tasks[i].name, tasks[i].priority, tasks[i].start_time, tasks[i].end_time);
    }
}

int main() {
    Task tasks[MAX_TASKS];
    int num_tasks = 0;

    // Read tasks from input file
    FILE *input_file = fopen("tasks.txt", "r");

    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    num_tasks = read_tasks_from_file(tasks, MAX_TASKS, input_file);

    if (num_tasks == 0) {
        printf("Error: No tasks found in input file.\n");
        return 1;
    }

    // Schedule tasks using round-robin algorithm
    schedule_tasks(tasks, num_tasks);

    fclose(input_file);

    // Write tasks to output file
    FILE *output_file = fopen("scheduled_tasks.txt", "w");

    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        return 1;
    }

    write_tasks_to_file(tasks, num_tasks, output_file);

    fclose(output_file);

    return 0;
}