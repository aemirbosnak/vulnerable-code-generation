//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PROCESSES 10
#define MAX_COMMAND_LENGTH 1024

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s command [args...]\n", argv[0]);
        return 1;
    }

    char command[MAX_COMMAND_LENGTH];
    strcpy(command, argv[1]);

    int num_processes = 1;
    if (argc > 2) {
        num_processes = atoi(argv[2]);
        if (num_processes > MAX_PROCESSES) {
            fprintf(stderr, "Error: Maximum number of processes is %d\n", MAX_PROCESSES);
            return 1;
        }
    }

    pid_t *pids = malloc(num_processes * sizeof(pid_t));
    if (pids == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for process IDs\n");
        return 1;
    }

    for (int i = 0; i < num_processes; i++) {
        pid_t pid = fork();
        if (pid == -1) {
            fprintf(stderr, "Error: Failed to fork process\n");
            free(pids);
            return 1;
        } else if (pid > 0) {
            pids[i] = pid;
        } else {
            int fd = open("/dev/null", O_RDWR);
            if (fd == -1) {
                fprintf(stderr, "Error: Failed to open /dev/null\n");
                exit(1);
            }

            dup2(fd, STDIN_FILENO);
            dup2(fd, STDOUT_FILENO);
            dup2(fd, STDERR_FILENO);

            execlp("sh", "sh", "-c", command, NULL);
            fprintf(stderr, "Error: Failed to execute shell\n");
            exit(1);
        }
    }

    for (int i = 0; i < num_processes; i++) {
        int status = 0;
        waitpid(pids[i], &status, 0);
        if (WIFEXITED(status)) {
            if (WEXITSTATUS(status)!= 0) {
                fprintf(stderr, "Error: Process %d exited with non-zero status\n", pids[i]);
            }
        } else {
            fprintf(stderr, "Error: Process %d terminated abnormally\n", pids[i]);
        }
    }

    free(pids);
    return 0;
}