//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: Alan Turing
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

#define NUM_OF_TASKS 10

typedef struct task{
    char name[20];
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
}task;

void create_task(task *t){
    printf("Enter the name of the task: ");
    scanf("%s",t->name);
    printf("Enter the priority of the task: ");
    scanf("%d",&t->priority);
    printf("Enter the burst time of the task: ");
    scanf("%d",&t->burst_time);
}

void execute_task(task *t){
    printf("\nExecuting task %s with priority %d\n",t->name,t->priority);
    sleep(t->burst_time/2);
    printf("\nTask %s completed execution\n",t->name);
}

void print_schedule(task *t, int num_of_tasks){
    printf("\nSchedule:\n");
    for(int i=0;i<num_of_tasks;i++){
        printf("Task %d: %s\n",i+1,t[i].name);
    }
}

void main(){
    task t[NUM_OF_TASKS];
    int num_of_tasks=0;

    while(num_of_tasks<NUM_OF_TASKS){
        printf("\nEnter 1 to create a new task, 0 to finish creating tasks:\n");
        int choice;
        scanf("%d",&choice);
        if(choice==1){
            create_task(&t[num_of_tasks]);
            num_of_tasks++;
        }else{
            break;
        }
    }

    printf("\nEnter the time quantum:\n");
    int time_quantum;
    scanf("%d",&time_quantum);

    int completed_tasks=0;
    int current_task=0;

    while(completed_tasks<num_of_tasks){
        execute_task(&t[current_task]);
        completed_tasks++;

        printf("\nSchedule after task %s completes:\n",t[current_task].name);
        print_schedule(t,num_of_tasks);

        current_task=(current_task+1)%num_of_tasks;
    }
}