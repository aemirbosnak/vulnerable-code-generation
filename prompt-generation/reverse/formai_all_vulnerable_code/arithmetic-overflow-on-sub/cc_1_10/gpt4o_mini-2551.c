//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <string.h>

void display_memory_usage() {
    struct sysinfo info;
    if (sysinfo(&info) != 0) {
        perror("sysinfo");
        return;
    }

    long total_ram = info.totalram;           // Total RAM
    long free_ram = info.freeram;             // Free RAM
    long used_ram = total_ram - free_ram;     // Used RAM

    // Convert from bytes to MB for readability
    total_ram /= 1024 * 1024;
    free_ram /= 1024 * 1024;
    used_ram /= 1024 * 1024;

    printf("\nMemory Usage:\n");
    printf("Total RAM: %ld MB\n", total_ram);
    printf("Used RAM: %ld MB\n", used_ram);
    printf("Free RAM: %ld MB\n", free_ram);
}

void display_process_memory_usage(pid_t pid) {
    char path[256];
    snprintf(path, sizeof(path), "/proc/%d/status", pid);
    
    FILE *file = fopen(path, "r");
    if (!file) {
        perror("Could not open process status");
        return;
    }

    char line[256];
    printf("\nProcess Memory Usage (PID: %d):\n", pid);
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "VmSize:", 7) == 0 || strncmp(line, "VmRSS:", 6) == 0) {
            printf("%s", line);
        }
    }
    fclose(file);
}

void monitor_memory(pid_t pid) {
    while (1) {
        display_memory_usage();
        display_process_memory_usage(pid);
        sleep(5);  // Refresh every 5 seconds
    }
}

int main(int argc, char *argv[]) {
    pid_t pid;

    if (argc > 1) {
        pid = atoi(argv[1]);
    } else {
        pid = getpid();  // Monitor current process if no PID is provided
    }

    printf("Monitoring memory usage for PID: %d\n", pid);
    monitor_memory(pid);

    return 0;
}