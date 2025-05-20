//FormAI DATASET v1.0 Category: Task Scheduler ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// struct for tasks
typedef struct task {
    char name[50];
    char desc[100];
    struct tm date_time;
} Task;

// function to add task
void add_task(Task *tasks, int *count) {
    printf("\nEnter task name: ");
    scanf("%s", tasks[*count].name);

    printf("Enter task description: ");
    scanf("%s", tasks[*count].desc);

    printf("Enter task date and time in YYYY MM DD HH MM format: ");
    scanf("%d %d %d %d %d", &tasks[*count].date_time.tm_year, &tasks[*count].date_time.tm_mon, &tasks[*count].date_time.tm_mday, &tasks[*count].date_time.tm_hour, &tasks[*count].date_time.tm_min);

    tasks[*count].date_time.tm_year -= 1900; // adjust year
    tasks[*count].date_time.tm_mon--; // adjust month

    (*count)++;
}

// function to print all tasks
void print_tasks(Task *tasks, int count) {
    printf("\nAll Tasks:\n");
    for (int i = 0; i < count; i++) {
        printf("Task %d:\n", i+1);
        printf("Name: %s\n", tasks[i].name);
        printf("Description: %s\n", tasks[i].desc);
        printf("Date and Time: %d/%d/%d %d:%d\n", tasks[i].date_time.tm_mday, tasks[i].date_time.tm_mon+1, tasks[i].date_time.tm_year+1900, tasks[i].date_time.tm_hour, tasks[i].date_time.tm_min);
    }
}

// function to check if task is due
int is_due(Task task) {
    time_t now = time(NULL);
    struct tm *current_time = localtime(&now);

    if ((task.date_time.tm_year < current_time->tm_year) ||
        (task.date_time.tm_year == current_time->tm_year && task.date_time.tm_mon < current_time->tm_mon) ||
        (task.date_time.tm_year == current_time->tm_year && task.date_time.tm_mon == current_time->tm_mon && task.date_time.tm_mday < current_time->tm_mday) ||
        (task.date_time.tm_year == current_time->tm_year && task.date_time.tm_mon == current_time->tm_mon && task.date_time.tm_mday == current_time->tm_mday && task.date_time.tm_hour < current_time->tm_hour) ||
        (task.date_time.tm_year == current_time->tm_year && task.date_time.tm_mon == current_time->tm_mon && task.date_time.tm_mday == current_time->tm_mday && task.date_time.tm_hour == current_time->tm_hour && task.date_time.tm_min <= current_time->tm_min)) {
        return 1;
    }

    return 0;
}

// function to print tasks that are due
void print_due_tasks(Task *tasks, int count) {
    printf("\nTasks Due:\n");
    int count_due = 0;
    for (int i = 0; i < count; i++) {
        if (is_due(tasks[i])) {
            count_due++;
            printf("Task %d:\n", count_due);
            printf("Name: %s\n", tasks[i].name);
            printf("Description: %s\n", tasks[i].desc);
            printf("Date and Time: %d/%d/%d %d:%d\n", tasks[i].date_time.tm_mday, tasks[i].date_time.tm_mon+1, tasks[i].date_time.tm_year+1900, tasks[i].date_time.tm_hour, tasks[i].date_time.tm_min);
        }
    }

    if (count_due == 0) {
        printf("No tasks due.\n");
    }
}

int main() {
    Task tasks[100];
    int count = 0;

    while (1) {
        int choice;
        printf("\nTASK SCHEDULER\n");
        printf("1. Add Task\n");
        printf("2. Print All Tasks\n");
        printf("3. Print Due Tasks\n");
        printf("4. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_task(tasks, &count);
                break;
            case 2:
                print_tasks(tasks, count);
                break;
            case 3:
                print_due_tasks(tasks, count);
                break;
            case 4:
                printf("Quitting Program.\n");
                exit(0);
            default:
                printf("Invalid Choice.\n");
        }
    }

    return 0;
}