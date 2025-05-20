//FormAI DATASET v1.0 Category: Task Scheduler ; Style: curious
/*Greetings! Welcome to my curious C Task Scheduler program*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct {
    int task_id;
    char description[50];
    int priority;
    time_t scheduled_time;
} Task;

Task task_list[MAX_TASKS]; //list containing all tasks
int task_count = 0; //current number of tasks in list

void schedule_task() {
    Task new_task;
    new_task.task_id = task_count;
    printf("Enter task description: ");
    scanf("%s", new_task.description);
    printf("Enter task priority (1-10): ");
    scanf("%d", &new_task.priority);
    new_task.scheduled_time = time(NULL); //sets scheduled time as current time
    task_list[task_count] = new_task;
    task_count++;
    printf("Task scheduled successfully!\n");
}

void view_tasks() {
    printf("\nTask list:\n");
    printf("ID\tPriority\tScheduled Time\t\tDescription\n");    
    for(int i = 0; i < task_count; i++) {
        printf("%d\t%d\t\t", task_list[i].task_id, task_list[i].priority);
        printf("%s\t", ctime(&task_list[i].scheduled_time));
        printf("%s\n", task_list[i].description);
    }
}

int main() {
    printf("Welcome to my curious C Task Scheduler program!\n");
    int option = 0;

    while(option != 3) {
        printf("\nPlease select an option:\n");
        printf("1. Schedule a task\n");
        printf("2. View scheduled tasks\n");
        printf("3. Exit\n");

        scanf("%d", &option);

        switch(option) {
            case 1:
                schedule_task();
                break;
            case 2:
                view_tasks();
                break;
            case 3:
                printf("\nThank you for using my program! Goodbye\n");
                break;
            default:
                printf("\nInvalid option. Please select again.\n");
        }
    }
    return 0;
}