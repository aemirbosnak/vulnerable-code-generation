//FormAI DATASET v1.0 Category: Task Scheduler ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Structure to hold task info */
typedef struct {
    int id;
    char name[20];
    int priority;
    int interval; // in seconds
    time_t next_exec; // timestamp of next execution
    void (*func_ptr)(void); // function pointer for task function
} Task;

/* Function declarations */
void print_tasks(Task *tasks, int num_tasks);
void execute_task(Task *task);
void task_1(void);
void task_2(void);
void task_3(void);

int main() {
    int num_tasks = 3;
    
    /* Initialize tasks */
    Task tasks[num_tasks];
    tasks[0].id = 1;
    tasks[0].priority = 2;
    tasks[0].interval = 5;
    tasks[0].next_exec = time(NULL) + tasks[0].interval;
    tasks[0].func_ptr = &task_1;
    strcpy(tasks[0].name, "Task 1");
    
    tasks[1].id = 2;
    tasks[1].priority = 1;
    tasks[1].interval = 10;
    tasks[1].next_exec = time(NULL) + tasks[1].interval;
    tasks[1].func_ptr = &task_2;
    strcpy(tasks[1].name, "Task 2");
    
    tasks[2].id = 3;
    tasks[2].priority = 3;
    tasks[2].interval = 7;
    tasks[2].next_exec = time(NULL) + tasks[2].interval;
    tasks[2].func_ptr = &task_3;
    strcpy(tasks[2].name, "Task 3");
    
    /* Main loop */
    while (1) {
        /* Check current time */
        time_t current_time = time(NULL);
        
        /* Execute tasks that are due */
        for (int i = 0; i < num_tasks; i++) {
            if (current_time >= tasks[i].next_exec) {
                printf("Executing task %s\n", tasks[i].name);
                execute_task(&tasks[i]);
                tasks[i].next_exec = current_time + tasks[i].interval;
            }
        }
        
        /* Sleep for 1 second */
        sleep(1);
    }
    
    return 0;
}

/* Function to execute task */
void execute_task(Task *task) {
    (*(task->func_ptr))();
}

/* Example task functions */
void task_1(void) {
    printf("Executing Task 1...\n");
}

void task_2(void) {
    printf("Executing Task 2...\n");
}

void task_3(void) {
    printf("Executing Task 3...\n");
}

/* Function to print task info */
void print_tasks(Task *tasks, int num_tasks) {
    printf("ID\tName\tPriority\tInterval\tNext Exec Time\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("%d\t%s\t%d\t\t%d\t\t%ld\n", tasks[i].id, tasks[i].name, tasks[i].priority, tasks[i].interval, tasks[i].next_exec);
    }
}