//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_DESC_LEN 256

typedef struct {
    char description[MAX_DESC_LEN];
    time_t time_to_run;
} Task;

Task task_list[MAX_TASKS];
int task_count = 0;

// Function to add a task
void add_task(const char *description, int delay_seconds) {
    if (task_count < MAX_TASKS) {
        strncpy(task_list[task_count].description, description, MAX_DESC_LEN);
        task_list[task_count].time_to_run = time(NULL) + delay_seconds;
        task_count++;
        printf("A new task has been added to the schedule, my dear! \"%s\" will execute in %d seconds.\n", description, delay_seconds);
    } else {
        printf("Oh no! We cannot add more tasks; our love is too full.\n");
    }
}

// Function to check if tasks need to be executed
void check_tasks() {
    time_t current_time = time(NULL);
    for (int i = 0; i < task_count; i++) {
        if (task_list[i].time_to_run <= current_time) {
            printf("Oh, the moment has arrived! Running task: %s\n", task_list[i].description);
            // Simulate task execution
            sleep(1);
            printf("Task \"%s\" has completed. Our love grows stronger with each passing moment!\n", task_list[i].description);
            // Remove the task by shifting the rest
            for (int j = i; j < task_count - 1; j++) {
                task_list[j] = task_list[j + 1];
            }
            task_count--;
            i--; // Adjust index to check the new task in the current position
        }
    }
}

// Function to display the tasks
void display_tasks() {
    if (task_count == 0) {
        printf("Our schedule is empty, my love. How about we fill it with dreams together?\n");
    } else {
        printf("Here are our scheduled tasks, each a testament to our love:\n");
        for (int i = 0; i < task_count; i++) {
            printf("%d. %s - Scheduled for %s", i + 1, task_list[i].description, ctime(&task_list[i].time_to_run));
        }
    }
}

int main() {
    printf("Welcome, dear heart, to the Task Scheduler of Love!\n");

    int choice;
    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a new task\n");
        printf("2. Check for tasks\n");
        printf("3. Display current tasks\n");
        printf("4. Exit this lovely program\n");
        printf("Please enter your choice (1-4): ");
        scanf("%d", &choice);

        if (choice == 1) {
            char description[MAX_DESC_LEN];
            int delay;
            printf("Tell me, what task shall we add to our love schedule? ");
            getchar(); // Consume the newline
            fgets(description, MAX_DESC_LEN, stdin);
            description[strcspn(description, "\n")] = 0; // Remove newline
            
            printf("In how many seconds should I carry out this task, my love? ");
            scanf("%d", &delay);
            add_task(description, delay);
        } else if (choice == 2) {
            check_tasks();
        } else if (choice == 3) {
            display_tasks();
        }
    } while (choice != 4);

    printf("Thank you for spending time with me, my beloved! Until next time...\n");
    return 0;
}