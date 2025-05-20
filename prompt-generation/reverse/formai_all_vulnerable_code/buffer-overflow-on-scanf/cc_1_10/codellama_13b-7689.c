//Code Llama-13B DATASET v1.0 Category: System process viewer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_PROCESSES 100
#define MAX_LENGTH 256

typedef struct {
    char name[MAX_LENGTH];
    int pid;
    int ppid;
} process_info;

void print_processes(process_info* processes, int num_processes) {
    printf("PID\tPPID\tNAME\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%d\t%s\n", processes[i].pid, processes[i].ppid, processes[i].name);
    }
}

int main(int argc, char* argv[]) {
    process_info processes[MAX_PROCESSES];
    int num_processes = 0;
    int status;

    while (1) {
        int pid = fork();
        if (pid == 0) {
            // Child process
            char cmd[MAX_LENGTH];
            printf("Enter command: ");
            scanf("%s", cmd);
            execlp(cmd, cmd, NULL);
            exit(0);
        } else if (pid > 0) {
            // Parent process
            waitpid(pid, &status, 0);
            if (WIFEXITED(status)) {
                int exit_status = WEXITSTATUS(status);
                if (exit_status == 0) {
                    // Successful exit
                    num_processes++;
                    processes[num_processes - 1].pid = pid;
                    processes[num_processes - 1].ppid = getppid();
                    strcpy(processes[num_processes - 1].name, argv[0]);
                } else {
                    // Unsuccessful exit
                    num_processes++;
                    processes[num_processes - 1].pid = pid;
                    processes[num_processes - 1].ppid = getppid();
                    strcpy(processes[num_processes - 1].name, "UNKNOWN");
                }
            }
            print_processes(processes, num_processes);
        } else {
            // Error
            printf("Error forking process\n");
        }
    }

    return 0;
}