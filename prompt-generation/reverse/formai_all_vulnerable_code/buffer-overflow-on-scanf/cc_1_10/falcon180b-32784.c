//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct task {
    char name[20];
    int priority;
    time_t start_time;
    time_t end_time;
} Task;

int main() {
    Task tasks[MAX_TASKS];
    int num_tasks = 0;
    int choice;
    int i;

    do {
        printf("\nTask Scheduler Menu:\n");
        printf("1. Add task\n");
        printf("2. Remove task\n");
        printf("3. Display tasks\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(num_tasks >= MAX_TASKS) {
                    printf("Maximum number of tasks reached.\n");
                } else {
                    printf("Enter task name: ");
                    scanf("%s", tasks[num_tasks].name);
                    printf("Enter task priority (0-9): ");
                    scanf("%d", &tasks[num_tasks].priority);
                    printf("Enter task start time (YYYY-MM-DD HH:MM:SS): ");
                    scanf("%s", tasks[num_tasks].start_time);
                    printf("Enter task end time (YYYY-MM-DD HH:MM:SS): ");
                    scanf("%s", tasks[num_tasks].end_time);
                    num_tasks++;
                }
                break;

            case 2:
                printf("Enter task name to remove: ");
                scanf("%s", tasks[num_tasks].name);
                for(i=0; i<num_tasks-1; i++) {
                    if(strcmp(tasks[i].name, tasks[num_tasks-1].name) == 0) {
                        memcpy(&tasks[i], &tasks[num_tasks-1], sizeof(Task));
                        num_tasks--;
                    }
                }
                break;

            case 3:
                printf("Task List:\n");
                for(i=0; i<num_tasks; i++) {
                    printf("%s - Priority: %d - Start Time: %s - End Time: %s\n",
                            tasks[i].name, tasks[i].priority, tasks[i].start_time, tasks[i].end_time);
                }
                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice!= 4);

    return 0;
}