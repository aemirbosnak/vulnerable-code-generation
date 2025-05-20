//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 100

// Task structure
struct task {
    char name[20];
    int priority;
    time_t start_time;
    time_t end_time;
    int duration;
};

// Function to compare tasks based on their priority
int compare_tasks(const void *a, const void *b) {
    struct task *task_a = (struct task *)a;
    struct task *task_b = (struct task *)b;

    if (task_a->priority > task_b->priority)
        return 1;
    else if (task_a->priority < task_b->priority)
        return -1;
    else
        return 0;
}

// Function to schedule tasks
void schedule_tasks(struct task tasks[], int num_tasks) {
    qsort(tasks, num_tasks, sizeof(struct task), compare_tasks);

    int i = 0;
    int j = 0;

    while (i < num_tasks && j < MAX_TASKS) {
        if (tasks[i].start_time <= tasks[j].start_time) {
            printf("Task %s starting at %ld\n", tasks[i].name, tasks[i].start_time);
            i++;
        } else {
            printf("Task %s starting at %ld\n", tasks[j].name, tasks[j].start_time);
            j++;
        }
    }
}

// Main function
int main() {
    struct task tasks[MAX_TASKS];
    int num_tasks = 0;

    while (num_tasks < MAX_TASKS) {
        printf("Enter task name: ");
        scanf("%s", tasks[num_tasks].name);

        printf("Enter task priority (1-10): ");
        scanf("%d", &tasks[num_tasks].priority);

        printf("Enter task start time (YYYY-MM-DD HH:MM:SS): ");
        scanf("%s", tasks[num_tasks].start_time);

        printf("Enter task end time (YYYY-MM-DD HH:MM:SS): ");
        scanf("%s", tasks[num_tasks].end_time);

        tasks[num_tasks].duration = difftime(mktime(tasks[num_tasks].end_time), mktime(tasks[num_tasks].start_time));
        num_tasks++;
    }

    schedule_tasks(tasks, num_tasks);

    return 0;
}