//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_TASKS 10
#define MAX_TASK_NAME_LENGTH 50
#define MAX_TASK_COMMAND_LENGTH 100

typedef struct task_t {
    char name[MAX_TASK_NAME_LENGTH];
    char command[MAX_TASK_COMMAND_LENGTH];
} task_t;

task_t tasks[MAX_TASKS];
int num_tasks = 0;

void add_task(char *name, char *command) {
    if (num_tasks >= MAX_TASKS) {
        printf("Error: Maximum number of tasks reached.\n");
        return;
    }

    strncpy(tasks[num_tasks].name, name, MAX_TASK_NAME_LENGTH);
    strncpy(tasks[num_tasks].command, command, MAX_TASK_COMMAND_LENGTH);

    num_tasks++;
    printf("Task added: %s\n", name);
}

void remove_task(int index) {
    if (index >= num_tasks) {
        printf("Error: Invalid task index.\n");
        return;
    }

    num_tasks--;

    printf("Task removed: %s\n", tasks[index].name);
}

void run_tasks() {
    for (int i = 0; i < num_tasks; i++) {
        int pid = fork();

        if (pid == 0) {
            execlp(tasks[i].command, tasks[i].command, NULL);
            exit(1);
        } else if (pid < 0) {
            printf("Error: Failed to fork.\n");
        } else {
            int status;
            waitpid(pid, &status, 0);
        }
    }
}

int main() {
    char input[100];

    while (1) {
        printf("\nEnter command (add/remove/run/exit): ");
        scanf("%s", input);

        if (strcmp(input, "add") == 0) {
            char name[MAX_TASK_NAME_LENGTH];
            char command[MAX_TASK_COMMAND_LENGTH];

            printf("Enter task name: ");
            scanf("%s", name);

            printf("Enter task command: ");
            scanf("%s", command);

            add_task(name, command);
        } else if (strcmp(input, "remove") == 0) {
            int index;

            printf("Enter task index to remove: ");
            scanf("%d", &index);

            remove_task(index);
        } else if (strcmp(input, "run") == 0) {
            run_tasks();
        } else if (strcmp(input, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}