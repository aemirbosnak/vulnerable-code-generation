//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

void get_ram_usage(int *total, int *free) {
    FILE *fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), fp)) {
        if (sscanf(line, "MemTotal: %d kB", total) == 1) {
            continue;
        }
        if (sscanf(line, "MemFree: %d kB", free) == 1) {
            break;
        }
    }
    fclose(fp);
}

void display_ram_usage(int total, int free, int *used, float *usage_percentage) {
    *used = total - free;
    *usage_percentage = ((float)(*used) / total) * 100;

    printf("Total RAM: %d kB\n", total);
    printf("Free RAM: %d kB\n", free);
    printf("Used RAM: %d kB\n", *used);
    printf("RAM Usage: %.2f%%\n", *usage_percentage);
}

void recursive_print_usage(int total, int free, int *used, float *usage_percentage, int depth) {
    if (depth == 0) {
        return;
    }

    display_ram_usage(total, free, used, usage_percentage);
    printf("Recursive depth: %d\n", depth);
    
    sleep(1); // Small delay to see changes in usage
    recursive_print_usage(total, free, used, usage_percentage, depth - 1);
}

int main() {
    int total_ram = 0, free_ram = 0, used_ram = 0;
    float usage_percentage = 0.0;

    get_ram_usage(&total_ram, &free_ram);
    
    int recursive_depth;
    printf("Enter the number of times to repeat the RAM usage check (depth): ");
    scanf("%d", &recursive_depth);

    if (recursive_depth < 1) {
        printf("Depth should be greater than 0.\n");
        return EXIT_FAILURE;
    }

    printf("\nStarting RAM usage monitor...\n");
    recursive_print_usage(total_ram, free_ram, &used_ram, &usage_percentage, recursive_depth);
    
    printf("Monitoring completed.\n");
    return EXIT_SUCCESS;
}