//Falcon-180B DATASET v1.0 Category: System administration ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_PID_LENGTH 16

typedef struct {
    char command[MAX_COMMAND_LENGTH];
    pid_t pid;
} process_t;

void *monitor_process(void *arg) {
    process_t *process = (process_t *) arg;

    while (1) {
        int status;
        waitpid(process->pid, &status, WUNTRACED);

        if (WIFEXITED(status)) {
            printf("Process %s (PID %d) has exited with status %d\n", process->command, process->pid, WEXITSTATUS(status));
            break;
        } else if (WIFSIGNALED(status)) {
            printf("Process %s (PID %d) has been terminated by signal %d\n", process->command, process->pid, WTERMSIG(status));
            break;
        }
    }

    return NULL;
}

int main() {
    pthread_t thread_id;
    process_t process;

    printf("Enter the command to execute: ");
    scanf("%s", process.command);

    if (pipe(process.command) == -1) {
        printf("Error creating pipe\n");
        exit(1);
    }

    process.pid = fork();

    if (process.pid == -1) {
        printf("Error forking process\n");
        exit(1);
    } else if (process.pid == 0) {
        // Child process
        close(process.command[0]);
        dup2(process.command[1], STDOUT_FILENO);
        close(process.command[1]);
        execlp("sh", "sh", "-c", process.command, NULL);
        exit(1);
    } else {
        // Parent process
        close(process.command[1]);
        read(process.command[0], &process, sizeof(process_t));
        close(process.command[0]);

        pthread_create(&thread_id, NULL, monitor_process, &process);

        while (1) {
            char c;
            read(process.command[0], &c, 1);
            write(STDOUT_FILENO, &c, 1);
        }
    }

    return 0;
}