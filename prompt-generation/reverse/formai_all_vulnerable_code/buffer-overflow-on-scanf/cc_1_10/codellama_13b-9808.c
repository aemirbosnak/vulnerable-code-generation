//Code Llama-13B DATASET v1.0 Category: Task Scheduler ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 100

typedef struct {
    char name[100];
    int hour;
    int minute;
    int second;
    int repeat;
} Task;

void print_tasks(Task tasks[], int num_tasks) {
    for (int i = 0; i < num_tasks; i++) {
        printf("%d. %s\n", i + 1, tasks[i].name);
    }
}

int main() {
    Task tasks[MAX_TASKS];
    int num_tasks = 0;

    while (1) {
        char command[100];
        printf("Enter command: ");
        fgets(command, 100, stdin);

        if (strcmp(command, "add") == 0) {
            Task task;
            printf("Enter task name: ");
            fgets(task.name, 100, stdin);
            printf("Enter hour: ");
            scanf("%d", &task.hour);
            printf("Enter minute: ");
            scanf("%d", &task.minute);
            printf("Enter second: ");
            scanf("%d", &task.second);
            printf("Enter repeat (0 = no, 1 = yes): ");
            scanf("%d", &task.repeat);
            tasks[num_tasks] = task;
            num_tasks++;
        } else if (strcmp(command, "print") == 0) {
            print_tasks(tasks, num_tasks);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}