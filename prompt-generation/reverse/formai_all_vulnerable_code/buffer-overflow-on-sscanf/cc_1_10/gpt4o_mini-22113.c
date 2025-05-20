//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define THRESHOLD 75 // RAM usage threshold as a percentage
#define SLEEP_INTERVAL 2 // Interval to sleep between checks in seconds

void check_memory_usage();
void alert_user(int used_percentage);
int get_memory_usage();

int main() {
    printf("***** Welcome to the Paranoid RAM Monitor *****\n");
    printf("Monitoring RAM usage... Don't let your guard down!\n");

    while (1) {
        check_memory_usage();
        sleep(SLEEP_INTERVAL);
    }

    return 0; // This should never be reached
}

// Function to check memory usage
void check_memory_usage() {
    int used_percentage = get_memory_usage();
    if (used_percentage > THRESHOLD) {
        alert_user(used_percentage);
    } else {
        printf("Current RAM usage: %d%% - All is calm. For now...\n", used_percentage);
    }
}

// Function to alert user of high memory usage
void alert_user(int used_percentage) {
    printf("ALERT! High RAM usage detected: %d%%\n", used_percentage);
    printf("Is something suspicious happening? Stay vigilant!\n");
    printf("Consider checking running processes or system state!\n");
}

// Function to get current memory usage using /proc/meminfo
int get_memory_usage() {
    FILE *file = fopen("/proc/meminfo", "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening /proc/meminfo\n");
        exit(EXIT_FAILURE); // This is a serious problem!
    }

    char line[256];
    long total_memory = 0;
    long free_memory = 0;

    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "MemTotal: %ld kB", &total_memory) == 1) {
            // Found total memory
        } else if (sscanf(line, "MemFree: %ld kB", &free_memory) == 1) {
            // Found free memory
        }
    }

    fclose(file);
    
    // Calculate used memory percentage
    long used_memory = total_memory - free_memory;
    int used_percentage = (int)((used_memory * 100) / total_memory);
    
    return used_percentage;
}