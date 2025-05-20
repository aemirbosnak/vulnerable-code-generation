//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_TASK_NAME 100
#define MAX_TASKS 10

typedef struct Task {
    char name[MAX_TASK_NAME];
    time_t executionTime;
    struct Task* next;
} Task;

Task* head = NULL;

void addTask(char* name, struct tm* timeInfo) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->executionTime = mktime(timeInfo);
    newTask->next = NULL;

    if (head == NULL) {
        head = newTask;
    } else {
        Task* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newTask;
    }
    printf("Task '%s' scheduled for %s", name, asctime(timeInfo));
}

void viewTasks() {
    if (head == NULL) {
        printf("\nNo scheduled tasks.\n");
        return;
    }
    Task* current = head;
    printf("\nScheduled Tasks:\n");
    while (current != NULL) {
        printf("Task: '%s' at %s", current->name, ctime(&current->executionTime));
        current = current->next;
    }
}

void runTasks() {
    time_t currentTime = time(NULL);
    
    Task* current = head;
    Task* prev = NULL;

    while (current != NULL) {
        if (current->executionTime <= currentTime) {
            printf("\nRunning Task: '%s'\n", current->name);
            
            // Remove completed task from the list
            if (prev == NULL) {
                head = current->next;
                free(current);
                current = head;
            } else {
                prev->next = current->next;
                free(current);
                current = prev->next;
            }
        } else {
            prev = current;
            current = current->next;
        }
    }
}

int main() {
    int choice;
    char taskName[MAX_TASK_NAME];

    while (1) {
        printf("\nTask Scheduler Menu:\n");
        printf("1. Add Task\n");
        printf("2. View Scheduled Tasks\n");
        printf("3. Run Due Tasks\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                struct tm timeInfo;
                int year, month, day, hour, minute;
                printf("Enter task name: ");
                scanf(" %[^\n]s", taskName); // Read string with spaces

                printf("Enter a date (YYYY MM DD): ");
                scanf("%d %d %d", &year, &month, &day);
                printf("Enter time (HH MM): ");
                scanf("%d %d", &hour, &minute);

                // Set the time structure
                timeInfo.tm_year = year - 1900;
                timeInfo.tm_mon = month - 1;
                timeInfo.tm_mday = day;
                timeInfo.tm_hour = hour;
                timeInfo.tm_min = minute;
                timeInfo.tm_sec = 0;
                timeInfo.tm_isdst = -1; // Let mktime determine if DST is in effect

                addTask(taskName, &timeInfo);
                break;
            }
            case 2:
                viewTasks();
                break;
            case 3:
                runTasks();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }

        // Sleep for a brief moment to prevent rapid loops
        sleep(1);
    }
    
    return 0;
}