//FormAI DATASET v1.0 Category: Task Scheduler ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define TASK_COUNT 3

typedef struct{
    char name[20];
    int start_time;
    int duration;
    int priority;
} Task;

void schedule_tasks(Task tasks[], int n);

int main(){
    Task tasks[TASK_COUNT] = {
        {"Task 1", 0, 3, 1},
        {"Task 2", 2, 5, 3},
        {"Task 3", 4, 2, 2}
    };

    schedule_tasks(tasks, TASK_COUNT);

    return 0;
}

void schedule_tasks(Task tasks[], int n){
    Task current_task;
    int current_time = 0;
    int i;
    int remaining_tasks = n;

    printf("Time\tTask\n");

    while(remaining_tasks > 0){
        current_task.duration = -1;

        // Find the highest priority task that is ready to start
        for(i = 0; i < n; i++){
            if(tasks[i].start_time <= current_time && tasks[i].duration > 0 && tasks[i].priority > current_task.priority){
                current_task = tasks[i];
            }
        }

        if(current_task.duration == -1){
            printf("%d\tIdle\n", current_time);
            current_time++;
        }
        else{
            printf("%d\t%s\n", current_time, current_task.name);

            current_task.duration--;
            current_time++;

            if(current_task.duration == 0){
                remaining_tasks--;

                // Mark the task as completed
                for(i = 0; i < n; i++){
                    if(strcmp(tasks[i].name, current_task.name) == 0){
                        tasks[i].duration = 0;
                        break;
                    }
                }
            }
        }
    }

    printf("%d\tDone\n", current_time);
}