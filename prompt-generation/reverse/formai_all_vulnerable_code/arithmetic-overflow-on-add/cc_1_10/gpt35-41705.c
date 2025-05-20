//FormAI DATASET v1.0 Category: Task Scheduler ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_TASKS 100
#define MAX_TASK_NAME_LENGTH 20
#define MAX_EMAIL_LENGTH 50

typedef struct {
    char task_name[MAX_TASK_NAME_LENGTH];
    bool completed;
    time_t due_date;
    char email[MAX_EMAIL_LENGTH];
} Task;

int num_tasks = 0;
Task task_list[MAX_TASKS];

void add_task(char* task_name, time_t due_date, char* email) {
    if (num_tasks >= MAX_TASKS) {
        printf("Cannot add more tasks.\n");
        return;
    }
    Task new_task;
    for (int i = 0; i < MAX_TASK_NAME_LENGTH; i++) {
        new_task.task_name[i] = task_name[i];
    }
    new_task.completed = false;
    new_task.due_date = due_date;
    for (int i = 0; i < MAX_EMAIL_LENGTH; i++) {
        new_task.email[i] = email[i];
    }
    task_list[num_tasks] = new_task;
    num_tasks++;
}

void print_task_list() {
    printf("Task List:\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("%d. %s, due: %s, email: %s, completed: %s\n", 
            i+1, 
            task_list[i].task_name, 
            ctime(&task_list[i].due_date), 
            task_list[i].email, 
            task_list[i].completed ? "yes": "no");
    }
}

void mark_task_done(int task_index) {
    if (task_index < 1 || task_index > num_tasks) {
        printf("Invalid task index.\n");
        return;
    }
    Task* task = &task_list[task_index-1];
    task->completed = true;
    printf("Task marked as completed!\n");
}

int main(void) {
    add_task("Finish C Project", time(NULL) + 86400, "john@doe.com");
    add_task("Submit Report", time(NULL) + 3600, "jane@doe.com");
    add_task("Buy Groceries", time(NULL) + 432000, "john@doe.com");
    add_task("Call Mom", time(NULL) + 7200, "jane@doe.com");
    
    print_task_list();
    
    mark_task_done(2);
    
    print_task_list();

    return 0;
}