//Gemma-7B DATASET v1.0 Category: CPU usage monitor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/resource.h>
#include <time.h>

#define MAX_PROCESSES 10

int main()
{
    // Define an array to store process IDs
    int pids[MAX_PROCESSES] = {0};

    // Allocate memory for the CPU usage data
    double cpu_usage[MAX_PROCESSES] = {0};

    // Get the current time
    time_t start_time = time(NULL);

    // Create and start MAX_PROCESSES processes
    for (int i = 0; i < MAX_PROCESSES; i++)
    {
        pids[i] = fork();

        if (pids[i] == 0)
        {
            // Child process: Sleep for a random amount of time
            sleep(rand() % 10);

            // Exit the child process
            exit(0);
        }
    }

    // Wait for all processes to complete
    for (int i = 0; i < MAX_PROCESSES; i++)
    {
        wait(NULL);
    }

    // Get the current time again
    time_t end_time = time(NULL);

    // Calculate the CPU usage for each process
    for (int i = 0; i < MAX_PROCESSES; i++)
    {
        cpu_usage[i] = (double)(end_time - start_time) * 100.0 / pids[i];
    }

    // Print the CPU usage for each process
    for (int i = 0; i < MAX_PROCESSES; i++)
    {
        printf("Process ID: %d, CPU Usage: %.2f%% \n", pids[i], cpu_usage[i]);
    }

    return 0;
}