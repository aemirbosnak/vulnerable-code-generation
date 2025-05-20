//FormAI DATASET v1.0 Category: System administration ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>

// Define the CPU usage threshold (in percentage)
#define CPU_THRESHOLD 90

// Define the interval for checking CPU usage (in seconds)
#define CHECK_INTERVAL 5

// Define the command to execute when CPU usage is high
#define COMMAND "/etc/init.d/apache2 restart"

// Define the maximum number of times to execute the command
#define MAX_COMMAND_EXECUTIONS 3

int command_executions = 0;

// Signal handler for stopping the program gracefully
void stop_handler(int signum) {
    printf("Stopping monitoring...\n");
    exit(0);
}

int main() {
    // Register the signal handler for stopping the program
    signal(SIGINT, stop_handler);

    // Define a struct to hold time values
    struct timeval tv;

    while (1) {
        // Sleep for the specified interval
        sleep(CHECK_INTERVAL);

        // Get resource usage information
        struct rusage usage;
        getrusage(RUSAGE_SELF, &usage);

        // Get CPU usage as a percentage
        float cpu_usage = (((float)usage.ru_utime.tv_sec + (float)usage.ru_stime.tv_sec) * 100.0 +
                           ((float)usage.ru_utime.tv_usec + (float)usage.ru_stime.tv_usec) / 1000000.0) /
                          ((float)CHECK_INTERVAL * sysconf(_SC_NPROCESSORS_ONLN));

        printf("CPU usage: %.2f%%\n", cpu_usage);

        // If CPU usage is above the threshold, execute the command
        if (cpu_usage > CPU_THRESHOLD) {
            printf("CPU usage is above %d%%! Executing command...\n", CPU_THRESHOLD);
            system(COMMAND);
            command_executions++;
            
            // If the maximum number of executions has been reached, stop the program
            if (command_executions >= MAX_COMMAND_EXECUTIONS) {
                printf("%d command executions reached. Stopping monitoring...\n", MAX_COMMAND_EXECUTIONS);
                exit(0);
            }
        }
    }

    return 0;
}