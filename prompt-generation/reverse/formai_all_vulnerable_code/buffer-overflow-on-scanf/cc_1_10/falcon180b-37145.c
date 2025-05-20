//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_TASKS 10
#define MAX_COMMAND_LENGTH 80

typedef struct {
    char command[MAX_COMMAND_LENGTH];
    int pid;
} task_t;

void add_task(task_t tasks[], int num_tasks, char* command) {
    if (num_tasks >= MAX_TASKS) {
        printf("Error: Maximum number of tasks reached.\n");
        return;
    }

    strncpy(tasks[num_tasks].command, command, MAX_COMMAND_LENGTH);
    tasks[num_tasks].pid = 0;
    num_tasks++;
}

void run_tasks(task_t tasks[], int num_tasks) {
    for (int i = 0; i < num_tasks; i++) {
        if (tasks[i].pid == 0) {
            printf("Running task %s...\n", tasks[i].command);
            tasks[i].pid = fork();

            if (tasks[i].pid == 0) {
                execlp(tasks[i].command, tasks[i].command, NULL);
                exit(1);
            } else if (tasks[i].pid < 0) {
                printf("Error: Failed to fork task %s.\n", tasks[i].command);
            }
        } else {
            int status;
            waitpid(tasks[i].pid, &status, WNOHANG);

            if (WIFEXITED(status)) {
                printf("Task %s completed with exit code %d.\n", tasks[i].command, WEXITSTATUS(status));
                tasks[i].pid = 0;
            }
        }
    }
}

void remove_task(task_t tasks[], int num_tasks, int task_index) {
    if (task_index >= num_tasks || task_index < 0) {
        printf("Error: Invalid task index.\n");
        return;
    }

    tasks[task_index].pid = 0;
    num_tasks--;
}

int main() {
    task_t tasks[MAX_TASKS];
    int num_tasks = 0;

    while (1) {
        printf("Enter command to add task or type 'list' to view tasks or 'exit' to quit: ");
        char input[MAX_COMMAND_LENGTH];
        scanf("%s", input);

        if (strcmp(input, "list") == 0) {
            printf("Tasks:\n");
            for (int i = 0; i < num_tasks; i++) {
                printf("%d: %s\n", i, tasks[i].command);
            }
        } else if (strcmp(input, "exit") == 0) {
            break;
        } else {
            add_task(tasks, num_tasks, input);
        }
    }

    run_tasks(tasks, num_tasks);

    return 0;
}