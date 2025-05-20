//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 100

typedef struct task {
    char *name;
    time_t start_time;
    time_t end_time;
    int priority;
    int duration;
} Task;

void print_task(Task task) {
    printf("Task name: %s\n", task.name);
    printf("Start time: %s", ctime(&task.start_time));
    printf("End time: %s\n", ctime(&task.end_time));
    printf("Priority: %d\n", task.priority);
    printf("Duration: %d seconds\n\n", task.duration);
}

int compare_tasks(const void *a, const void *b) {
    Task task1 = *(Task *)a;
    Task task2 = *(Task *)b;

    if (task1.priority > task2.priority) {
        return -1;
    } else if (task1.priority < task2.priority) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int num_tasks;
    Task tasks[MAX_TASKS];

    printf("Enter the number of tasks (maximum %d): ", MAX_TASKS);
    scanf("%d", &num_tasks);

    for (int i = 0; i < num_tasks; i++) {
        printf("Enter task %d details:\n", i + 1);
        printf("Task name: ");
        scanf("%s", tasks[i].name);

        printf("Start time (YYYY-MM-DD HH:MM:SS): ");
        scanf("%s", tasks[i].start_time);

        printf("End time (YYYY-MM-DD HH:MM:SS): ");
        scanf("%s", tasks[i].end_time);

        printf("Priority (1-100): ");
        scanf("%d", &tasks[i].priority);

        printf("Duration (in seconds): ");
        scanf("%d", &tasks[i].duration);
    }

    qsort(tasks, num_tasks, sizeof(Task), compare_tasks);

    for (int i = 0; i < num_tasks; i++) {
        print_task(tasks[i]);
    }

    return 0;
}