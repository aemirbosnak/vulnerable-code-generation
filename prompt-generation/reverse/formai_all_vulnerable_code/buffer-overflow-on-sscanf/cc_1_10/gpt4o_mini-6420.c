//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PROCESSES 1024
#define BUFFER_SIZE 256

void get_memory_usage(int pid, size_t *memory_usage) {
    char path[BUFFER_SIZE];
    FILE *file;
    sprintf(path, "/proc/%d/statm", pid);
    
    file = fopen(path, "r");
    if (file) {
        unsigned long size, resident, share, text, lib, data, dt;
        fscanf(file, "%lu %lu %lu %lu %lu %lu %lu", &size, &resident, &share, &text, &lib, &data, &dt);
        fclose(file);
        *memory_usage = resident * sysconf(_SC_PAGESIZE) / 1024; // convert to KB
    } else {
        *memory_usage = 0; // Couldn't read memory usage
    }
}

void print_memory_usage_summary() {
    char buffer[BUFFER_SIZE];
    FILE *file = popen("ps -eo pid,comm", "r");

    if (file == NULL) {
        perror("popen");
        return;
    }

    printf("%-10s %-20s %s\n", "PID", "COMMAND", "MEMORY (KB)");
    while (fgets(buffer, sizeof(buffer), file)) {
        if (buffer[0] == '\n') continue; // Skip empty lines
        
        int pid;
        char command[BUFFER_SIZE];
        sscanf(buffer, "%d %s", &pid, command);

        size_t memory_usage;
        get_memory_usage(pid, &memory_usage);
        
        printf("%-10d %-20s %lu KB\n", pid, command, memory_usage);
    }

    pclose(file);
}

void monitor_memory_usage(int interval) {
    while (1) {
        printf("\nMemory Usage Summary:\n");
        print_memory_usage_summary();
        sleep(interval); // Wait for the specified interval
    }
}

int main(int argc, char *argv[]) {
    int interval = 5; // default interval in seconds

    if (argc > 1) {
        interval = atoi(argv[1]);
        if (interval < 1) {
            printf("Invalid interval. Using default of 5 seconds.\n");
            interval = 5;
        }
    }
    
    printf("Memory Usage Monitor: Checking every %d seconds.\n", interval);
    monitor_memory_usage(interval);

    return 0;
}