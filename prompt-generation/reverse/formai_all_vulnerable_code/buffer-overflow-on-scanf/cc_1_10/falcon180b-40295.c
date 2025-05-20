//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct task {
    char name[20];
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int start_time;
    int end_time;
} Task;

Task tasks[MAX_TASKS];
int num_tasks = 0;

void *runner(void *arg) {
    int i;
    for (i = 0; i < num_tasks; i++) {
        printf("Task %s is running...\n", tasks[i].name);
        sleep(tasks[i].burst_time / (tasks[i].priority + 1));
        printf("Task %s has finished.\n", tasks[i].name);
    }
    pthread_exit(0);
}

int compare(const void *a, const void *b) {
    Task task1 = *(Task *)a;
    Task task2 = *(Task *)b;

    if (task1.priority > task2.priority)
        return 1;
    else if (task1.priority < task2.priority)
        return -1;
    else
        return 0;
}

void add_task() {
    printf("Enter task name: ");
    scanf("%s", tasks[num_tasks].name);
    printf("Enter task priority (1-10): ");
    scanf("%d", &tasks[num_tasks].priority);
    printf("Enter task burst time: ");
    scanf("%d", &tasks[num_tasks].burst_time);
    tasks[num_tasks].waiting_time = 0;
    tasks[num_tasks].turnaround_time = 0;
    tasks[num_tasks].start_time = 0;
    tasks[num_tasks].end_time = 0;
    num_tasks++;
}

void display_tasks() {
    printf("\nTask List:\n");
    printf("-----------------------------\n");
    printf("Task Name\tPriority\tBurst Time\n");
    qsort(tasks, num_tasks, sizeof(Task), compare);
    int i;
    for (i = 0; i < num_tasks; i++) {
        printf("%s\t\t%d\t\t%d\n", tasks[i].name, tasks[i].priority, tasks[i].burst_time);
    }
}

int main() {
    int i, choice;

    printf("\nWelcome to the Task Scheduler!\n");
    printf("---------------------------------\n");

    while (1) {
        display_tasks();
        printf("\nEnter your choice:\n");
        printf("1. Add task\n2. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_task();
            break;
        case 2:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}