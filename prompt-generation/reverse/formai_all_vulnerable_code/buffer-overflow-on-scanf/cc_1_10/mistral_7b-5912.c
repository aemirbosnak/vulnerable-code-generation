//MISTRAL-7B DATASET v1.0 Category: System process viewer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>

#define MAX_CMD_LEN 256
#define MAX_ARGS 128
#define MAX_PROCS 64

typedef struct {
    pid_t pid;
    char cmd[MAX_CMD_LEN];
    int status;
} proc_info;

proc_info procs[MAX_PROCS];
int num_procs = 0;

void print_procs() {
    int i;

    printf("\nCURRENT PROCESSES:\n");
    printf("--------------------\n");
    for (i = 0; i < num_procs; i++) {
        printf("%d. %s [%s]\n", i + 1, procs[i].cmd, (procs[i].status == 0) ? "Running" : (procs[i].status == 1) ? "Zombie" : "Terminated");
    }
}

void view_procs(char *args) {
    int i, j, status;
    pid_t pid;

    if (num_procs >= MAX_PROCS) {
        printf("\nMaximum number of processes reached!\n");
        return;
    }

    if ((pid = fork()) < 0) {
        perror("Error: Fork failed");
        return;
    } else if (pid == 0) { // child process
        close(STDOUT_FILENO);
        dup2(fileno(stdout), STDOUT_FILENO);

        execlp("/bin/ps", "ps", "-o", "pid,cmd,status", (char *) NULL);
        perror("Error: Exec failed");
        exit(EXIT_FAILURE);
    } else { // parent process
        waitpid(pid, &status, 0);
        strcpy(procs[num_procs].cmd, args);
        procs[num_procs].pid = pid;
        procs[num_procs].status = WEXITSTATUS(status);
        num_procs++;
    }
}

int main(int argc, char **argv) {
    char cmd[MAX_CMD_LEN];

    if (argc > 1) {
        strcpy(cmd, argv[1]);
        view_procs(cmd);
    }

    while (1) {
        print_procs();
        printf("\nEnter 'q' to quit, or enter a command to view: ");
        scanf("%s", cmd);

        if (strcmp(cmd, "q") == 0) {
            break;
        } else {
            view_procs(cmd);
        }
    }

    return EXIT_SUCCESS;
}