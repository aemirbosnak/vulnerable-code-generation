//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 100
#define MAX_PRIORITY 10

typedef struct task {
    int id;
    char name[20];
    int priority;
    time_t start_time;
    time_t end_time;
    int duration;
} Task;

void init_task(Task *task, int id, char *name, int priority, time_t start_time, time_t end_time, int duration) {
    task->id = id;
    strcpy(task->name, name);
    task->priority = priority;
    task->start_time = start_time;
    task->end_time = end_time;
    task->duration = duration;
}

void print_task(Task task) {
    printf("ID: %d, Name: %s, Priority: %d, Start Time: %s, End Time: %s, Duration: %d\n", task.id, task.name, task.priority, ctime(&task.start_time), ctime(&task.end_time), task.duration);
}

int compare_priority(const void *a, const void *b) {
    Task task_a = *(Task *)a;
    Task task_b = *(Task *)b;

    if (task_a.priority > task_b.priority) {
        return -1;
    } else if (task_a.priority < task_b.priority) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    Task tasks[MAX_TASKS];
    int num_tasks = 0;

    printf("Enter the number of tasks: ");
    scanf("%d", &num_tasks);

    for (int i = 0; i < num_tasks; i++) {
        char name[20];
        printf("Enter task %d name: ", i + 1);
        scanf("%s", name);

        int priority;
        printf("Enter task %d priority: ", i + 1);
        scanf("%d", &priority);

        time_t start_time, end_time;
        printf("Enter task %d start time (YYYY-MM-DD HH:MM:SS): ", i + 1);
        scanf("%s", ctime(&start_time));

        printf("Enter task %d end time (YYYY-MM-DD HH:MM:SS): ", i + 1);
        scanf("%s", ctime(&end_time));

        int duration = difftime(end_time, start_time);

        init_task(&tasks[i], i + 1, name, priority, start_time, end_time, duration);
    }

    qsort(tasks, num_tasks, sizeof(Task), compare_priority);

    for (int i = 0; i < num_tasks; i++) {
        print_task(tasks[i]);
    }

    return 0;
}