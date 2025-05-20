//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 100
#define MAX_PRIORITY 10

typedef struct task {
    char name[20];
    int priority;
    time_t start_time;
    time_t end_time;
    int duration;
    int completed;
} Task;

void print_task(Task task) {
    printf("Task Name: %s\n", task.name);
    printf("Priority: %d\n", task.priority);
    printf("Start Time: %s\n", ctime(&task.start_time));
    printf("End Time: %s\n", ctime(&task.end_time));
    printf("Duration: %d seconds\n", task.duration);
    printf("Completed: %s\n", task.completed? "Yes" : "No");
}

int compare_tasks(const void *a, const void *b) {
    const Task *task_a = (const Task *)a;
    const Task *task_b = (const Task *)b;
    return task_a->priority - task_b->priority;
}

int main() {
    Task tasks[MAX_TASKS];
    int num_tasks = 0;

    srand(time(NULL));

    while (num_tasks < MAX_TASKS) {
        int task_type = rand() % 3;
        if (task_type == 0) {
            char name[20];
            sprintf(name, "Task %d", num_tasks + 1);
            int priority = rand() % MAX_PRIORITY + 1;
            int duration = rand() % 60 + 1;
            time_t start_time = time(NULL) + rand() % duration;
            tasks[num_tasks] = (Task){.name = name,.priority = priority,.duration = duration,.start_time = start_time,.end_time = 0,.completed = 0};
            num_tasks++;
        } else if (task_type == 1) {
            int index = rand() % num_tasks;
            tasks[index].completed = 1;
        } else {
            int index = rand() % num_tasks;
            tasks[index].duration += rand() % 60 + 1;
        }
    }

    qsort(tasks, num_tasks, sizeof(Task), compare_tasks);

    for (int i = 0; i < num_tasks; i++) {
        print_task(tasks[i]);
    }

    return 0;
}