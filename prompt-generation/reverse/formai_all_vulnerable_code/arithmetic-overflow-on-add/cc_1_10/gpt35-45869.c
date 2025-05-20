//FormAI DATASET v1.0 Category: Task Scheduler ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// define a struct to store task information
typedef struct {
    char name[50];
    int priority;
    char command[100];
    time_t scheduled_time;
    int executed;
} Task;

// declare global variables
Task task_list[50];
int num_tasks = 0;

// function to add a new task to the list
void add_task(char name[], int priority, char command[], time_t scheduled_time) {
    Task new_task;
    strcpy(new_task.name, name);
    new_task.priority = priority;
    strcpy(new_task.command, command);
    new_task.scheduled_time = scheduled_time;
    new_task.executed = 0;
    task_list[num_tasks++] = new_task;
}

// function to execute a task
void execute_task(Task task) {
    printf("Executing task: %s\n", task.name);
    system(task.command);
    task.executed = 1;
}

// function to schedule tasks
void schedule_tasks() {
    // sort the task list by priority
    for (int i = 0; i < num_tasks - 1; i++) {
        for (int j = i + 1; j < num_tasks; j++) {
            if (task_list[i].priority < task_list[j].priority) {
                Task temp = task_list[i];
                task_list[i] = task_list[j];
                task_list[j] = temp;
            }
        }
    }
    
    // execute the tasks that are due
    time_t current_time = time(NULL);
    double diff_time;
    for (int i = 0; i < num_tasks; i++) {
        diff_time = difftime(task_list[i].scheduled_time, current_time);
        if (diff_time <= 0 && !task_list[i].executed) {
            execute_task(task_list[i]);
        }
    }
}

int main() {
    // add some tasks to the list
    add_task("Task 1", 2, "ls -l", time(NULL) + 10);
    add_task("Task 2", 1, "ps", time(NULL) + 30);
    add_task("Task 3", 3, "cat /etc/passwd", time(NULL) + 20);
    
    // loop forever and schedule tasks
    while (1) {
        schedule_tasks();
        sleep(1);
    }
    
    return 0;
}