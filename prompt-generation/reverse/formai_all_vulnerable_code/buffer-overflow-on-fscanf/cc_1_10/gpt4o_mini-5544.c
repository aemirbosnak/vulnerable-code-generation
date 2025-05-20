//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int priority;
    int execution_time; // Simulated time to complete the task
} Task;

typedef struct {
    Task tasks[MAX_TASKS];
    int count;
} TaskList;

// Function Prototypes
void addTask(TaskList *list, const char *name, int priority, int exec_time);
void optimizeBootSequence(TaskList *list);
void displayTasks(TaskList *list);
void saveToFile(TaskList *list, const char *filename);
void loadFromFile(TaskList *list, const char *filename);
int compareTasks(const void *a, const void *b);

int main() {
    TaskList taskList;
    taskList.count = 0;

    loadFromFile(&taskList, "tasks.txt");

    printf("Initial Task List:\n");
    displayTasks(&taskList);

    optimizeBootSequence(&taskList);
    
    printf("\nOptimized Task List:\n");
    displayTasks(&taskList);

    saveToFile(&taskList, "optimized_tasks.txt");

    return 0;
}

void addTask(TaskList *list, const char *name, int priority, int exec_time) {
    if (list->count < MAX_TASKS) {
        strcpy(list->tasks[list->count].name, name);
        list->tasks[list->count].priority = priority;
        list->tasks[list->count].execution_time = exec_time;
        list->count++;
    } else {
        printf("Task list is full! Cannot add more tasks.\n");
    }
}

void optimizeBootSequence(TaskList *list) {
    qsort(list->tasks, list->count, sizeof(Task), compareTasks);
}

int compareTasks(const void *a, const void *b) {
    Task *taskA = (Task *)a;
    Task *taskB = (Task *)b;

    // Sort by priority (higher priority first), then by execution time
    if (taskB->priority != taskA->priority) {
        return taskB->priority - taskA->priority;
    }
    return taskA->execution_time - taskB->execution_time;
}

void displayTasks(TaskList *list) {
    for (int i = 0; i < list->count; i++) {
        printf("Task Name: %s, Priority: %d, Execution Time: %d\n",
               list->tasks[i].name, list->tasks[i].priority, list->tasks[i].execution_time);
    }
}

void saveToFile(TaskList *list, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Could not open file for writing");
        return;
    }
    
    for (int i = 0; i < list->count; i++) {
        fprintf(file, "%s %d %d\n", list->tasks[i].name, list->tasks[i].priority, list->tasks[i].execution_time);
    }
    
    fclose(file);
    printf("Tasks successfully saved to %s\n", filename);
}

void loadFromFile(TaskList *list, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file for reading");
        return;
    }

    char name[NAME_LENGTH];
    int priority, exec_time;

    while (fscanf(file, "%s %d %d", name, &priority, &exec_time) == 3) {
        addTask(list, name, priority, exec_time);
    }

    fclose(file);
    printf("Tasks successfully loaded from %s\n", filename);
}