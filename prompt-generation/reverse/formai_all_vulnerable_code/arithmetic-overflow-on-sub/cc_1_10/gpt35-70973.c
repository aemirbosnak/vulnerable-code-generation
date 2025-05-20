//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <math.h>

// Define some constants
#define MAX_FILENAME_LEN 256
#define MAX_CPU_USAGE_RECORDS 1000

// Define struct to hold CPU usage data
typedef struct {
    time_t timestamp;
    float usage;
} CpuUsageRecord;

// Define global variables
CpuUsageRecord cpu_usage_records[MAX_CPU_USAGE_RECORDS];
int num_cpu_usage_records = 0;

// Define function to read CPU usage
float read_cpu_usage() {
    // Open the /proc/stat file
    FILE* stat_file = fopen("/proc/stat", "r");
    // Read the first line of the file
    char line[256];
    fgets(line, sizeof(line), stat_file);
    // Close the file
    fclose(stat_file);

    // Extract CPU usage values from the line
    int user, nice, system, idle, iowait, irq, softirq;
    sscanf(line, "cpu %d %d %d %d %d %d %d", &user, &nice, &system, &idle, &iowait, &irq, &softirq);

    // Calculate total CPU time
    int total_cpu_time = user + nice + system + idle + iowait + irq + softirq;

    // Calculate idle CPU time
    int idle_cpu_time = idle + iowait;

    // Calculate CPU usage percentage
    float cpu_usage = 100.0 * (total_cpu_time - idle_cpu_time) / total_cpu_time;

    // Return the CPU usage percentage
    return cpu_usage;
}

// Define function to record CPU usage
void record_cpu_usage() {
    // Get the current time
    time_t now;
    time(&now);

    // Read the current CPU usage
    float cpu_usage = read_cpu_usage();

    // Create a new CPU usage record
    CpuUsageRecord record;
    record.timestamp = now;
    record.usage = cpu_usage;

    // Add the record to the global array
    cpu_usage_records[num_cpu_usage_records++] = record;
}

// Define function to print CPU usage chart
void print_cpu_usage_chart() {
    // Calculate the maximum CPU usage value
    float max_usage = 0.0;
    int i;
    for (i = 0; i < num_cpu_usage_records; i++) {
        if (cpu_usage_records[i].usage > max_usage) {
            max_usage = cpu_usage_records[i].usage;
        }
    }

    // Calculate the width of the chart
    int width = 80;

    // Print the chart header
    printf("  +");
    for (i = 0; i < width + 2; i++) {
        printf("-");
    }
    printf("+\n");

    // Print the chart content
    for (i = 0; i < num_cpu_usage_records; i++) {
        // Calculate the usage value scaled to the chart width
        int usage_scaled = round(cpu_usage_records[i].usage / max_usage * width);

        // Print the chart row
        printf("%2d|%*s| %5.1f %%\n",
               i + 1, usage_scaled, "",
               cpu_usage_records[i].usage);
    }

    // Print the chart footer
    printf("  +");
    for (i = 0; i < width + 2; i++) {
        printf("-");
    }
    printf("+\n");
}

int main() {
    // Record CPU usage every second for 10 seconds
    int i;
    for (i = 0; i < 10; i++) {
        record_cpu_usage();
        sleep(1);
    }

    // Print the CPU usage chart
    print_cpu_usage_chart();

    // Exit the program
    return 0;
}