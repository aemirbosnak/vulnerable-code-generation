//FormAI DATASET v1.0 Category: Task Scheduler ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char task_name[20];
    int priority;
    int time_required;
    time_t due_date;
} Task;

typedef struct {
    int hour;
    int minute;
} Time;

void add_task(Task tasks[], int index);
void edit_task(Task tasks[], int index);
void delete_task(Task tasks[], int index);
void display_task(Task tasks[], int index);
void display_all_tasks(Task tasks[], int n);
void sort_tasks_by_priority(Task tasks[], int n);
void sort_tasks_by_due_date(Task tasks[], int n);
void execute_task(Task tasks[], int n);

int main() {
    int menu_choice;
    int n = 0;
    Task tasks[10];
    do {
        printf("Task Scheduler\n");
        printf("1. Add Task\n");
        printf("2. Edit Task\n");
        printf("3. Delete Task\n");
        printf("4. Display Task\n");
        printf("5. Display All Tasks\n");
        printf("6. Sort Tasks by Priority\n");
        printf("7. Sort Tasks by Due Date\n");
        printf("8. Execute Task\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &menu_choice);

        switch (menu_choice) {
            case 1:
                add_task(tasks, n);
                n++;
                break;
            case 2:
                if (n == 0) {
                    printf("No tasks to edit\n");
                    break;
                }
                int edit_index;
                printf("Enter task index to edit: ");
                scanf("%d", &edit_index);
                if (edit_index < 0 || edit_index >= n) {
                    printf("Invalid index\n");
                    break;
                }
                edit_task(tasks, edit_index);
                break;
            case 3:
                if (n == 0) {
                    printf("No tasks to delete\n");
                    break;
                }
                int delete_index;
                printf("Enter task index to delete: ");
                scanf("%d", &delete_index);
                if (delete_index < 0 || delete_index >= n) {
                    printf("Invalid index\n");
                    break;
                }
                delete_task(tasks, delete_index);
                n--;
                break;
            case 4:
                if (n == 0) {
                    printf("No tasks to display\n");
                    break;
                }
                int display_index;
                printf("Enter task index to display:");
                scanf("%d", &display_index);
                if (display_index < 0 || display_index >= n) {
                    printf("Invalid index\n");
                    break;
                }
                display_task(tasks, display_index);
                break;
            case 5:
                if (n == 0) {
                    printf("No tasks to display\n");
                    break;
                }
                display_all_tasks(tasks, n);
                break;
            case 6:
                if (n == 0) {
                    printf("No tasks to sort\n");
                    break;
                }
                sort_tasks_by_priority(tasks, n);
                break;
            case 7:
                if (n == 0) {
                    printf("No tasks to sort\n");
                    break;
                }
                sort_tasks_by_due_date(tasks, n);
                break;
            case 8:
                if (n == 0) {
                    printf("No tasks to execute\n");
                    break;
                }
                execute_task(tasks, n);
                break;
            case 0:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (menu_choice != 0);

    return 0;
}

void add_task(Task tasks[], int index) {
    printf("Enter task name: ");
    scanf("%s", tasks[index].task_name);
    printf("Enter task priority (1-5): ");
    scanf("%d", &tasks[index].priority);
    if (tasks[index].priority < 1 || tasks[index].priority > 5) {
        printf("Invalid priority\n");
        return;
    }
    printf("Enter time required to complete task (in minutes): ");
    scanf("%d", &tasks[index].time_required);
    printf("Enter due date (YYYY-MM-DD): ");
    struct tm date_struct = {0};
    scanf("%d-%d-%d", &date_struct.tm_year, &date_struct.tm_mon, &date_struct.tm_mday);
    date_struct.tm_year -= 1900;
    date_struct.tm_mon--;
    tasks[index].due_date = mktime(&date_struct);
}

void edit_task(Task tasks[], int index) {
    printf("Enter new task name (or press enter to keep the same): ");
    char new_task_name[20];
    scanf("%s", new_task_name);
    if (strlen(new_task_name) > 0) {
        strcpy(tasks[index].task_name, new_task_name);
    }
    printf("Enter new task priority (or press enter to keep the same): ");
    char new_priority_string[10];
    scanf("%s", new_priority_string);
    if (strlen(new_priority_string) > 0) {
        int new_priority = atoi(new_priority_string);
        if (new_priority < 1 || new_priority > 5) {
            printf("Invalid priority\n");
            return;
        }
        tasks[index].priority = new_priority;
    }
    printf("Enter new time required (or press enter to keep the same): ");
    char new_time_string[10];
    scanf("%s", new_time_string);
    if (strlen(new_time_string) > 0) {
        int new_time = atoi(new_time_string);
        tasks[index].time_required = new_time;
    }
    printf("Enter new due date (YYYY-MM-DD) (or press enter to keep the same): ");
    char new_date_string[11];
    scanf("%s", new_date_string);
    if (strlen(new_date_string) > 0) {
        struct tm date_struct = {0};
        sscanf(new_date_string, "%d-%d-%d", &date_struct.tm_year, &date_struct.tm_mon, &date_struct.tm_mday);
        date_struct.tm_year -= 1900;
        date_struct.tm_mon--;
        tasks[index].due_date = mktime(&date_struct);
    }
    printf("Task edited\n");
}

void delete_task(Task tasks[], int index) {
    for (int i = index; i < 9; i++) {
        strcpy(tasks[i].task_name, tasks[i+1].task_name);
        tasks[i].priority = tasks[i+1].priority;
        tasks[i].time_required = tasks[i+1].time_required;
        tasks[i].due_date = tasks[i+1].due_date;
    }
    printf("Task deleted\n");
}

void display_task(Task tasks[], int index) {
    printf("Task Name: %s\n", tasks[index].task_name);
    printf("Task Priority: %d\n", tasks[index].priority);
    printf("Time Required: %d minutes\n", tasks[index].time_required);
    struct tm* due_date = localtime(&tasks[index].due_date);
    printf("Due Date: %d-%02d-%02d\n", due_date->tm_year+1900, due_date->tm_mon+1, due_date->tm_mday);
}

void display_all_tasks(Task tasks[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Task %d:\n", i);
        display_task(tasks, i);
        printf("\n");
    }
}

void sort_tasks_by_priority(Task tasks[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (tasks[j].priority > tasks[i].priority) {
                Task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }
    printf("Tasks sorted by priority\n");
}

void sort_tasks_by_due_date(Task tasks[], int n) {
    for (int i = 0 ; i < n - 1; i++) {
        for (int j = 0 ; j < n - i - 1; j++) {
            if (tasks[j].due_date > tasks[j+1].due_date) {
                Task temp = tasks[j];
                tasks[j] = tasks[j+1];
                tasks[j+1] = temp;
            }
        }
    }
    printf("Tasks sorted by due date\n");
}

void execute_task(Task tasks[], int n) {
    time_t current_time = time(NULL);
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (current_time > tasks[i].due_date) {
            printf("Task \"%s\" is overdue. Do you want to execute it now (y/n)? ", tasks[i].task_name);
            char choice;
            scanf(" %c", &choice);
            if (choice == 'y') {
                index = i;
                break;
            }
        }
    }
    if (index == -1) {
        printf("No overdue tasks to execute\n");
        return;
    }
    printf("Executing task \"%s\"...\n", tasks[index].task_name);
    printf("Task completed!\n");
    delete_task(tasks, index);
    n--;
}