//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: curious
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

struct process {
    int pid;
    char name[64];
    int status;
};

void sigchld_handler(int signum) {
    while (waitpid(-1, NULL, WNOHANG) > 0) {
        printf("Child process terminated\n");
    }
}

int main() {
    int i, num_processes = 0;
    struct process processes[MAX_PROCESSES];
    char input[1024];

    signal(SIGCHLD, sigchld_handler);

    printf("Enter the number of processes to monitor (max %d): ", MAX_PROCESSES-1);
    scanf("%d", &num_processes);

    for (i = 0; i < num_processes; i++) {
        printf("Enter process %d name: ", i+1);
        scanf("%s", processes[i].name);
        processes[i].pid = fork();

        if (processes[i].pid == 0) {
            // Child process
            execlp(processes[i].name, processes[i].name, NULL);
            exit(1);
        } else if (processes[i].pid < 0) {
            // Fork failed
            printf("Fork failed\n");
            exit(1);
        }
    }

    while (1) {
        printf("\n");
        for (i = 0; i < num_processes; i++) {
            printf("%d. %s (PID %d)\n", i+1, processes[i].name, processes[i].pid);
        }
        printf("Q to quit\n");
        fgets(input, 1024, stdin);
        if (input[0] == 'q' || input[0] == 'Q') {
            break;
        }
    }

    for (i = 0; i < num_processes; i++) {
        if (processes[i].pid > 0) {
            kill(processes[i].pid, SIGTERM);
        }
    }

    return 0;
}