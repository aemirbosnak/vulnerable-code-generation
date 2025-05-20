//Code Llama-13B DATASET v1.0 Category: CPU usage monitor ; Style: interoperable
// C CPU usage monitor program
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <time.h>

// Function to calculate CPU usage
double calculate_cpu_usage(int pid, double previous_total_time, double previous_elapsed_time) {
    // Get current CPU usage
    double total_time, elapsed_time, total_time_difference, elapsed_time_difference;
    FILE* fp;
    char line[128];

    fp = fopen("/proc/stat", "r");
    fgets(line, sizeof(line), fp);
    fclose(fp);

    sscanf(line, "%*s %lf %lf", &total_time, &elapsed_time);

    total_time_difference = total_time - previous_total_time;
    elapsed_time_difference = elapsed_time - previous_elapsed_time;

    return (elapsed_time_difference / total_time_difference) * 100;
}

int main() {
    // Get current PID
    int pid = getpid();

    // Get initial CPU usage
    double previous_total_time, previous_elapsed_time;
    FILE* fp;
    char line[128];

    fp = fopen("/proc/stat", "r");
    fgets(line, sizeof(line), fp);
    fclose(fp);

    sscanf(line, "%*s %lf %lf", &previous_total_time, &previous_elapsed_time);

    // Loop and calculate CPU usage every second
    while (1) {
        double cpu_usage = calculate_cpu_usage(pid, previous_total_time, previous_elapsed_time);
        printf("CPU usage: %lf%%\n", cpu_usage);
        sleep(1);
    }

    return 0;
}