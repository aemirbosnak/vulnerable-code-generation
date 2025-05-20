//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 10
#define TASK_NAME_LENGTH 50

typedef struct {
    char name[TASK_NAME_LENGTH];
    time_t scheduled_time;
} Task;

Task tasks[MAX_TASKS];
int task_count = 0;

void add_task(char *name, time_t time);
void remove_task(int index);
void display_tasks();
void execute_tasks();
time_t parse_time(char *time_string);

int main() {
    char command[20];
    char task_name[TASK_NAME_LENGTH];
    char time_string[20];

    while (1) {
        printf("Task Scheduler: [add/remove/display/execute/quit] > ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            if (task_count >= MAX_TASKS) {
                printf("Task limit reached. Cannot add any more tasks.\n");
                continue;
            }
            printf("Enter task name: ");
            scanf("%s", task_name);
            printf("Enter scheduled time (YYYY-MM-DD HH:MM:SS): ");
            scanf("%s", time_string);
            time_t scheduled_time = parse_time(time_string);
            add_task(task_name, scheduled_time);
        } else if (strcmp(command, "remove") == 0) {
            int index;
            printf("Enter task index to remove: ");
            scanf("%d", &index);
            remove_task(index);
        } else if (strcmp(command, "display") == 0) {
            display_tasks();
        } else if (strcmp(command, "execute") == 0) {
            execute_tasks();
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Unknown command: %s\n", command);
        }
    }

    return 0;
}

void add_task(char *name, time_t time) {
    strcpy(tasks[task_count].name, name);
    tasks[task_count].scheduled_time = time;
    task_count++;
    printf("Task '%s' added for scheduled time %s", name, ctime(&time));
}

void remove_task(int index) {
    if (index < 0 || index >= task_count) {
        printf("Invalid index. Task not removed.\n");
        return;
    }
    printf("Removing task '%s'\n", tasks[index].name);
    for (int i = index; i < task_count - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    task_count--;
}

void display_tasks() {
    if (task_count == 0) {
        printf("No tasks scheduled.\n");
        return;
    }
    for (int i = 0; i < task_count; i++) {
        printf("Task %d: %s at %s", i, tasks[i].name, ctime(&tasks[i].scheduled_time));
    }
}

void execute_tasks() {
    time_t now = time(NULL);
    for (int i = 0; i < task_count; i++) {
        if (tasks[i].scheduled_time <= now) {
            printf("Executing task: %s\n", tasks[i].name);
            remove_task(i);
            i--; // Decrement i due to task being removed
        }
    }
}

time_t parse_time(char *time_string) {
    struct tm tm;
    strptime(time_string, "%Y-%m-%d %H:%M:%S", &tm);
    return mktime(&tm);
}