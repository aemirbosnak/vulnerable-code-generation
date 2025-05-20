//FormAI DATASET v1.0 Category: Task Scheduler ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

#define MAX_TASKS 10

typedef struct {
    int task_id;
    int interval;
    bool status;
    time_t last_run_time;
} Task;

Task task_list[MAX_TASKS];
int task_count = 0;

void add_task() {
    if (task_count == MAX_TASKS) {
        printf("Task List is Full!\n");
        return;
    }
    Task new_task;
    new_task.task_id = task_count + 1;
    printf("Enter Interval for Task %d: ", new_task.task_id);
    scanf("%d", &new_task.interval);
    new_task.status = true;
    new_task.last_run_time = time(NULL);
    task_list[task_count++] = new_task;
    printf("Task %d Added!\n", new_task.task_id);
}

void remove_task() {
    if (task_count == 0) {
        printf("Task List is Empty!\n");
        return;
    }
    int task_id;
    printf("Enter Task ID to Remove: ");
    scanf("%d", &task_id);
    for (int i = 0; i < task_count; i++) {
        if (task_list[i].task_id == task_id) {
            for (int j = i; j < task_count - 1; j++) {
                task_list[j] = task_list[j + 1];
            }
            task_count--;
            printf("Task %d Removed!\n", task_id);
            return;
        }
    }
    printf("Task with ID %d not Found!\n", task_id);
}

void show_all_tasks() {
    if (task_count == 0) {
        printf("Task List is Empty!\n");
        return;
    }
    printf("Task ID\tInterval\tStatus\tLast Run Time\n");
    for (int i = 0; i < task_count; i++) {
        Task current = task_list[i];
        printf("%d\t%d\t\t%s\t%s", current.task_id, current.interval, current.status ? "ON" : "OFF", ctime(&(current.last_run_time)));
    }
}

void run_task(int task_id) {
    time_t now = time(NULL);
    for (int i = 0; i < task_count; i++) {
        Task *current = &task_list[i];
        if (current->task_id == task_id) {
            if (difftime(now, current->last_run_time) >= current->interval && current->status) {
                // Execute Task Logic
                printf("Executing Task %d...\n", current->task_id);
                // Update Last Run Time for Task
                current->last_run_time = time(NULL);
            }
            else {
                printf("Task %d not Ready to Execute yet or is Disabled!\n", current->task_id);
            }
            return; // Task Found and Processed, we are done here
        }
    }
    printf("Task with ID %d not Found!\n", task_id);
}

int main() {
    while (true) {
        printf("\n------------------------------\n");
        printf("Welcome to Task Scheduler!\n");
        printf("Please choose an option:\n");
        printf("1. Add a New Task\n");
        printf("2. Remove an Existing Task\n");
        printf("3. Show all Tasks\n");
        printf("4. Run a Task\n");
        printf("0. Exit Program\n");
        printf("------------------------------\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1: add_task(); break;
            case 2: remove_task(); break;
            case 3: show_all_tasks(); break;
            case 4: {
                int task_id;
                printf("Enter Task ID to Run: ");
                scanf("%d", &task_id);
                run_task(task_id);
                break;
            }
            case 0: {
                printf("Exiting Program...\n");
                exit(EXIT_SUCCESS);
            }
            default: printf("Invalid Choice! Please Try Again.\n");
        }
        sleep(1); // Pause for 1 second between each menu iteration
    }
    return 0;
}