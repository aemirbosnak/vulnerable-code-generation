//FormAI DATASET v1.0 Category: Task Scheduler ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>

#define MAX_TASKS 10 // Maximum number of tasks that can be scheduled
#define MAX_NAME_LENGTH 50 // Maximum length of task name
#define MAX_PRIORITY 10 // Maximum priority task can have
#define INTERVAL 1 // Task scheduling interval in seconds

// Task struct for task scheduling
struct Task {
    char name[MAX_NAME_LENGTH];
    int priority;
    time_t next_execution_time;
    bool is_deleted;
};

int num_tasks = 0;
struct Task task_list[MAX_TASKS];

// Function to add task to task list
void add_task(char name[], int priority) {
    if (num_tasks >= MAX_TASKS) {
        printf("Max number of tasks reached. Cannot add task.\n");
        return;
    }
    struct Task new_task;
    strcpy(new_task.name, name);
    new_task.priority = priority;
    new_task.is_deleted = false;
    new_task.next_execution_time = time(NULL);
    task_list[num_tasks] = new_task;
    num_tasks++;
    printf("Task scheduled.\n");
}

// Function to remove task from task list
void remove_task(int task_index) {
    if (task_index < 0 || task_index >= num_tasks) {
        printf("Invalid task index.\n");
        return;
    }
    task_list[task_index].is_deleted = true;
    printf("Task deleted.\n");
}

// Function to update next execution time for tasks
void update_task_execution_times() {
    for (int i = 0; i < num_tasks; i++) {
        if (!task_list[i].is_deleted) {
            task_list[i].next_execution_time += INTERVAL * task_list[i].priority;
        }
    }
}

// Function to get highest priority task from task list
int get_highest_priority_task_index() {
    int highest_priority_index = -1;
    int highest_priority = MAX_PRIORITY + 1;
    for (int i = 0; i < num_tasks; i++) {
        if (!task_list[i].is_deleted && task_list[i].priority < highest_priority && task_list[i].next_execution_time <= time(NULL)) {
            highest_priority_index = i;
            highest_priority = task_list[i].priority;
        }
    }
    return highest_priority_index;
}

int main() {
    while (true) {
        // Get user input to add or remove task
        printf("\nType 'add' to schedule a new task or 'remove' to delete a task: ");
        char user_input[10];
        scanf("%s", user_input);
        if (strcmp(user_input, "add") == 0) {
            // Get task name and priority from user input
            printf("Enter task name: ");
            char task_name[MAX_NAME_LENGTH];
            scanf("%s", task_name);
            printf("Enter task priority (1-10): ");
            int task_priority;
            scanf("%d", &task_priority);
            // Add task to task list
            add_task(task_name, task_priority);
        } else if (strcmp(user_input, "remove") == 0) {
            // Get task index to remove from user input
            printf("Enter task index to delete (0-%d): ", num_tasks - 1);
            int task_index;
            scanf("%d", &task_index);
            // Remove task from task list
            remove_task(task_index);
        } else {
            printf("Invalid input.\n");
        }

        // Schedule next task based on task priorities
        int highest_priority_index = get_highest_priority_task_index();
        while (highest_priority_index != -1) {
            printf("Task '%s' with priority %d running.\n", task_list[highest_priority_index].name, task_list[highest_priority_index].priority);
            task_list[highest_priority_index].next_execution_time = time(NULL);
            update_task_execution_times();
            highest_priority_index = get_highest_priority_task_index();
        }

        // Sleep for interval before running again
        sleep(INTERVAL);
    }

    return 0;
}