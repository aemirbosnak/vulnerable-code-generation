//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/sysinfo.h>
#include <signal.h>
#include <time.h>

#define THRESHOLD 75  // Memory usage threshold in percentage
#define SLEEP_INTERVAL 5  // Monitor interval in seconds

void signal_handler(int signum) {
    if (signum == SIGINT) {
        printf("\nCaught SIGINT! Exiting memory monitor...\n");
        exit(0);
    }
}

void display_memory_usage() {
    struct sysinfo memInfo;
    sysinfo(&memInfo);
    
    long totalRAM = memInfo.totalram;
    totalRAM += memInfo.totalswap;
    totalRAM *= memInfo.mem_unit;
    
    long freeRAM = memInfo.freeram;
    freeRAM *= memInfo.mem_unit;

    long usedRAM = totalRAM - freeRAM;
    float usedPercent = ((float)usedRAM / totalRAM) * 100;

    printf("Total Memory: %ld bytes\n", totalRAM);
    printf("Used Memory: %ld bytes (%.2f%%)\n", usedRAM, usedPercent);
    
    if (usedPercent > THRESHOLD) {
        printf("\033[0;31mWarning: Memory usage exceeds the threshold of %d%%!\033[0m\n", THRESHOLD);
    } else {
        printf("\033[0;32mMemory usage is under control.\033[0m\n");
    }
    
    printf("\n");
}

void print_separator() {
    for (int i = 0; i < 50; i++) {
        printf("-");
    }
    printf("\n");
}

void display_time() {
    time_t now;
    time(&now);
    printf("Current Time: %s\n", ctime(&now));
}

int main() {
    signal(SIGINT, signal_handler);
    
    printf("=== RAM Usage Monitor ===\n");
    
    while (1) {
        display_time();
        display_memory_usage();
        print_separator();
        
        sleep(SLEEP_INTERVAL);
    }
    
    return 0;
}