//FormAI DATASET v1.0 Category: Task Scheduler ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

#define MAX_TASKS 10

typedef struct task {
    char name[30];
    int priority;
    int time_needed;
    int time_remaining;
} Task;

Task tasks[MAX_TASKS];
int num_tasks = 0;

void add_task() {
    if(num_tasks >= MAX_TASKS) {
        printf("Task list is full.\n");
        return;
    }
    
    printf("Enter task name: ");
    scanf("%s", tasks[num_tasks].name);
    
    printf("Enter task priority (0-9): ");
    scanf("%d", &tasks[num_tasks].priority);
    
    printf("Enter time needed for task (in minutes): ");
    scanf("%d", &tasks[num_tasks].time_needed);
    
    tasks[num_tasks].time_remaining = tasks[num_tasks].time_needed;
    num_tasks++;
}

void list_tasks() {
    if(num_tasks == 0) {
        printf("Task list is empty.\n");
        return;
    }
    
    printf("Task list:\n");
    printf("Name\t\tPriority\tTime needed\tTime remaining\n");
    for(int i=0; i<num_tasks; i++) {
        printf("%s\t\t%d\t\t%d\t\t%d\n", tasks[i].name, tasks[i].priority, tasks[i].time_needed, tasks[i].time_remaining);
    }
}

void schedule_tasks() {
    printf("Scheduling tasks...\n");
    int total_time = 0;
    for(int i=0; i<num_tasks; i++) {
        total_time += tasks[i].time_needed;
    }
    int current_time = 0;
    while(current_time < total_time) {
        Task* highest_priority = NULL;
        for(int i=0; i<num_tasks; i++) {
            if(tasks[i].time_remaining > 0) {
                if(highest_priority == NULL || tasks[i].priority > highest_priority->priority) {
                    highest_priority = &tasks[i];
                }
            }
        }
        if(highest_priority == NULL) {
            printf("All tasks completed!\n");
            return;
        }
        printf("%d - Executing task %s...\n", current_time, highest_priority->name);
        highest_priority->time_remaining--;
        current_time++;
    }
    printf("All tasks completed!\n");
}

int main() {
    int choice;
    do {
        printf("\nTask Scheduler\n");
        printf("1. Add task\n");
        printf("2. List tasks\n");
        printf("3. Schedule tasks\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                add_task();
                break;
            case 2:
                list_tasks();
                break;
            case 3:
                schedule_tasks();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice != 4);
    
    return 0;
}