//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

#define MAX_TASKS 100
#define TASK_NAME_LENGTH 100

typedef struct {
    char name[TASK_NAME_LENGTH];
    int hour;
    int minute;
} Task;

Task taskList[MAX_TASKS];
int taskCount = 0;
pthread_mutex_t mutex;

void addTask(char* name, int hour, int minute) {
    pthread_mutex_lock(&mutex);

    if (taskCount < MAX_TASKS) {
        strncpy(taskList[taskCount].name, name, TASK_NAME_LENGTH);
        taskList[taskCount].hour = hour;
        taskList[taskCount].minute = minute;
        taskCount++;
        printf("Task '%s' scheduled at %02d:%02d\n", name, hour, minute);
    } else {
        printf("Task list is full. Unable to add task '%s'.\n", name);
    }

    pthread_mutex_unlock(&mutex);
}

void removeTask(char* name) {
    pthread_mutex_lock(&mutex);

    for (int i = 0; i < taskCount; i++) {
        if (strcmp(taskList[i].name, name) == 0) {
            printf("Task '%s' cancelled.\n", taskList[i].name);
            for (int j = i; j < taskCount - 1; j++) {
                taskList[j] = taskList[j + 1];
            }
            taskCount--;
            break;
        }
    }

    pthread_mutex_unlock(&mutex);
}

void executeTask(Task task) {
    printf("Executing Task: %s at %02d:%02d\n", task.name, task.hour, task.minute);
}

void* scheduler(void* arg) {
    while (1) {
        time_t rawtime;
        struct tm *timeinfo;
        time(&rawtime);
        timeinfo = localtime(&rawtime);

        pthread_mutex_lock(&mutex);
        
        for (int i = 0; i < taskCount; i++) {
            if (taskList[i].hour == timeinfo->tm_hour && taskList[i].minute == timeinfo->tm_min) {
                executeTask(taskList[i]);
                removeTask(taskList[i].name); // remove task after execution
                break; // to prevent multiple executions
            }
        }

        pthread_mutex_unlock(&mutex);
        sleep(60); // check every minute
    }
    return NULL;
}

int main() {
    char command[50], name[TASK_NAME_LENGTH];
    int hour, minute;

    pthread_t schedulerThread;
    pthread_mutex_init(&mutex, NULL);
    pthread_create(&schedulerThread, NULL, scheduler, NULL);

    while (1) {
        printf("Enter command (add/remove/exit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Enter task name: ");
            scanf("%s", name);
            printf("Enter hour (0-23): ");
            scanf("%d", &hour);
            printf("Enter minute (0-59): ");
            scanf("%d", &minute);

            if (hour < 0 || hour > 23 || minute < 0 || minute > 59) {
                printf("Invalid time entered!\n");
            } else {
                addTask(name, hour, minute);
            }
        } else if (strcmp(command, "remove") == 0) {
            printf("Enter task name to remove: ");
            scanf("%s", name);
            removeTask(name);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Unknown command. Please try again.\n");
        }
    }

    pthread_cancel(schedulerThread);
    pthread_join(schedulerThread, NULL);
    pthread_mutex_destroy(&mutex);

    printf("Exiting Task Scheduler. Goodbye!\n");
    return 0;
}