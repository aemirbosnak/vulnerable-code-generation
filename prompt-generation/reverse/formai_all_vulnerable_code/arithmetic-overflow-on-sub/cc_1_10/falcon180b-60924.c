//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define MEGABYTE (1024 * 1024)

// Function to print the current RAM usage
void print_ram_usage() {
    FILE *fp;
    char filename[20] = "meminfo";
    char line[100];
    int total_ram = 0;
    int used_ram = 0;
    int free_ram = 0;

    // Open the meminfo file
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: Failed to open meminfo file.\n");
        exit(1);
    }

    // Read the first line to get the total RAM
    fgets(line, 100, fp);
    sscanf(line, "MemTotal: %d kB", &total_ram);

    // Read the next line to get the used RAM
    fgets(line, 100, fp);
    sscanf(line, "MemUsed: %d kB", &used_ram);

    // Calculate the free RAM
    free_ram = total_ram - used_ram;

    // Convert the values to megabytes
    total_ram /= MEGABYTE;
    used_ram /= MEGABYTE;
    free_ram /= MEGABYTE;

    // Print the RAM usage
    printf("Total RAM: %.2f MB\n", total_ram);
    printf("Used RAM: %.2f MB\n", used_ram);
    printf("Free RAM: %.2f MB\n", free_ram);

    fclose(fp);
}

// Function to monitor the RAM usage every second
void monitor_ram_usage() {
    while (1) {
        print_ram_usage();
        sleep(1);
    }
}

int main() {
    monitor_ram_usage();
    return 0;
}