//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 1024

typedef struct {
    pid_t pid;
    char command[MAX_COMMAND_LENGTH];
} process_t;

int main() {
    int num_processes = 0;
    process_t processes[MAX_PROCESSES];

    while (num_processes < MAX_PROCESSES) {
        printf("Enter PID of process to monitor (or -1 to exit): ");
        int pid;
        if (scanf("%d", &pid)!= 1 || pid < 0) {
            printf("Invalid input.\n");
            continue;
        }

        if (pid == -1) {
            break;
        }

        process_t *p = &processes[num_processes];
        p->pid = pid;
        sprintf(p->command, "ps -p %d -o command=", pid);

        int fd = open("/dev/null", O_RDONLY);
        if (fd == -1) {
            perror("open");
            exit(1);
        }

        p->pid = fork();
        if (p->pid == -1) {
            perror("fork");
            exit(1);
        } else if (p->pid == 0) {
            dup2(fd, 0);
            close(fd);

            char *args[] = {"sh", "-c", p->command, NULL};
            execvp("sh", args);
            perror("execvp");
            exit(1);
        }

        close(fd);
        num_processes++;
    }

    for (int i = 0; i < num_processes; i++) {
        waitpid(processes[i].pid, NULL, 0);
    }

    return 0;
}