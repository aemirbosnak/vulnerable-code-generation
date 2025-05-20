//FormAI DATASET v1.0 Category: Task Scheduler ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10  // define maximum number of tasks

struct task{
    int priority;     // range 1-10
    int time;         // time (in seconds) required to complete task
    char description[50]; // brief description of the task
};

int main(){
    struct task tasks[MAX_TASKS];
    int num_tasks = 0;

    char input;

    while(1){
        printf("Enter 'a' to add a task, 'r' to remove a task, 'v' to view tasks, or 'q' to quit.\n");
        scanf(" %c", &input);

        if(input == 'q'){
            break;
        }

        switch(input){
            case 'a':{
                if(num_tasks < MAX_TASKS){
                    printf("Enter priority of task (1-10): ");
                    scanf("%d", &tasks[num_tasks].priority);

                    printf("Enter estimated time required to complete task (in seconds): ");
                    scanf("%d", &tasks[num_tasks].time);

                    printf("Enter brief task description (50 characters or less): ");
                    scanf(" %[^\n]%*c", tasks[num_tasks].description);

                    printf("Task added successfully.\n");
                    num_tasks++;
                }
                else{
                    printf("Task list is full.\n");
                }
                break;
            }

            case 'r':{
                if(num_tasks > 0){
                    int task_index = -1;
                    int highest_priority = -1;

                    for(int i=0; i<num_tasks; i++){
                        if(tasks[i].priority > highest_priority){
                            highest_priority = tasks[i].priority;
                            task_index = i;
                        }
                    }

                    printf("Removing task:\n");
                    printf("Priority: %d\nTime required: %d seconds\nDescription: %s\n", tasks[task_index].priority, tasks[task_index].time, tasks[task_index].description);
                    for(int j=task_index; j<=num_tasks-2; j++){
                        tasks[j] = tasks[j+1];
                    }
                    num_tasks--;
                }
                else{
                    printf("Task list is empty.\n");
                }
                break;
            }

            case 'v':{
                if(num_tasks > 0){
                    printf("--------\n");
                    for(int k=0; k<num_tasks; k++){
                        printf("Task %d:\n", k+1);
                        printf("Priority: %d\nTime required: %d seconds\nDescription: %s\n", tasks[k].priority, tasks[k].time, tasks[k].description);
                        printf("--------\n");
                    }
                }
                else{
                    printf("Task list is empty.\n");
                }
                break;
            }

            default:{
                printf("Invalid input. Try again.\n");
            }
        }
    }

    return 0;
}