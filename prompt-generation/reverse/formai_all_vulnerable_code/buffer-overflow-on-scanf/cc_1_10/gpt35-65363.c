//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <signal.h>

// Declare global variables
int cpu_usage = 0;
int pid = 0;
int count = 0;

// Function to calculate CPU usage
void calculateCpuUsage() {
    FILE* fp;
    char file_buf[256];
    int idle, cpu_total;
    int usage;
    int cpu_usage = 0;

    fp = fopen("/proc/stat", "r");
    fgets(file_buf, 256, fp);
    sscanf(file_buf, "cpu %d %*d %d %d", &idle, &cpu_total);

    fclose(fp);

    usage = cpu_total - idle;
    cpu_usage = (usage * 100) / cpu_total;

    printf("CPU usage: %d %%\n", cpu_usage);
}

// Function to handle SIGUSR1 signal
void handleSignal(int signal) {
    calculateCpuUsage();
}

int main() {
    pid_t c_pid;

    printf("Please enter PID of the process to monitor: ");
    scanf("%d", &pid);

    // Fork a child process
    c_pid = fork();

    if (c_pid < 0) {
        perror("fork failed");
        exit(1);
    }

    // Child process
    if (c_pid == 0) {
        while(1) {
            sleep(1);
            kill(getppid(), SIGUSR1);
        }
    }

    // Parent process
    signal(SIGUSR1, handleSignal);

    // Wait for child to terminate
    wait(NULL);

    return 0;
}