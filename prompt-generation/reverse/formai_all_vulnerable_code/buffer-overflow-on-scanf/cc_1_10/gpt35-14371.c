//FormAI DATASET v1.0 Category: Task Scheduler ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 10
#define MAX_TASK_NAME_LEN 20

typedef struct {
    char name[MAX_TASK_NAME_LEN];
    int priority;
    int duration;
    int time_left;
} Task;

Task tasks[MAX_TASKS];
int num_tasks = 0;

void add_task() {
    if(num_tasks >= MAX_TASKS) {
        printf("Error: maximum number of tasks reached\n");
        return;
    }

    printf("Enter task name: ");
    scanf("%s", tasks[num_tasks].name);

    printf("Enter task priority (1-10): ");
    scanf("%d", &tasks[num_tasks].priority);

    printf("Enter task duration in minutes: ");
    scanf("%d", &tasks[num_tasks].duration);

    tasks[num_tasks].time_left = tasks[num_tasks].duration;

    num_tasks++;
}

void display_tasks() {
    printf("Task list:\n");
    printf("Name\tPriority\tDuration\tTime left\n");
    for(int i = 0; i < num_tasks; i++) {
        printf("%s\t%d\t%d\t%d\n",
            tasks[i].name, tasks[i].priority,
            tasks[i].duration, tasks[i].time_left);
    }
}

void execute_tasks() {
    printf("Executing tasks...\n");
    for(int i = 0; i < num_tasks; i++) {
        printf("Task: %s\n", tasks[i].name);
        tasks[i].time_left = 0;
    }
}

void schedule_tasks() {
    // sort tasks by priority (highest first)
    for(int i = 0; i < num_tasks - 1; i++) {
        for(int j = i + 1; j < num_tasks; j++) {
            if(tasks[i].priority < tasks[j].priority) {
                Task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }

    // execute tasks in priority order until no time remains
    int total_time = 0;
    for(int i = 0; i < num_tasks; i++) {
        total_time += tasks[i].duration;
    }

    while(total_time > 0) {
        for(int i = 0; i < num_tasks; i++) {
            if(tasks[i].time_left > 0) {
                printf("Executing task: %s\n", tasks[i].name);
                tasks[i].time_left--;
                total_time--;
                if(total_time == 0) {
                    break;
                }
            }
        }
    }
}

int main() {
    int choice;
    do {
        printf("\nTask Scheduler\n");
        printf("1. Add task\n");
        printf("2. Display task list\n");
        printf("3. Execute tasks\n");
        printf("4. Schedule tasks\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_task();
                break;
            case 2:
                display_tasks();
                break;
            case 3:
                execute_tasks();
                break;
            case 4:
                schedule_tasks();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while(choice != 5);

    return 0;
}