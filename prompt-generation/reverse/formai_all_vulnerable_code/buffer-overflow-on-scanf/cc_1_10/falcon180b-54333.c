//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_PROCESSES 100

typedef struct process {
    int pid;
    char name[16];
    int status;
} Process;

void print_processes(Process *processes, int count) {
    printf("PID\tName\tStatus\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%d\n", processes[i].pid, processes[i].name, processes[i].status);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int count = 0;

    while (1) {
        printf("Enter command (list/kill/exit): ");
        char command[20];
        scanf("%s", command);

        if (strcmp(command, "list") == 0) {
            print_processes(processes, count);
        } else if (strcmp(command, "kill") == 0) {
            printf("Enter PID to kill: ");
            int pid;
            scanf("%d", &pid);

            for (int i = 0; i < count; i++) {
                if (processes[i].pid == pid) {
                    kill(pid, SIGKILL);
                    processes[i].status = -1;
                }
            }
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}