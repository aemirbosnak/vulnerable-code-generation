//FormAI DATASET v1.0 Category: Task Scheduler ; Style: optimized
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_TASKS 10
#define INTERVAL 10 // Time interval for executing tasks

// Structure for each task
struct task{
    int id;
    int priority;
    int remaining_time;
};

// Function to swap two tasks
void swap(struct task *t1, struct task *t2){
    struct task temp = *t1;
    *t1 = *t2;
    *t2 = temp;
}

// Function to sort tasks based on priority (higher priority tasks first)
void sortTasks(struct task taskList[], int n){
    int i, j;
    for(i=0; i<n-1; i++){
        for(j=i+1; j<n; j++){
            if(taskList[i].priority < taskList[j].priority){
                swap(&taskList[i], &taskList[j]);
            }
        }
    }
}

// Function to execute a task
void executeTask(struct task *t){
    printf("Executing task %d with priority %d\n", t->id, t->priority);
    t->remaining_time -= INTERVAL;
}

// Function to add a new task to task list
void addTask(struct task taskList[], int *n){
    if(*n >= MAX_TASKS){
        printf("Maximum number of tasks reached!\n");
        return;
    }
    struct task t;
    printf("Enter task ID: ");
    scanf("%d", &t.id);
    printf("Enter task priority (1-10): ");
    scanf("%d", &t.priority);
    printf("Enter task execution time: ");
    scanf("%d", &t.remaining_time);
    taskList[*n] = t;
    *n += 1;
    printf("Task added successfully!\n");
}

int main(){
    struct task taskList[MAX_TASKS];
    int n = 0, i;
    time_t start_time, current_time;
    double time_diff;

    printf("Task Scheduler Program\n");

    while(1){
        printf("\nCurrent tasks:\n");
        for(i=0; i<n; i++){
            printf("Task %d (Priority: %d, Remaining Time: %d)\n", taskList[i].id, taskList[i].priority, taskList[i].remaining_time);
        }
        printf("\n1. Add new task\n");
        printf("2. Execute tasks\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
        switch(choice){
            case 1:
                addTask(taskList, &n);
                break;
            case 2:
                if(n==0){
                    printf("No tasks to execute!\n");
                    break;
                }
                start_time = time(NULL);
                while(n > 0){
                    sortTasks(taskList, n);
                    executeTask(&taskList[0]);
                    if(taskList[0].remaining_time <= 0){
                        printf("Task %d completed!\n", taskList[0].id);
                        for(i=1; i<n; i++){
                            taskList[i-1] = taskList[i];
                        }
                        n--;
                    }
                    current_time = time(NULL);
                    time_diff = difftime(current_time, start_time);
                    if(time_diff >= INTERVAL){
                        break;
                    }
                }
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}