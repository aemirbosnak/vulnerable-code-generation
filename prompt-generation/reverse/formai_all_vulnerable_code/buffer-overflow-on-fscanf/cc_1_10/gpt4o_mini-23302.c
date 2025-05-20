//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>

#define MAX_TASKS 10
#define TASK_NAME_LEN 50
#define CONFIG_FILE "scheduler.conf"

typedef struct {
    char name[TASK_NAME_LEN];
    int interval; // seconds
    int duration; // seconds
} Task;

Task taskList[MAX_TASKS];
int taskCount = 0;

// Function prototypes
void loadConfig();
void scheduleTasks();
void executeTask(Task task);
void signalHandler(int signum);

int main() {
    // Load configuration from file
    loadConfig();
    
    // Schedule tasks based on loaded configuration
    scheduleTasks();

    return 0;
}

void loadConfig() {
    FILE *file = fopen(CONFIG_FILE, "r");
    if (!file) {
        perror("Could not open config file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%49s %d %d", taskList[taskCount].name, 
                                     &taskList[taskCount].interval, 
                                     &taskList[taskCount].duration) == 3) {
        taskCount++;
        if (taskCount >= MAX_TASKS) {
            break;
        }
    }
    
    fclose(file);
}

void scheduleTasks() {
    signal(SIGINT, signalHandler); // Set signal handler for graceful exit
    while (1) {
        time_t currentTime = time(NULL);

        for (int i = 0; i < taskCount; i++) {
            printf("Scheduling task: %s\n", taskList[i].name);

            // Execute the scheduled task
            executeTask(taskList[i]);

            // Sleep for the interval period
            sleep(taskList[i].interval);
            printf("Waiting for %d seconds until next execution of %s...\n", 
                    taskList[i].interval, taskList[i].name);
        }
    }
}

void executeTask(Task task) {
    printf("Executing task: %s for %d seconds...\n", task.name, task.duration);
    sleep(task.duration);
    printf("Task %s completed.\n", task.name);
}

void signalHandler(int signum) {
    printf("Termination signal received. Exiting gracefully...\n");
    exit(EXIT_SUCCESS);
}