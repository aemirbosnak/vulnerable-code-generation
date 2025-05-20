//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_PROCESSES 100

typedef struct {
    pid_t pid;
    char name[16];
    int status;
} process;

void sigchld_handler(int signum) {
    while (waitpid(-1, NULL, WNOHANG) > 0) {
        printf("Child process terminated\n");
    }
}

int main() {
    int i, num_processes = 0;
    process processes[MAX_PROCESSES];

    signal(SIGCHLD, sigchld_handler);

    printf("Enter number of processes to monitor: ");
    scanf("%d", &num_processes);

    for (i = 0; i < num_processes; i++) {
        printf("Enter process id for process %d: ", i+1);
        scanf("%d", &processes[i].pid);
        printf("Enter process name for process %d: ", i+1);
        scanf("%s", processes[i].name);
        processes[i].status = 0;
    }

    while (1) {
        for (i = 0; i < num_processes; i++) {
            if (processes[i].status == 0) {
                if (kill(processes[i].pid, 0) == -1) {
                    printf("Process %s (pid %d) terminated\n", processes[i].name, processes[i].pid);
                    processes[i].status = 1;
                }
            }
        }
        sleep(1);
    }

    return 0;
}