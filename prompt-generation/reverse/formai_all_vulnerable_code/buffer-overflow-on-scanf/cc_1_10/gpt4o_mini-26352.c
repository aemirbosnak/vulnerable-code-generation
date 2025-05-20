//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

#define MAX_TASKS 10
#define TASK_NAME_LEN 50
#define SLEEP_TIME 2

typedef struct {
    char name[TASK_NAME_LEN];
    int interval; // Interval in seconds
    int active;   // Is the task active
} Task;

Task taskList[MAX_TASKS];
int taskCount = 0;
pthread_mutex_t taskMutex;

void *taskRunner(void *arg) {
    Task *task = (Task *)arg;
    while (task->active) {
        time_t now;
        time(&now);
        char *timeString = ctime(&now);
        timeString[strlen(timeString) - 1] = '\0'; // Remove new line character

        printf("[%s] Running Task: %s\n", timeString, task->name);
        sleep(task->interval);
    }
    return NULL;
}

void addTask() {
    if (taskCount >= MAX_TASKS) {
        printf("Task limit reached. Cannot add more tasks.\n");
        return;
    }

    Task newTask;
    printf("Enter task name: ");
    fgets(newTask.name, TASK_NAME_LEN, stdin);
    newTask.name[strcspn(newTask.name, "\n")] = '\0'; // Remove new line character

    printf("Enter task interval (in seconds): ");
    scanf("%d", &newTask.interval);
    getchar(); // Consume new line character

    newTask.active = 1; // Set task to active
    taskList[taskCount++] = newTask;

    pthread_t thread;
    pthread_create(&thread, NULL, taskRunner, &taskList[taskCount - 1]);
    pthread_detach(thread); // Detach thread for automatic cleanup
}

void listTasks() {
    if (taskCount == 0) {
        printf("No tasks available.\n");
        return;
    }

    printf("Scheduled Tasks:\n");
    for (int i = 0; i < taskCount; i++) {
        printf("Task %d: Name: %s, Interval: %d seconds, Active: %s\n", 
               i + 1, taskList[i].name, taskList[i].interval, 
               taskList[i].active ? "Yes" : "No");
    }
}

void stopTask() {
    int taskIndex;
    printf("Enter task number to stop: ");
    scanf("%d", &taskIndex);
    getchar(); // Consume new line character

    if (taskIndex < 1 || taskIndex > taskCount) {
        printf("Invalid task number.\n");
        return;
    }

    taskIndex--; // Convert to 0-based index
    taskList[taskIndex].active = 0; // Deactivate the task
    printf("Task '%s' stopped.\n", taskList[taskIndex].name);
}

void menu() {
    int choice;
    do {
        printf("\nTask Scheduler Menu:\n");
        printf("1. Add Task\n");
        printf("2. List Tasks\n");
        printf("3. Stop Task\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // Consume new line character

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                listTasks();
                break;
            case 3:
                stopTask();
                break;
            case 4:
                printf("Exiting task scheduler...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 4);
}

int main() {
    printf("Welcome to the Task Scheduler!\n");
    pthread_mutex_init(&taskMutex, NULL);

    menu();

    pthread_mutex_destroy(&taskMutex);
    return 0;
}