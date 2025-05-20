//FormAI DATASET v1.0 Category: Task Scheduler ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>

#define MAX_TASKS 5
#define MAX_NAME_LENGTH 20

// Define Task struct
typedef struct task{
    char name[MAX_NAME_LENGTH];
    int frequency;
    int last_executed;
    void (*function)(void);
}Task;

// Declare functions
void task1(void);
void task2(void);
void task3(void);
void task4(void);
void task5(void);
void add_task(void);
void remove_task(void);
void display_tasks(void);
void execute_tasks(void);

// Declare array of task structs
Task task_list[MAX_TASKS];
int num_tasks = 0;

int main(){
    int option;
    printf("*** Task Scheduler ***\n");
    while(1){
        printf("\nPlease choose an option:\n");
        printf("1. Add a task\n");
        printf("2. Remove a task\n");
        printf("3. Display task list\n");
        printf("4. Execute pending tasks\n");
        printf("0. Exit\n");
        scanf("%d", &option);
        switch(option){
            case 0:
                exit(0);
            case 1:
                add_task();
                break;
            case 2:
                remove_task();
                break;
            case 3:
                display_tasks();
                break;
            case 4:
                execute_tasks();
                break;
            default:
                printf("Invalid option selected!\n");
        }
    }
}

// Function to add a new task
void add_task(){
    if(num_tasks == MAX_TASKS){
        printf("Task list is full!\n");
        return;
    }
    Task new_task;
    printf("Enter task name: ");
    scanf("%s", new_task.name);
    printf("Enter task frequency (in seconds): ");
    scanf("%d", &new_task.frequency);
    new_task.last_executed = 0;
    printf("Task added successfully!\n");
    printf("Task ID: %d\n", num_tasks);
    // Assign function pointer
    if(num_tasks == 0){
        new_task.function = &task1;
    }
    else if(num_tasks == 1){
        new_task.function = &task2;
    }
    else if(num_tasks == 2){
        new_task.function = &task3;
    }
    else if(num_tasks == 3){
        new_task.function = &task4;
    }
    else{
        new_task.function = &task5;
    }
    // Add new task to task list
    task_list[num_tasks++] = new_task;
}

// Function to remove a task
void remove_task(){
    int task_id;
    printf("Enter task ID: ");
    scanf("%d", &task_id);
    if(task_id < 0 || task_id >= num_tasks){
        printf("Invalid task ID!\n");
        return;
    }
    for(int i = task_id; i < num_tasks - 1; i++){
        task_list[i] = task_list[i+1];
    }
    num_tasks--;
    printf("Task removed successfully!\n");
}

// Function to display all tasks
void display_tasks(){
    printf("\nTask List:\n");
    printf("Task ID\tTask Name\tTask Frequency\n");
    for(int i = 0; i < num_tasks; i++){
        printf("%d\t%s\t\t%d\n", i, task_list[i].name, task_list[i].frequency);
    }
}

// Function to execute pending tasks
void execute_tasks(){
    for(int i = 0; i < num_tasks; i++){
        Task current_task = task_list[i];
        int current_time = (int)time(NULL);
        if(current_time - current_task.last_executed >= current_task.frequency){
            printf("Executing task: %s\n", current_task.name);
            current_task.function();
            current_task.last_executed = current_time;
        }
    }
}

// Sample task functions
void task1(){
    printf("Task 1 executed!\n");
}

void task2(){
    printf("Task 2 executed!\n");
}

void task3(){
    printf("Task 3 executed!\n");
}

void task4(){
    printf("Task 4 executed!\n");
}

void task5(){
    printf("Task 5 executed!\n");
}