//MISTRAL-7B DATASET v1.0 Category: Task Scheduler ; Style: Dennis Ritchie
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_TASKS 10
#define MAX_CMD_LEN 100

typedef struct {
    char cmd[MAX_CMD_LEN];
    int pid;
    int status;
    int next;
} task_t;

task_t tasks[MAX_TASKS];
int head = 0;
int tail = 0;

void print_tasks() {
    printf("Tasks:\n");
    for (int i = head; i != tail; i = (i + 1) % MAX_TASKS) {
        printf("Cmd: %s, PID: %d, Status: %d\n", tasks[i].cmd, tasks[i].pid, tasks[i].status);
    }
}

void add_task(char *cmd) {
    if ((tail + 1) % MAX_TASKS == head) {
        fprintf(stderr, "Task queue is full\n");
        return;
    }

    strcpy(tasks[tail].cmd, cmd);
    tasks[tail].pid = -1;
    tasks[tail].status = 0;
    tail = (tail + 1) % MAX_TASKS;
}

int run_task(int i) {
    int status;

    pid_t pid = fork();
    if (pid == -1) {
        fprintf(stderr, "Fork failed\n");
        return -1;
    }

    if (pid == 0) {
        execlp(strtok(tasks[i].cmd, " "), strtok(tasks[i].cmd, " "), NULL);
        perror("Execlp failed");
        exit(1);
    }

    tasks[i].pid = pid;

    waitpid(pid, &status, 0);
    tasks[i].status = WEXITSTATUS(status);

    return status;
}

int main() {
    char cmd[MAX_CMD_LEN];

    while (1) {
        printf("Enter command (empty line to exit): ");
        fgets(cmd, MAX_CMD_LEN, stdin);
        cmd[strlen(cmd) - 1] = '\0';

        if (strcmp(cmd, "") == 0) {
            break;
        }

        add_task(cmd);

        if (head == tail) {
            printf("Queue is full, skipping command: %s\n", cmd);
            continue;
        }

        int i = head;
        head = (head + 1) % MAX_TASKS;

        int status = run_task(i);
        if (status < 0) {
            printf("Error running task: %s\n", tasks[i].cmd);
            continue;
        }

        printf("Task: %s, completed with status: %d\n", tasks[i].cmd, status);
    }

    print_tasks();

    return 0;
}