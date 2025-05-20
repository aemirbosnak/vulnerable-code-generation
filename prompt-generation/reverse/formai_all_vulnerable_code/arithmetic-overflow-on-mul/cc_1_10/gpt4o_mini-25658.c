//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <signal.h>

volatile sig_atomic_t running = 1;

void handle_signal(int signal) {
    running = 0;
}

void display_memory_info() {
    struct sysinfo memInfo;
    if (sysinfo(&memInfo) != 0) {
        fprintf(stderr, "Failed to get memory info\n");
        return;
    }

    long totalPhysMemory = memInfo.totalram;
    totalPhysMemory *= memInfo.mem_unit;

    long usedPhysMemory = memInfo.totalram - memInfo.freeram;
    usedPhysMemory *= memInfo.mem_unit;

    long totalSwapMemory = memInfo.totalswap;
    totalSwapMemory *= memInfo.mem_unit;

    long usedSwapMemory = memInfo.totalswap - memInfo.freeswap;
    usedSwapMemory *= memInfo.mem_unit;

    printf("Memory Info:\n");
    printf("Total Physical Memory: %.2f GB\n", totalPhysMemory / (1024.0 * 1024 * 1024));
    printf("Used Physical Memory: %.2f GB\n", usedPhysMemory / (1024.0 * 1024 * 1024));
    printf("Total Swap Memory: %.2f GB\n", totalSwapMemory / (1024.0 * 1024 * 1024));
    printf("Used Swap Memory: %.2f GB\n", usedSwapMemory / (1024.0 * 1024 * 1024));
    printf("---------------------------------------------\n");
}

void paranoid_monitor() {
    while (running) {
        printf("Starting memory monitoring...\n");
        display_memory_info();

        // In a paranoid style we should check CPU load as well.
        // Add a hyper-vigilant frequency checker.
        printf("WARNING: Monitoring frequency set to 5 seconds! Monitor your surroundings!\n");
        sleep(5); // Sleep for 5 seconds, paranoidly keeping track of memory usage.
    }
}

int main() {
    printf("Welcome to the Paranoid RAM Usage Monitor!\n");
    signal(SIGINT, handle_signal); // Handle SIGINT for graceful termination

    printf("WARNING: Check every 5 seconds for potential memory leaks!\n");
    printf("WARNING: Press Ctrl+C to exit cautiously.\n");

    paranoid_monitor();

    printf("Exiting the Paranoid RAM Usage Monitor...\n");
    return 0;
}