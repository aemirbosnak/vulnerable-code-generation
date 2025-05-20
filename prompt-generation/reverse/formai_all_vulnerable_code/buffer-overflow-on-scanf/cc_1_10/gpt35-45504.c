//FormAI DATASET v1.0 Category: Task Scheduler ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a task struct containing the name and time of execution
typedef struct {
    char name[20];
    time_t execution_time;
} Task;

// Define a function to execute the task
void execute_task(Task task) {
    printf("Executing task '%s'...\n", task.name);
    time_t current_time = time(NULL);
    while(difftime(time(NULL), current_time) < task.execution_time) {
        // Busy wait for the time of execution
    }
    printf("Task '%s' successfully executed.\n", task.name);
}

// Define a circular buffer to hold the tasks
Task tasks[10];
int head = 0, tail = 0, size = 0;

// Define a function to add a task to the buffer
void add_task(char* name, time_t execution_time) {
    if(size == 10) {
        printf("Error: task queue full.\n");
        return;
    }
    Task task;
    strcpy(task.name, name);
    task.execution_time = execution_time;
    tasks[tail] = task;
    tail = (tail + 1) % 10;
    size++;
    printf("Task '%s' added to queue.\n", name);
}

// Define the main function
int main() {
    printf("This is the Mind-Bending Task Scheduler program.\n");
    printf("Please enter the number of tasks you would like to schedule: ");
    int num_tasks;
    scanf("%d", &num_tasks);
    if(num_tasks < 1) {
        printf("Error: invalid input.\n");
        return 0;
    }
    printf("Please enter the tasks in the format 'name time' (separated by a space):\n");
    for(int i = 0; i < num_tasks; i++) {
        char name[20];
        time_t execution_time;
        scanf("%s %ld", name, &execution_time);
        add_task(name, execution_time);
    }
    printf("Tasks added to queue. Starting execution...\n");
    while(size > 0) {
        execute_task(tasks[head]);
        head = (head + 1) % 10;
        size--;
    }
    printf("All tasks successfully executed.\n");
    return 0;
}