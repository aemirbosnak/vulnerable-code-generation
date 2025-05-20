//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

#define MAX_TASKS 10
#define TASK_NAME_LEN 50
#define COMMAND_LEN 100

typedef struct {
    char name[TASK_NAME_LEN];
    char command[COMMAND_LEN];
    time_t executeTime;
} Task;

Task taskList[MAX_TASKS];
int taskCount = 0;
pthread_mutex_t taskMutex;

void* taskScheduler(void* arg) {
    while (1) {
        time_t currentTime = time(NULL);
        
        pthread_mutex_lock(&taskMutex);
        for (int i = 0; i < taskCount; i++) {
            if (difftime(taskList[i].executeTime, currentTime) <= 0) {
                printf("Executing task: %s\n", taskList[i].name);
                system(taskList[i].command); // Execute the shell command
                // Remove the task by shifting the remaining tasks
                for (int j = i; j < taskCount - 1; j++) {
                    taskList[j] = taskList[j + 1];
                }
                taskCount--;
                i--; // Check the current index again
            }
        }
        pthread_mutex_unlock(&taskMutex);
        sleep(1); // Sleep for a second to prevent busy waiting
    }
    return NULL;
}

void addTask(const char* name, const char* command, int delay) {
    pthread_mutex_lock(&taskMutex);
    if (taskCount < MAX_TASKS) {
        strncpy(taskList[taskCount].name, name, TASK_NAME_LEN);
        strncpy(taskList[taskCount].command, command, COMMAND_LEN);
        taskList[taskCount].executeTime = time(NULL) + delay;
        taskCount++;
        printf("Task \"%s\" added. It will execute in %d seconds.\n", name, delay);
    } else {
        printf("Task list is full! Cannot add more tasks.\n");
    }
    pthread_mutex_unlock(&taskMutex);
}

int main() {
    pthread_t schedulerThread;
    pthread_mutex_init(&taskMutex, NULL);
    
    // Start the task scheduler thread
    pthread_create(&schedulerThread, NULL, taskScheduler, NULL);

    // Cyberpunk interface
    printf("=== CYBER TASK SCHEDULER ===\n");
    printf("Enter your tasks below (type 'exit' to quit):\n");

    while (1) {
        char taskName[TASK_NAME_LEN];
        char command[COMMAND_LEN];
        int delay;

        printf("Task Name: ");
        fgets(taskName, TASK_NAME_LEN, stdin);
        taskName[strcspn(taskName, "\n")] = 0; // Remove newline char

        if (strcmp(taskName, "exit") == 0) {
            break;
        }

        printf("Command (shell command to execute): ");
        fgets(command, COMMAND_LEN, stdin);
        command[strcspn(command, "\n")] = 0; // Remove newline char

        printf("Delay (in seconds): ");
        scanf("%d", &delay);
        getchar(); // Clear the newline character left by scanf

        addTask(taskName, command, delay);
    }

    // Cleanup
    pthread_cancel(schedulerThread);
    pthread_join(schedulerThread, NULL);
    pthread_mutex_destroy(&taskMutex);

    printf("Exiting Cyber Task Scheduler. Stay sharp, Chummer!\n");
    return 0;
}