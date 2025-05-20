//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define NUM_SAMPLES 10 // Number of samples to average RAM usage over
#define DELAY_TIME 1 // Time to wait between taking samples in seconds

int main() {
    long long ram_usage = 0; // Keep a running total of RAM usage
    int sample_count = 0; // Keep track of how many samples have been taken

    printf("Monitoring RAM usage...\n");

    while(1) { // Loop indefinitely
        // Read the RAM usage from the /proc/meminfo file
        FILE *meminfo_file = fopen("/proc/meminfo", "r");
        char meminfo_line[256];
        long long free_ram = 0;
        long long total_ram = 0;
        long long buffers = 0;
        long long cached = 0;
        long long used_ram = 0;

        while(fgets(meminfo_line, sizeof(meminfo_line), meminfo_file)) {
            if (sscanf(meminfo_line, "MemTotal: %lld", &total_ram) == 1) {}
            else if (sscanf(meminfo_line, "MemFree: %lld", &free_ram) == 1) {}
            else if (sscanf(meminfo_line, "Buffers: %lld", &buffers) == 1) {}
            else if (sscanf(meminfo_line, "Cached: %lld", &cached) == 1) {}
        }

        used_ram = total_ram - (free_ram + buffers + cached);

        fclose(meminfo_file);

        ram_usage += used_ram; // Add the current RAM usage to the running total
        sample_count++; // Increment the sample count

        if(sample_count >= NUM_SAMPLES) { // If we've taken enough samples
            long long avg_ram_usage = ram_usage / NUM_SAMPLES; // Calculate the average RAM usage
            printf("Average RAM usage over last %d samples: %lld kB\n", NUM_SAMPLES, avg_ram_usage); // Print the result
            ram_usage = 0; // Reset the running total
            sample_count = 0; // Reset the sample count
        }

        sleep(DELAY_TIME); // Wait before taking the next sample
    }

    return 0;
}