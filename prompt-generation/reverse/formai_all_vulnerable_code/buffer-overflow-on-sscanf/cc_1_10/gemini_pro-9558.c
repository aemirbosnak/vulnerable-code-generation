//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

// Collect CPU usage data
int get_cpu_usage() {
    FILE *stat_file = fopen("/proc/stat", "r");
    if (!stat_file) {
        perror("Failed to open /proc/stat");
        return -1;
    }

    char line[256];
    while (fgets(line, sizeof(line), stat_file)) {
        if (strncmp(line, "cpu", 3) == 0) {
            // Parse CPU usage data
            unsigned long long user, nice, system, idle;
            sscanf(line, "cpu %llu %llu %llu %llu", &user, &nice, &system, &idle);

            // Calculate CPU usage percentage
            double cpu_usage = (100.0 * (user + nice + system)) / (user + nice + system + idle);

            fclose(stat_file);
            return (int)cpu_usage;
        }
    }

    fclose(stat_file);
    return -1;
}

// Print CPU usage data in a scientific format
void print_cpu_usage(int cpu_usage) {
    if (cpu_usage < 0) {
        printf("Failed to get CPU usage\n");
        return;
    }

    // Convert CPU usage to scientific notation
    double cpu_usage_scientific = cpu_usage / 100.0;
    int exponent = 0;
    while (cpu_usage_scientific < 1.0) {
        cpu_usage_scientific *= 10.0;
        exponent -= 1;
    }
    while (cpu_usage_scientific >= 10.0) {
        cpu_usage_scientific /= 10.0;
        exponent += 1;
    }

    // Print CPU usage in scientific format
    printf("CPU usage: %.2fe%d%%\n", cpu_usage_scientific, exponent);
}

int main() {
    // Continuously monitor and print CPU usage
    while (true) {
        int cpu_usage = get_cpu_usage();
        print_cpu_usage(cpu_usage);

        // Sleep for 1 second
        sleep(1);
    }

    return 0;
}