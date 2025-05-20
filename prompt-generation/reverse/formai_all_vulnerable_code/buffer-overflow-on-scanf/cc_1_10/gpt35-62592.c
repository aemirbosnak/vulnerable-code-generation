//FormAI DATASET v1.0 Category: Task Scheduler ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Task {
    char name[30];
    int priority;
    int duration;
    int frequency;
    struct Task *next;
} Task;

Task *head = NULL;

void addTask(char name[], int priority, int duration, int frequency) {
    Task *newTask = malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->priority = priority;
    newTask->duration = duration;
    newTask->frequency = frequency;
    newTask->next = NULL;

    if(head == NULL) {
        head = newTask;
    } else {
        Task *current = head;
        Task *prev = NULL;
        while(current != NULL && current->priority >= priority) {
            prev = current;
            current = current->next;
        }
        if(prev == NULL) {
            head = newTask;
        } else {
            prev->next = newTask;
        }
        newTask->next = current;
    }
}

void deleteTask(char name[]) {
    Task *current = head;
    Task *prev = NULL;
    while(current != NULL && strcmp(current->name, name) != 0) {
        prev = current;
        current = current->next;
    }
    if(current == NULL) {
        printf("Task not found.\n");
        return;
    }
    if(prev == NULL) {
        head = current->next;
    } else {
        prev->next = current->next;
    }
    free(current);
    printf("Task deleted successfully.\n");
}

void printTasks() {
    if(head == NULL) {
        printf("No tasks found.\n");
    } else {
        printf("Tasks:\n");
        Task *current = head;
        while(current != NULL) {
            printf("Name: %s\n", current->name);
            printf("Priority: %d\n", current->priority);
            printf("Duration: %d\n", current->duration);
            printf("Frequency: %d\n", current->frequency);
            printf("----------------------\n");
            current = current->next;
        }
    }
}

void runTask(char name[]) {
    Task *current = head;
    while(current != NULL && strcmp(current->name, name) != 0) {
        current = current->next;
    }
    if(current == NULL) {
        printf("Task not found.\n");
        return;
    }
    time_t now = time(NULL);
    printf("Task started at %s\n", ctime(&now));
    int iterations = current->duration / current->frequency;
    for(int i = 1; i <= iterations; i++) {
        printf("%d iteration(s) completed.\n", i);
        printf("Waiting %d seconds...\n", current->frequency);
        sleep(current->frequency);
    }
    printf("Task finished.\n");
}

int main() {
    while(1) {
        printf("Choose an option:\n");
        printf("1. Add a task\n");
        printf("2. Delete a task\n");
        printf("3. Print all tasks\n");
        printf("4. Run a task\n");
        printf("5. Quit\n");
        int option;
        scanf("%d", &option);
        switch(option) {
            case 1: {
                char name[30];
                int priority, duration, frequency;
                printf("Enter task name: ");
                scanf("%s", name);
                printf("Enter task priority (1-10): ");
                scanf("%d", &priority);
                printf("Enter task duration (in seconds): ");
                scanf("%d", &duration);
                printf("Enter task frequency (in seconds): ");
                scanf("%d", &frequency);
                addTask(name, priority, duration, frequency);
                break;
            }
            case 2: {
                char name[30];
                printf("Enter task name: ");
                scanf("%s", name);
                deleteTask(name);
                break;
            }
            case 3: {
                printTasks();
                break;
            }
            case 4: {
                char name[30];
                printf("Enter task name: ");
                scanf("%s", name);
                runTask(name);
                break;
            }
            case 5: {
                exit(0);
            }
            default: {
                printf("Invalid option.\n");
                break;
            }
        }
    }
    return 0;
}