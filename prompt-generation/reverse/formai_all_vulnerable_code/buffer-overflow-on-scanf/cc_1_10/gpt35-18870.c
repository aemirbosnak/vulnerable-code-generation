//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: safe
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

#define MAX_PROCESSES 128

void printCPUInfo() {
    printf("\nCPU Usage:\n");
    system("top -bn1 | grep \"Cpu(s)\" | sed \"s/.*, *\\([0-9.]*\\)%* id.*/\\1/\" | awk '{print 100 - $1\"%\"}'");
}

int main() {
    pid_t pid;
    int status;
    int pcount = 0;
    pid_t processes[MAX_PROCESSES];

    printf("Enter the time interval in seconds for CPU usage monitoring:\n");
    int interval;
    scanf("%d", &interval);

    while (1) {
        pid = fork();
        if (pid == 0) {
            // Child process
            exit(0);
        } else if (pid < 0) {
            // Error
            printf("Failed to fork process.\n");
            exit(1);
        } else {
            // Parent process
            processes[pcount++] = pid;
            if (pcount >= MAX_PROCESSES) {
                // Kill all child processes if we have reached the max number of processes
                printf("Reached maximum number of processes. Stopping.\n");
                for (int i = 0; i < pcount; i++) {
                    kill(processes[i], SIGTERM);
                }
                exit(0);
            }

            // Wait for the child process to finish
            sleep(interval);
            waitpid(pid, &status, WNOHANG);

            // Print CPU usage information
            printCPUInfo();
        }
    }

    return 0;
}