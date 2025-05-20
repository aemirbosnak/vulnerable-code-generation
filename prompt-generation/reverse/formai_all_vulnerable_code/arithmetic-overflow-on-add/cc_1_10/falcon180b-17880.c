//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 100
#define MAX_PRIORITY 10
#define MAX_NAME_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    int priority;
    int duration;
    int start_time;
    int end_time;
} Task;

void schedule_task(Task *task);

int main() {
    Task tasks[MAX_TASKS];
    int num_tasks = 0;
    int choice;

    srand(time(NULL));

    while(1) {
        printf("Choose an option:\n");
        printf("1. Add task\n");
        printf("2. Display schedule\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(num_tasks >= MAX_TASKS) {
                    printf("Maximum number of tasks reached.\n");
                } else {
                    printf("Enter task name (max %d characters): ", MAX_NAME_LEN-1);
                    scanf("%s", tasks[num_tasks].name);
                    printf("Enter task priority (0-9): ");
                    scanf("%d", &tasks[num_tasks].priority);
                    printf("Enter task duration (in seconds): ");
                    scanf("%d", &tasks[num_tasks].duration);
                    tasks[num_tasks].start_time = rand() % (24*60*60);
                    tasks[num_tasks].end_time = tasks[num_tasks].start_time + tasks[num_tasks].duration;
                    num_tasks++;
                }
                break;
            case 2:
                printf("Task Schedule:\n");
                for(int i=0; i<num_tasks; i++) {
                    printf("%s (priority %d) - %d seconds from %d to %d\n", tasks[i].name, tasks[i].priority, tasks[i].duration, tasks[i].start_time, tasks[i].end_time);
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

void schedule_task(Task *task) {
    int current_time = time(NULL);
    int task_start_time = task->start_time;
    int task_end_time = task->end_time;

    if(current_time >= task_start_time && current_time <= task_end_time) {
        printf("%s is currently running.\n", task->name);
    } else if(current_time < task_start_time) {
        printf("%s will start in %d seconds.\n", task->name, task_start_time - current_time);
    } else {
        printf("%s ended %d seconds ago.\n", task->name, current_time - task_end_time);
    }
}