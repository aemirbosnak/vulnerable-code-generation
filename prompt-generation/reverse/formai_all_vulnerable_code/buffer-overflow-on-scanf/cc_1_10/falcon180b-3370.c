//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function prototypes
void get_ram_info(unsigned long *total, unsigned long *free, unsigned long *used);

int main() {
    unsigned long total, free, used;
    char choice;
    bool quit = false;

    // Initialize variables
    get_ram_info(&total, &free, &used);

    // Display initial RAM usage
    printf("\nRAM Usage Monitor\n\n");
    printf("Total RAM: %lu bytes\n", total);
    printf("Free RAM: %lu bytes\n", free);
    printf("Used RAM: %lu bytes\n\n", used);

    do {
        // Display menu options
        printf("1. Refresh RAM usage\n");
        printf("2. Quit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        // Process user choice
        switch (choice) {
        case '1':
            get_ram_info(&total, &free, &used);
            printf("\nRAM usage refreshed.\n");
            break;
        case '2':
            quit = true;
            break;
        default:
            printf("Invalid choice.\n");
        }

    } while (!quit);

    return 0;
}

// Function to get RAM info
void get_ram_info(unsigned long *total, unsigned long *free, unsigned long *used) {
    FILE *fp;
    char line[1024];
    unsigned long value;

    // Open /proc/meminfo file
    fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        printf("Error: Could not open /proc/meminfo.\n");
        exit(1);
    }

    // Read total RAM
    *total = 0;
    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (sscanf(line, "MemTotal: %lu kB", &value) == 1) {
            *total = value * 1024;
            break;
        }
    }

    // Read free RAM
    *free = 0;
    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (sscanf(line, "MemFree: %lu kB", &value) == 1) {
            *free = value * 1024;
            break;
        }
    }

    // Read used RAM
    *used = *total - *free;

    // Close file
    fclose(fp);
}