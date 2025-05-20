//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define MAX_TASKS 100

typedef struct {
    int id;
    int delay; // delay in seconds
    char message[256];
} Task;

Task taskQueue[MAX_TASKS];
int taskCount = 0;
pthread_mutex_t taskMutex;

void* executeTask(void* arg) {
    Task* task = (Task*)arg;

    // Simulate work with a delay
    sleep(task->delay);
    printf("Task ID: %d completed after %d seconds: %s\n", task->id, task->delay, task->message);
    
    return NULL;
}

void addTask(int delay, const char* message) {
    pthread_mutex_lock(&taskMutex);
    
    if (taskCount < MAX_TASKS) {
        Task newTask;
        newTask.id = taskCount + 1;
        newTask.delay = delay;
        strncpy(newTask.message, message, sizeof(newTask.message) - 1);
        newTask.message[sizeof(newTask.message) - 1] = '\0'; // Ensure null-termination

        taskQueue[taskCount] = newTask;
        taskCount++;
        
        printf("Added Task ID: %d with delay: %d seconds\n", newTask.id, delay);
    } else {
        printf("Task queue is full! Cannot add more tasks.\n");
    }
    
    pthread_mutex_unlock(&taskMutex);
}

void* scheduleTasks() {
    for (int i = 0; i < taskCount; i++) {
        pthread_t threadId;
        pthread_create(&threadId, NULL, executeTask, (void*)&taskQueue[i]);
        pthread_detach(threadId); // Detach to allow automatic reclaiming of resources
    }
    return NULL;
}

int main() {
    pthread_mutex_init(&taskMutex, NULL);

    int choice, delay;
    char message[256];

    while (1) {
        printf("Task Scheduler Menu:\n");
        printf("1. Add Task\n");
        printf("2. Execute Tasks\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter delay (in seconds): ");
                scanf("%d", &delay);
                printf("Enter task message: ");
                getchar(); // Consume newline from previous input
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = '\0'; // Remove newline character
                addTask(delay, message);
                break;
            case 2:
                scheduleTasks();
                break;
            case 3:
                printf("Exiting...\n");
                pthread_mutex_destroy(&taskMutex);
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}