//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <pthread.h>

#define MAX_TASKS 100

// Define a structure to hold task information
typedef struct {
    char name[50];
    int delay;
    int repeat;
} Task;

// Task list
Task taskList[MAX_TASKS];
int taskCount = 0;
pthread_mutex_t lock;

// Function to execute a task
void* executeTask(void* arg) {
    Task* task = (Task*)arg;
    for (int i = 0; i < task->repeat; i++) {
        sleep(task->delay);
        time_t now = time(NULL);
        printf("Task '%s' executed at %s\n", task->name, ctime(&now));
    }
    return NULL;
}

// Function to add a new task
void addTask(const char* name, int delay, int repeat) {
    pthread_mutex_lock(&lock);
    if (taskCount < MAX_TASKS) {
        strncpy(taskList[taskCount].name, name, sizeof(taskList[taskCount].name) - 1);
        taskList[taskCount].delay = delay;
        taskList[taskCount].repeat = repeat;
        taskCount++;
        printf("Task '%s' added with %d seconds delay and will repeat %d times.\n", name, delay, repeat);
    } else {
        printf("Task list is full! Cannot add more tasks.\n");
    }
    pthread_mutex_unlock(&lock);
}

// Function to print all current tasks
void printTasks() {
    pthread_mutex_lock(&lock);
    printf("\nCurrent Tasks:\n");
    for (int i = 0; i < taskCount; i++) {
        printf("Task %d: %s, Delay: %d seconds, Repeat: %d times\n", 
               i + 1, taskList[i].name, taskList[i].delay, taskList[i].repeat);
    }
    pthread_mutex_unlock(&lock);
}

// Function to prompt user for input
void inputTasks() {
    char name[50];
    int delay, repeat;

    while (1) {
        printf("Enter task name (or 'exit' to finish): ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = 0; // Remove the newline character
        if (strcmp(name, "exit") == 0) break;

        printf("Enter delay in seconds: ");
        scanf("%d", &delay);
        printf("Enter number of repeats: ");
        scanf("%d", &repeat);
        while (getchar() != '\n'); // Clear the input buffer

        addTask(name, delay, repeat);
    }
}

// Main function
int main() {
    pthread_mutex_init(&lock, NULL);
    pthread_t threads[MAX_TASKS];

    inputTasks(); // Prompt user for tasks

    // Start all tasks in separate threads
    for (int i = 0; i < taskCount; i++) {
        pthread_create(&threads[i], NULL, executeTask, (void*)&taskList[i]);
    }

    // Wait for all tasks to complete
    for (int i = 0; i < taskCount; i++) {
        pthread_join(threads[i], NULL);
    }

    printTasks(); // Print all tasks after execution

    pthread_mutex_destroy(&lock);
    return 0;
}