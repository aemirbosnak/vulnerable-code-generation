//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

typedef struct Task {
    char task_name[100];
    int delay; // Delay in seconds
    time_t execute_time;
    struct Task* next;
} Task;

Task* head = NULL;

void add_task(char* name, int delay) {
    Task* new_task = (Task*)malloc(sizeof(Task));
    strcpy(new_task->task_name, name);
    new_task->delay = delay;
    new_task->execute_time = time(NULL) + delay; // Calculate execute time
    new_task->next = NULL;

    if (head == NULL) {
        head = new_task; // First task in the list
    } else {
        Task* temp = head;
        while (temp->next != NULL) {
            temp = temp->next; // Traverse to the end of the list
        }
        temp->next = new_task; // Add new task to the end of the list
    }

    printf("Task '%s' added with a delay of %d seconds.\n", name, delay);
}

void execute_tasks() {
    time_t current_time;
    Task* temp = head;
    Task* prev = NULL;

    while (temp != NULL) {
        current_time = time(NULL);
        if (temp->execute_time <= current_time) {
            printf("Executing Task: %s\n", temp->task_name);
            if (prev == NULL) {
                head = temp->next; // Remove the head task
                free(temp);
                temp = head; // Move to next task
            } else {
                prev->next = temp->next; // Bypass the executed task
                free(temp);
                temp = prev->next; // Move to the next task
            }
        } else {
            prev = temp; // Move to next task if not executed
            temp = temp->next;
        }
    }
}

void display_tasks() {
    Task* temp = head;
    if (temp == NULL) {
        printf("No tasks scheduled.\n");
        return;
    }
    printf("Scheduled Tasks:\n");
    while (temp != NULL) {
        printf("Task: %s, Delay: %d seconds\n", temp->task_name, temp->delay);
        temp = temp->next;
    }
}

void free_tasks() {
    Task* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int choice;
    char name[100];
    int delay;

    while (1) {
        printf("\n*** Simple Task Scheduler ***\n");
        printf("1. Add Task\n");
        printf("2. Execute Tasks\n");
        printf("3. Display Scheduled Tasks\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                printf("Enter task name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; // Remove trailing newline
                printf("Enter delay (in seconds): ");
                scanf("%d", &delay);
                add_task(name, delay);
                break;
            case 2:
                execute_tasks();
                break;
            case 3:
                display_tasks();
                break;
            case 4:
                free_tasks();
                printf("Exiting the program. All tasks cleared.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
        sleep(1); // Sleep for 1 second for smoother interaction
    }

    return 0;
}