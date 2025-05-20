//FormAI DATASET v1.0 Category: Task Scheduler ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define a task struct
typedef struct Task {
    char* task_name;
    int priority;
    int deadline;
    double execution_time;
} Task;

// function to execute a task
void execute_task(Task* task) {
    printf("\n*** Executing task %s ***\n", task->task_name);
    
    // simulate task execution time
    clock_t start = clock();
    while (((double)(clock() - start)) / CLOCKS_PER_SEC < task->execution_time);
    
    printf("*** Task %s completed! ***\n", task->task_name);   
}

// function to compare tasks based on their priority
int compare_priority(const void* p1, const void* p2) {
    Task* t1 = (Task*)p1;
    Task* t2 = (Task*)p2;
    
    if (t1->priority > t2->priority)
        return -1;
    else if (t1->priority < t2->priority)
        return 1;
    else
        return 0;
}

int main() {
    // create an array of tasks
    Task tasks[] = {
        {"Task 1", 2, 500, 0.5},
        {"Task 2", 1, 300, 0.2},
        {"Task 3", 3, 600, 0.8},
        {"Task 4", 1, 400, 0.3},
        {"Task 5", 2, 200, 0.4},
        {"Task 6", 3, 700, 0.9},
        {"Task 7", 1, 600, 0.2},
        {"Task 8", 2, 800, 0.6},
        {"Task 9", 3, 900, 0.5},
        {"Task 10", 1, 1000, 0.7}
    };
    int num_tasks = sizeof(tasks) / sizeof(Task);
    
    // sort tasks by their priority (higher priority first)
    qsort(tasks, num_tasks, sizeof(Task), compare_priority);
    
    // get current time
    time_t current_time = time(NULL);
    
    // execute tasks based on their deadline
    for (int i = 0; i < num_tasks; i++) {
        // compute remaining time until deadline
        double remaining_time = difftime(tasks[i].deadline, current_time);
        
        // check if task can be executed before deadline
        if (remaining_time > tasks[i].execution_time) {
            execute_task(&tasks[i]);
            current_time = time(NULL); // update current time
        } else {
            printf("\n*** Task %s cannot be executed before deadline! ***\n", tasks[i].task_name);
        }
    }
    
    return 0;
}