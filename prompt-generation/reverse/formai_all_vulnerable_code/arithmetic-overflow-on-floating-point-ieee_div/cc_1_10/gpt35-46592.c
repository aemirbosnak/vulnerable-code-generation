//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

// Global variables
int g_running = 1;
unsigned long long g_prev_totalram = 0;
unsigned long long g_prev_freeram = 0;

// Signal handler to gracefully exit on Ctrl+C
void sigint_handler(int sig)
{
    g_running = 0;
}

int main()
{
    // Install the signal handler
    signal(SIGINT, sigint_handler);

    while(g_running)
    {
        struct sysinfo si;
        if(sysinfo(&si) != 0)
        {
            printf("Error: failed to get system information\n");
            return 1;
        }

        // Calculate the total RAM usage and print it
        unsigned long long totalram = si.totalram * si.mem_unit;
        unsigned long long usedram = totalram - (si.freeram * si.mem_unit);
        printf("Total RAM Usage: %llu bytes (%llu MiB)\n", usedram, usedram / (1024 * 1024));

        // Calculate the RAM usage percentage and print it
        if(g_prev_totalram != 0)
        {
            double ram_usage = (double)(usedram - g_prev_freeram) / (double)(totalram - g_prev_totalram) * 100.0;
            printf("RAM Usage Percentage: %.2f%%\n", ram_usage);
        }

        // Save the current values for the next iteration
        g_prev_totalram = totalram;
        g_prev_freeram = si.freeram * si.mem_unit;

        // Wait for 1 second before checking again
        sleep(1);
    }

    return 0;
}