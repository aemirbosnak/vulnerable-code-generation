//FormAI DATASET v1.0 Category: Task Scheduler ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#define MAX_TASKS 10

struct task{
    int task_id;
    int priority;
    int complete_time;
    int remaining_time;
};

typedef struct task Task;

int current_task = 0;
int time_elapsed = 0;
Task tasks[MAX_TASKS];

int main(){
    int num_tasks;
    printf("Enter the number of tasks: ");
    scanf("%d",&num_tasks);
    if(num_tasks > MAX_TASKS){
        printf("Error: Maximum number of tasks allowed is %d",MAX_TASKS);
        exit(1);
    }
    //Get inputs for tasks
    for(int i=0;i<num_tasks;i++){
        printf("Enter the priority of task %d: ",i+1);
        scanf("%d",&tasks[i].priority);
        printf("Enter the time required to complete task %d: ",i+1);
        scanf("%d",&tasks[i].complete_time);
        tasks[i].remaining_time = tasks[i].complete_time;
        tasks[i].task_id = i+1;
    }
    //Sort tasks by priority
    for(int i=0;i<num_tasks-1;i++){
        for(int j=0;j<num_tasks-i-1;j++){
            if(tasks[j].priority < tasks[j+1].priority){
                Task temp = tasks[j];
                tasks[j] = tasks[j+1];
                tasks[j+1] = temp;
            }
        }
    }
    //Run the tasks
    printf("Task Scheduler Running...\n");
    while(current_task < num_tasks){
        printf("Time Elapsed: %d seconds\n",time_elapsed);
        printf("Task %d running...\n",tasks[current_task].task_id);
        tasks[current_task].remaining_time--;
        if(tasks[current_task].remaining_time == 0){
            printf("Task %d completed!\n",tasks[current_task].task_id);
            current_task++;
        }
        time_elapsed++;
    }
    printf("All tasks completed!\n");
    return 0;
}