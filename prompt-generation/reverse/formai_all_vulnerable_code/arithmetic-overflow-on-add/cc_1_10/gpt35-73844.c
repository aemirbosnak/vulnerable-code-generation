//FormAI DATASET v1.0 Category: Task Scheduler ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct {
    char name[50];
    time_t scheduled_time;
    int priority;
    int frequency; //how often the task runs in seconds
    int times_executed;
} Task;

int main() {
    Task tasks[MAX_TASKS];
    int num_tasks = 0;
    time_t current_time;

    while (num_tasks < MAX_TASKS) {
        printf("Enter task name:\n");
        scanf("%s", tasks[num_tasks].name);

        printf("Enter task scheduling frequency (in seconds):\n");
        scanf("%d", &tasks[num_tasks].frequency);

        printf("Enter task priority (lower number means higher priority):\n");
        scanf("%d", &tasks[num_tasks].priority);

        tasks[num_tasks].scheduled_time = time(NULL) + tasks[num_tasks].frequency;
        tasks[num_tasks].times_executed = 0;

        num_tasks++;

        printf("Do you want to add another task? (y/n)\n");
        char response;
        scanf("%s", &response);
        
        if (response == 'n') {
            break;
        }
    }

    //run the tasks in the scheduler loop
    while (true) {
        current_time = time(NULL);

        for (int i = 0; i < num_tasks; i++) {
            if (current_time >= tasks[i].scheduled_time) {
                printf("%s executing...\n", tasks[i].name);
                tasks[i].times_executed++;
                tasks[i].scheduled_time = current_time + tasks[i].frequency;
            }
        }

        //sort tasks by priority
        for (int i = 0; i < num_tasks; i++) {
            for (int j = 0; j < num_tasks - 1; j++) {
                if (tasks[j].priority > tasks[j+1].priority) {
                    Task temp = tasks[j];
                    tasks[j] = tasks[j+1];
                    tasks[j+1] = temp;
                }
            }
        }

        //display task execution statistics
        printf("\nTask Execution Statistics:\n");
        for (int i = 0; i < num_tasks; i++) {
            printf("%s executed %d times.\n", tasks[i].name, tasks[i].times_executed);
        }

        //pause execution for 1 second before running again
        sleep(1);
    }

    return 0;
}