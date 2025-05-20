//FormAI DATASET v1.0 Category: Task Scheduler ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_TASK_NAME 20

typedef struct {
    char name[MAX_TASK_NAME];
    int priority; 
    time_t start_time; 
} Task;

Task task_list[MAX_TASKS];
int num_tasks = 0;

void add_task() {
    if(num_tasks >= MAX_TASKS) {
        printf("Task list is full\n");
        return;
    }
    printf("Enter task name (max %d characters): ", MAX_TASK_NAME);
    scanf("%s", task_list[num_tasks].name);
    printf("Enter task priority (1-10): ");
    scanf("%d", &task_list[num_tasks].priority);
    task_list[num_tasks].start_time = time(NULL);
    num_tasks++;
    printf("Task added\n");
}

void execute_tasks() {
    if(num_tasks == 0) {
        printf("No tasks to execute\n");
        return;
    }
    int i;
    // sort tasks by priority in descending order
    for(i = 0; i < num_tasks - 1; i++) {
        int j;
        for(j = i + 1; j < num_tasks; j++) {
            if(task_list[i].priority < task_list[j].priority) {
                Task temp = task_list[i];
                task_list[i] = task_list[j];
                task_list[j] = temp;
            }
        }
    }
    // execute tasks
    for(i = 0; i < num_tasks; i++) {
        printf("Executing task: %s\n", task_list[i].name);
        // simulate task execution time
        double run_time = (double)(rand() % 10) + 1;
        time_t end_time = task_list[i].start_time + (int)run_time;
        while(time(NULL) < end_time);
        printf("Task completed\n");
    }
    // clear task list
    num_tasks = 0;
}

int main() {
    srand(time(NULL)); // seed rand()
    char command;
    do {
        printf("Enter command (a - add task, e - execute tasks, x - exit): ");
        scanf(" %c", &command);
        switch(command) {
            case 'a':
                add_task();
                break;
            case 'e':
                execute_tasks();
                break;
            case 'x':
                break;
            default:
                printf("Invalid command\n");
        }
    } while(command != 'x');
    printf("Exiting program\n");
    return 0;
}