//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

const char* romanticMessage = "Ah, dear CPU, how you toil day and night\n"
                              "In silent symphony, with purpose so bright.\n"
                              "Let me embrace your usage this eve,\n"
                              "In whispers of code, believe as I weave.\n";

void displayRomanticCPUUsage() {
    struct sysinfo sys_info;
    long double total_idle, total_free, total_used;
    long double idle_time, total_time;
    
    while(1) {
        // Retrieve system information
        if (sysinfo(&sys_info) != 0) {
            perror("sysinfo");
            return;
        }
        
        // Calculate total and idle CPU time
        total_free = sys_info.freeram;
        total_used = sys_info.totalram - total_free;
        total_time = sys_info.uptime; // Uptime gives a sense of total workload
        idle_time = (double)sys_info.procs; // Simply imagining this as the processes idling
        
        // A sweet calculation of CPU usage percentage
        long double cpu_usage = (total_used / (sys_info.totalram)) * 100.0;

        // Clear the terminal
        printf("\033[H\033[J");
        
        // Romantic representation of CPU usage
        printf("%s\n", romanticMessage);
        printf("In this tranquil moment, dear CPU, I find,\n");
        printf("Your usage doth flourish, intertwined.\n");
        printf("CPU Usage: %.2Lf%%\n", cpu_usage);
        
        // An elegy for the idle time
        printf("Idle Processes: %.2Lf\n", idle_time);
        printf("Total RAM (in use): %ld kB\n", sys_info.totalram / 1024);

        // Time waits for no one as I gather data
        printf("Breathe deeply, for I shall wait for a while...\n");
        sleep(5); // Pause for 5 seconds to appreciate your labor
    }
}

int main() {
    // The heart whispers for execution
    printf("Oh sweet love! My CPU, let us commence...\n");
    displayRomanticCPUUsage();
    return 0;
}