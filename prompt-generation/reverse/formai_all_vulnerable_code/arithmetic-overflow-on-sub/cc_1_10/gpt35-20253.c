//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>
#include <unistd.h>
#include <string.h>

#define MB 1024*1024

int main() {
    struct sysinfo si;
    int interval = 1; // monitoring interval in seconds
    long long total_ram = 0;
    long long free_ram = 0;
    long long used_ram = 0;
    long long prev_used_ram = 0;
    long long max_used_ram = 0;
    char comma[] = ",";
    char colon[] = ":";
    char divider[] = "-----------------------------";
    
    // Get total RAM available in the system
    if (sysinfo(&si) == 0) {
        total_ram = si.totalram * si.mem_unit / MB;
    }
    printf("Total RAM: %lld MB\n", total_ram);
    printf("%s\n", divider);
    
    // Monitor RAM usage
    while(1) {
        // Get free RAM available in the system
        if (sysinfo(&si) == 0) {
            free_ram = si.freeram * si.mem_unit / MB;
        }
        used_ram = total_ram - free_ram;
        
        // Print RAM usage stats
        printf("Used RAM: %lld MB\n", used_ram);
        if (used_ram > max_used_ram) {
            max_used_ram = used_ram;
        }
        printf("Max Used RAM: %lld MB\n", max_used_ram);
        
        // Calculate RAM usage difference between intervals
        long long diff = used_ram - prev_used_ram;
        if (prev_used_ram != 0) {
            if (diff >= 0) {
                printf("+%lld MB\n", diff);
            } else {
                diff = abs(diff);
                printf("-%lld MB\n", diff);
            }
        }
        prev_used_ram = used_ram;
        printf("%s\n", divider);
        sleep(interval);
    }
    return 0;
}