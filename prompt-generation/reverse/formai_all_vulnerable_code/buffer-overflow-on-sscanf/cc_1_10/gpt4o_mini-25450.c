//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 256

void get_ram_usage(float *total_ram, float *used_ram);
void print_ram_usage(float total_ram, float used_ram);

int main() {
    float total_ram = 0.0, used_ram = 0.0;
    char choice;

    printf("Welcome to the RAM Usage Monitor!\n");
    
    while (1) {
        get_ram_usage(&total_ram, &used_ram);
        print_ram_usage(total_ram, used_ram);

        printf("\nDo you want to refresh the RAM usage? (y/n): ");
        scanf(" %c", &choice);
        
        if (choice == 'n' || choice == 'N') {
            break;
        }
        
        sleep(2);  // Sleep for 2 seconds to avoid spamming updates
    }

    printf("Thank you for using the RAM Usage Monitor. Goodbye!\n");
    return 0;
}

void get_ram_usage(float *total_ram, float *used_ram) {
    FILE *file;
    char buffer[BUFFER_SIZE];
    
    // Reading total and free RAM from /proc/meminfo
    file = fopen("/proc/meminfo", "r");
    if (file == NULL) {
        perror("Failed to open /proc/meminfo");
        exit(EXIT_FAILURE);
    }
    
    while (fgets(buffer, BUFFER_SIZE, file)) {
        if (sscanf(buffer, "MemTotal: %f kB", total_ram) == 1) {
            *total_ram /= 1024; // Convert to MB
        }
        if (sscanf(buffer, "MemAvailable: %f kB", used_ram) == 1) {
            *used_ram = *total_ram - (*used_ram / 1024); // Convert to MB
        }
    }
    
    fclose(file);
}

void print_ram_usage(float total_ram, float used_ram) {
    printf("Total RAM: %.2f MB\n", total_ram);
    printf("Used RAM: %.2f MB\n", used_ram);
    printf("Free RAM: %.2f MB\n", total_ram - used_ram);
    printf("Memory Usage: %.2f%%\n", (used_ram / total_ram) * 100);
}