//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/sysinfo.h>

// Post-apocalyptic RAM monitor: R3M0R3
// A tool for the last remnants of humanity to keep track of the lost memories.

void print_memory_usage(long total, long free, long used, long shared, long buff_cache) {
    printf("---- T E R R A  M E M O R Y  S C A N ----\n");
    printf("Total Memory:   %ld MB\n", total / 1024);
    printf("Free Memory:    %ld MB\n", free / 1024);
    printf("Used Memory:    %ld MB\n", used / 1024);
    printf("Shared Memory:  %ld MB\n", shared / 1024);
    printf("Buffer Cache:   %ld MB\n", buff_cache / 1024);
    printf("---- C O N S C I O U S N E S S ----\n");
}

void display_memory_warnings(long used, long total) {
    int used_percent = (used * 100) / total;
    if (used_percent > 80) {
        printf("\033[31m⚠️  Warning! Memory usage is critically high: %d%% used!\033[0m\n", used_percent);
        printf("Fixed Eyes. Lost Souls Ahead... Seek refuge in cleaner caches...\n");
    } else if (used_percent > 50) {
        printf("\033[33m⚠️  Alert! Memory usage is moderate: %d%% used!\033[0m\n", used_percent);
        printf("Security protocols activated. Beware of lingering programs.\n");
    }
}

int main() {
    struct sysinfo mem_info;

    while (1) {
        if (sysinfo(&mem_info) == 0) {
            long total = mem_info.totalram;
            long free = mem_info.freeram;
            long used = total - free;
            long shared = mem_info.sharedram;
            long buff_cache = mem_info.bufferram;

            print_memory_usage(total, free, used, shared, buff_cache);
            display_memory_warnings(used, total);
        } else {
            printf("Could not retrieve memory information.\n");
            printf("The world is crumbling. Keep that data secure...\n");
        }
        printf("Waiting for the next insight...\n");
        sleep(5); // Wait 5 seconds before the next update
    }

    return 0;
}