//FormAI DATASET v1.0 Category: Task Scheduler ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_TASKS 5
#define MAX_PRIORITY 10
#define MAX_HOUR 24
#define MAX_MINUTE 60

struct task {
    int id; // Unique ID for the task
    char description[50]; // Description of the task
    int priority; // Priority of the task
    int hour; // Hour the task is scheduled for
    int minute; // Minute the task is scheduled for
};

int num_tasks = 0;
struct task tasks[NUM_TASKS];

void add_task() {
    if (num_tasks >= NUM_TASKS) {
        printf("Task list is full!\n");
        return;
    }

    struct task new_task;

    // Generate random values for new task
    new_task.id = rand() % 1000;
    sprintf(new_task.description, "Task %d", new_task.id);
    new_task.priority = rand() % MAX_PRIORITY + 1;
    new_task.hour = rand() % MAX_HOUR;
    new_task.minute = rand() % MAX_MINUTE;

    tasks[num_tasks] = new_task;
    num_tasks++;

    printf("Added new task:\n");
    printf(" ID: %d\n Description: %s\n Priority: %d\n Time: %d:%d\n",
            new_task.id, new_task.description, new_task.priority, new_task.hour, new_task.minute);
}

void delete_task(int id) {
    int index = -1;

    for (int i = 0; i < num_tasks; i++) {
        if (tasks[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Task with ID %d not found!\n", id);
        return;
    }

    for (int i = index; i < num_tasks - 1; i++) {
        tasks[i] = tasks[i+1];
    }

    num_tasks--;

    printf("Deleted task with ID %d.\n", id);
}

void print_tasks() {
    if (num_tasks == 0) {
        printf("Task list is empty!\n");
        return;
    }

    printf("Tasks:\n");

    for (int i = 0; i < num_tasks; i++) {
        printf(" ID: %d\n Description: %s\n Priority: %d\n Time: %d:%d\n",
                tasks[i].id, tasks[i].description, tasks[i].priority, tasks[i].hour, tasks[i].minute);
    }
}

void execute_task(int priority) {
    int index = -1;

    for (int i = 0; i < num_tasks; i++) {
        if (tasks[i].priority == priority) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("No tasks found with priority %d\n", priority);
        return;
    }

    printf("Executing task:\n");
    printf(" ID: %d\n Description: %s\n Priority: %d\n Time: %d:%d\n",
            tasks[index].id, tasks[index].description, tasks[index].priority, tasks[index].hour, tasks[index].minute);

    delete_task(tasks[index].id);
}

int main() {
    srand(time(NULL));

    // Add some initial tasks
    add_task();
    add_task();
    add_task();

    while (1) {
        char input[10];

        printf("\nEnter command (add, delete, print, execute): ");
        scanf("%s", input);

        if (strcmp(input, "add") == 0) {
            add_task();
        } else if (strcmp(input, "delete") == 0) {
            int id;
            printf("Enter task ID to delete: ");
            scanf("%d", &id);
            delete_task(id);
        } else if (strcmp(input, "print") == 0) {
            print_tasks();
        } else if (strcmp(input, "execute") == 0) {
            int priority;
            printf("Enter priority level to execute: ");
            scanf("%d", &priority);
            execute_task(priority);
        } else {
            printf("Invalid command!\n");
        }
    }

    return 0;
}