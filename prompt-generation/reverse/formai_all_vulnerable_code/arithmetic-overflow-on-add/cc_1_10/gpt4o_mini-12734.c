//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

typedef struct Task {
    int id;
    int interval; // Interval in seconds
    int nextExecution; // Time when the task is next scheduled to run
    struct Task *next;
} Task;

Task *head = NULL;

void addTask(int id, int interval) {
    Task *newTask = (Task *)malloc(sizeof(Task));
    newTask->id = id;
    newTask->interval = interval;
    newTask->nextExecution = time(NULL) + interval; // Schedule for the future
    newTask->next = head;
    head = newTask;
}

void executeTask(Task *task) {
    printf("Executing Task %d\n", task->id);
    task->nextExecution += task->interval; // Reschedule
}

void displayTasks() {
    Task *current = head;
    printf("Scheduled Tasks:\n");
    while (current != NULL) {
        printf("Task ID: %d, Interval: %d, Next Execution: %d\n", current->id, current->interval, current->nextExecution);
        current = current->next;
    }
}

void freeTasks() {
    Task *current = head;
    Task *tmp;
    while (current != NULL) {
        tmp = current;
        current = current->next;
        free(tmp);
    }
}

int main() {
    addTask(1, 2); // Task 1 every 2 seconds
    addTask(2, 4); // Task 2 every 4 seconds
    addTask(3, 3); // Task 3 every 3 seconds

    while (1) {
        time_t now = time(NULL);
        Task *current = head;
        
        while (current != NULL) {
            if (now >= current->nextExecution) {
                executeTask(current);
            }
            current = current->next;
        }
        
        displayTasks(); // Show status of tasks
        sleep(1); // Sleep for a second
    }

    freeTasks(); // Free allocated memory (not reached in this infinite loop)
    return 0;
}