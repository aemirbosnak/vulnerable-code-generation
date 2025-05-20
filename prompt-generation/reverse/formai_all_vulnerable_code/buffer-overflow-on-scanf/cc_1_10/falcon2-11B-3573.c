//Falcon2-11B DATASET v1.0 Category: CPU usage monitor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

// Function to monitor CPU usage
void monitor_cpu_usage() {
    int pid, i, j;
    int status;
    int max_usage;
    pid_t parent_pid, child_pid;
    double cpu_usage;

    printf("Enter the maximum CPU usage percentage: ");
    scanf("%d", &max_usage);

    parent_pid = getpid();
    printf("Parent PID: %d\n", parent_pid);

    for (i = 0; i < max_usage; i++) {
        child_pid = fork();

        if (child_pid == 0) {
            // Child process
            printf("Child PID: %d\n", getpid());

            for (j = 0; j < 1000000; j++) {
                // Simulate CPU intensive activity
                // Here, you can replace this with your own CPU intensive activity
                for (int k = 0; k < 1000000; k++) {
                    int a = 1;
                    int b = 2;
                    int c = a + b;
                }
            }

            // Exit child process
            exit(0);
        } else if (child_pid > 0) {
            // Parent process
            printf("Parent PID: %d\n", getpid());

            // Wait for child process to complete
            waitpid(child_pid, &status, 0);

            // Calculate CPU usage
            cpu_usage = ((double) status) / (double) max_usage * 100;

            printf("CPU usage: %.2f%%\n", cpu_usage);
        }
    }

    printf("CPU usage monitoring complete\n");
}

int main() {
    monitor_cpu_usage();
    return 0;
}