//FormAI DATASET v1.0 Category: Task Scheduler ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct Task {
    int id;
    char description[50];
    time_t time;
    bool completed;
} Task;

Task task_list[MAX_TASKS];
int num_tasks = 0;

void add_task(char* description, time_t time) {
    if (num_tasks < MAX_TASKS) {
        Task new_task;
        new_task.id = num_tasks + 1;
        strcpy(new_task.description, description);
        new_task.time = time;
        new_task.completed = false;
        task_list[num_tasks] = new_task;
        num_tasks++;
        printf("Task added successfully!\n");
    } else {
        printf("Task limit reached. Please delete some tasks to add new ones.\n");
    }
}

void delete_task(int id) {
    for (int i=0; i<num_tasks; i++) {
        if (task_list[i].id == id) {
            for (int j=i; j<num_tasks-1; j++) {
                task_list[j] = task_list[j+1];
            }
            num_tasks--;
            printf("Task deleted successfully!\n");
            return;
        }
    }
    printf("Task with ID %d not found.\n", id);
}

void print_task_list() {
    printf("ID\tDESCRIPTION\t\tTIME\t\tCOMPLETED\n");
    for (int i=0; i<num_tasks; i++) {
        printf("%d\t%s\t\t", task_list[i].id, task_list[i].description);
        struct tm* time_info;
        time_info = localtime(&task_list[i].time);
        printf("%d/%d/%d %02d:%02d:%02d\t", time_info->tm_mday, time_info->tm_mon+1, time_info->tm_year+1900, time_info->tm_hour, time_info->tm_min, time_info->tm_sec);
        if (task_list[i].completed) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}

void mark_task_completed(int id) {
    for (int i=0; i<num_tasks; i++) {
        if (task_list[i].id == id) {
            task_list[i].completed = true;
            printf("Task marked as completed.\n");
            return;
        }
    }
    printf("Task with ID %d not found.\n", id);
}

void check_due_tasks() {
    time_t curr_time;
    curr_time = time(NULL);
    for (int i=0; i<num_tasks; i++) {
        if (task_list[i].time < curr_time) {
            printf("The following task is overdue:\n");
            printf("%d\t%s\t\t", task_list[i].id, task_list[i].description);
            struct tm* time_info;
            time_info = localtime(&task_list[i].time);
            printf("%d/%d/%d %02d:%02d:%02d\t", time_info->tm_mday, time_info->tm_mon+1, time_info->tm_year+1900, time_info->tm_hour, time_info->tm_min, time_info->tm_sec);
            if (task_list[i].completed) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }
    }
}

int main() {
    int choice;
    do {
        printf("\nTask Scheduler Menu:\n");
        printf("=====================\n");
        printf("1. Add Task\n");
        printf("2. Delete Task\n");
        printf("3. Print Task List\n");
        printf("4. Mark Task Completed\n");
        printf("5. Check due tasks\n");
        printf("6. Exit\n");
        printf("=====================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                char description[50];
                time_t time;
                printf("Enter task description: ");
                scanf(" %[^\n]s", description);
                printf("Enter task time (DD/MM/YYYY HH:MM:SS): ");
                struct tm input_time = {0};
                char time_str[20];
                scanf(" %[^\n]s", time_str);
                strptime(time_str, "%d/%m/%Y %H:%M:%S", &input_time);
                time = mktime(&input_time);
                add_task(description, time);
                break;
            }
            case 2: {
                int id;
                printf("Enter task ID to delete: ");
                scanf("%d", &id);
                delete_task(id);
                break;
            }
            case 3: {
                print_task_list();
                break;
            }
            case 4: {
                int id;
                printf("Enter task ID to mark as completed: ");
                scanf("%d", &id);
                mark_task_completed(id);
                break;
            }
            case 5: {
                check_due_tasks();
                break;
            }
            case 6: {
                printf("Exiting Task Scheduler. Goodbye!\n");
                exit(0);
            }
            default: {
                printf("Invalid choice. Please enter a valid choice.\n");
            }
        }
    } while (choice != 6);
    return 0;
}