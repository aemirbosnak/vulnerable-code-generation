//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_PRIORITY 10

struct task {
    char name[50];
    int priority;
    int duration;
    int start_time;
    int end_time;
};

void display_tasks(struct task tasks[], int num_tasks) {
    for (int i = 0; i < num_tasks; i++) {
        printf("%s (%d) - %d to %d\n", tasks[i].name, tasks[i].priority, tasks[i].start_time, tasks[i].end_time);
    }
}

int main() {
    struct task tasks[MAX_TASKS];
    int num_tasks = 0;
    int choice = 0;
    int task_index = 0;

    srand(time(NULL));

    while (choice!= 4) {
        printf("\nChoose an option:\n");
        printf("1. Add a task\n2. Remove a task\n3. Display tasks\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_tasks >= MAX_TASKS) {
                    printf("Maximum number of tasks reached!\n");
                } else {
                    printf("Enter task name (max 50 characters): ");
                    scanf("%s", tasks[num_tasks].name);
                    printf("Enter task priority (1-10): ");
                    scanf("%d", &tasks[num_tasks].priority);
                    printf("Enter task duration (in seconds): ");
                    scanf("%d", &tasks[num_tasks].duration);
                    tasks[num_tasks].start_time = rand() % (60 * 60 * 24);
                    tasks[num_tasks].end_time = tasks[num_tasks].start_time + tasks[num_tasks].duration;
                    num_tasks++;
                }
                break;
            case 2:
                if (num_tasks == 0) {
                    printf("No tasks to remove!\n");
                } else {
                    printf("Enter task index to remove: ");
                    scanf("%d", &task_index);
                    if (task_index >= num_tasks || task_index < 0) {
                        printf("Invalid task index!\n");
                    } else {
                        for (int i = task_index; i < num_tasks - 1; i++) {
                            tasks[i] = tasks[i + 1];
                        }
                        num_tasks--;
                    }
                }
                break;
            case 3:
                display_tasks(tasks, num_tasks);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}