//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 100
#define MAX_PRIORITY 10

// Task structure
typedef struct {
    int task_id;
    char task_name[20];
    int priority;
    time_t start_time;
    time_t end_time;
} Task;

// Function to compare tasks based on their start time
int compare_tasks(const void *a, const void *b) {
    const Task *task1 = (const Task *)a;
    const Task *task2 = (const Task *)b;

    if (task1->start_time < task2->start_time) {
        return -1;
    } else if (task1->start_time > task2->start_time) {
        return 1;
    } else {
        return 0;
    }
}

// Function to schedule tasks
void schedule_tasks(Task tasks[], int num_tasks) {
    // Sort tasks based on their start time
    qsort(tasks, num_tasks, sizeof(Task), compare_tasks);

    // Schedule each task
    for (int i = 0; i < num_tasks; i++) {
        printf("Task %d (%s) scheduled from %s to %s\n", tasks[i].task_id, tasks[i].task_name, ctime(&tasks[i].start_time), ctime(&tasks[i].end_time));
    }
}

// Main function
int main() {
    // Initialize tasks
    Task tasks[MAX_TASKS];
    int num_tasks = 0;

    // Add some tasks
    tasks[num_tasks].task_id = 1;
    strcpy(tasks[num_tasks].task_name, "Task 1");
    tasks[num_tasks].priority = 5;
    tasks[num_tasks].start_time = time(NULL) + 10;
    tasks[num_tasks].end_time = time(NULL) + 20;
    num_tasks++;

    tasks[num_tasks].task_id = 2;
    strcpy(tasks[num_tasks].task_name, "Task 2");
    tasks[num_tasks].priority = 3;
    tasks[num_tasks].start_time = time(NULL) + 15;
    tasks[num_tasks].end_time = time(NULL) + 25;
    num_tasks++;

    // Schedule tasks
    schedule_tasks(tasks, num_tasks);

    return 0;
}