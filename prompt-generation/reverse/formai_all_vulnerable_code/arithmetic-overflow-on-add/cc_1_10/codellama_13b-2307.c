//Code Llama-13B DATASET v1.0 Category: CPU usage monitor ; Style: light-weight
/*
 * CPU usage monitor program
 *
 * Author: [Your Name]
 * Date:   [Today's Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/resource.h>

// Function to calculate CPU usage percentage
float get_cpu_usage(int pid)
{
    struct rusage usage;
    float total_time, seconds;

    getrusage(RUSAGE_SELF, &usage);
    total_time = usage.ru_utime.tv_sec + usage.ru_stime.tv_sec;
    seconds = (float)time(NULL);

    return (100 * total_time / seconds);
}

int main(int argc, char *argv[])
{
    int pid, i;
    float usage;

    // Get the process ID of the program
    pid = getpid();

    // Print the header
    printf("CPU Usage Monitor\n");
    printf("----------------\n");
    printf("PID\tCPU Usage (%)\n");

    // Print the initial CPU usage
    usage = get_cpu_usage(pid);
    printf("%d\t%.2f\n", pid, usage);

    // Sleep for 1 second and print the updated CPU usage
    sleep(1);
    usage = get_cpu_usage(pid);
    printf("%d\t%.2f\n", pid, usage);

    // Sleep for 2 seconds and print the updated CPU usage
    sleep(2);
    usage = get_cpu_usage(pid);
    printf("%d\t%.2f\n", pid, usage);

    return 0;
}