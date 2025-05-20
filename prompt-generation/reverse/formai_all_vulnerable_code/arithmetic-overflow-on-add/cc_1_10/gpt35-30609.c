//FormAI DATASET v1.0 Category: Task Scheduler ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Struct to hold task properties
typedef struct task_t {
    int id;
    char name[50];
    time_t start_time;
    time_t end_time;
} Task;

// Function to print tasks
void print_tasks(Task tasks[], int num_tasks) {
    printf("Current Tasks:\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("Task ID: %d\n", tasks[i].id);
        printf("Task Name: %s\n", tasks[i].name);
        printf("Start Time: %s", ctime(&tasks[i].start_time));
        printf("End Time: %s", ctime(&tasks[i].end_time));
        printf("---------------------\n");
    }
}

// Function to execute tasks
void execute_task(Task task) {
    printf("Executing task %d - %s...\n", task.id, task.name);
    printf("Task started at %s", ctime(&task.start_time));
    printf("Task finished at %s", ctime(&task.end_time));
}

int main() {
    // Seed random number generator
    srand(time(NULL));
    
    // Initialize task variables
    Task tasks[10];
    int num_tasks = 0;
    
    // Loop to add tasks
    for (int i = 0; i < 10; i++) {
        if (rand() % 2) {
            tasks[num_tasks].id = i+1;
            sprintf(tasks[num_tasks].name, "Task %d", i+1);
            time(&(tasks[num_tasks].start_time));
            tasks[num_tasks].end_time = tasks[num_tasks].start_time + (rand() % 10 + 1);
            num_tasks++;
        }
    }
    
    // Print tasks
    print_tasks(tasks, num_tasks);
    
    // Loop to execute tasks
    for (int i = 0; i < num_tasks; i++) {
        execute_task(tasks[i]);
    }
    
    return 0;
}