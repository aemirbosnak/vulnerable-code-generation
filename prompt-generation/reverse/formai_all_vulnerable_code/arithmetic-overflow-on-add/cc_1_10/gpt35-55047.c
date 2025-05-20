//FormAI DATASET v1.0 Category: Task Scheduler ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<time.h>

// Define the structure Task
typedef struct Task {
    char task_name[50];
    int priority;
    time_t exec_time;
} Task;

// Function to get current date & time
void getCurrentTime(char *current_time) {
    time_t raw_time;
    struct tm *time_info;
    char buffer[50];

    time(&raw_time);
    time_info = localtime(&raw_time);

    strftime(buffer, 50, "%Y-%m-%d %T", time_info);
    strcpy(current_time, buffer);
}

int main() {
    int choice, priority, sleep_time, task_count = 0;
    char task_name[50], current_time[50], exec_time[50];
    Task tasks[10];

    while(1) {
        // Display menu to the user
        printf("\n\n*****	C Task Scheduler	*****\n");
        printf("1. Add a task\n");
        printf("2. View all tasks\n");
        printf("3. Remove a task\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // Adding a task
                printf("\nEnter task name: ");
                scanf("%s", task_name);

                printf("Enter task priority (1-10): ");
                scanf("%d", &priority);

                printf("Enter time in seconds to execute the task: ");
                scanf("%d", &sleep_time);

                getCurrentTime(current_time);

                time_t now = time(NULL);
                time_t exec_time_t = now + sleep_time;

                strftime(exec_time, 50, "%Y-%m-%d %T", localtime(&exec_time_t));

                Task new_task;
                strcpy(new_task.task_name, task_name);
                new_task.priority = priority;
                new_task.exec_time = exec_time_t;

                tasks[task_count] = new_task;
                task_count++;

                printf("\nTask added successfully!\n");
                break;

            case 2: // Viewing all tasks
                printf("\nTasks:\n");

                printf("%-20s%-10s%s\n", "Task Name", "Priority", "Exec Time");
                printf("========================================================\n");

                for(int i=0; i<task_count; i++) {
                    strftime(exec_time, 50, "%Y-%m-%d %T", localtime(&tasks[i].exec_time));
                    printf("%-20s%-10d%s\n", tasks[i].task_name, tasks[i].priority, exec_time);
                }
                break;

            case 3: // Removing a task
                printf("\nEnter the task name to remove: ");
                scanf("%s", task_name);

                for(int i=0; i<task_count; i++) {
                    if(strcmp(tasks[i].task_name, task_name) == 0) {
                        for(int j=i; j<task_count-1; j++) {
                            tasks[j] = tasks[j+1];
                        }
                        task_count--;
                        printf("\nTask removed successfully!\n");
                        break;
                    }
                }
                break;

            case 4: // Exiting the program
                printf("\nExiting...\n");
                exit(0);

            default: // Handling invalid input
                printf("\nInvalid choice, please try again.\n");
                break;
        }
    }
    return 0;
}