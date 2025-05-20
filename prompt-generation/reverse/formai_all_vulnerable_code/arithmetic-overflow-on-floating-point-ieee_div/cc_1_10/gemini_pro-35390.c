//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Function to get the CPU usage in percentage
float get_cpu_usage() {
    // Open the /proc/stat file
    FILE *fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("fopen");
        return -1;
    }

    // Read the first line of the file
    char line[1024];
    if (fgets(line, sizeof(line), fp) == NULL) {
        perror("fgets");
        fclose(fp);
        return -1;
    }

    // Close the file
    fclose(fp);

    // Parse the line and get the user, nice, system, idle, and iowait times
    unsigned long long user, nice, system, idle, iowait;
    sscanf(line, "cpu %llu %llu %llu %llu %llu", &user, &nice, &system, &idle, &iowait);

    // Calculate the total CPU time
    unsigned long long total = user + nice + system + idle + iowait;

    // Calculate the CPU usage in percentage
    float usage = (float)(user + nice + system) / (float)total * 100.0;

    return usage;
}

// Function to print the CPU usage
void print_cpu_usage() {
    // Get the CPU usage
    float usage = get_cpu_usage();
    if (usage < 0) {
        printf("Error getting CPU usage\n");
        return;
    }

    // Print the CPU usage
    printf("CPU usage: %.2f%%\n", usage);
}

// Main function
int main() {
    // Print the CPU usage every second
    while (1) {
        print_cpu_usage();
        sleep(1);
    }

    return 0;
}