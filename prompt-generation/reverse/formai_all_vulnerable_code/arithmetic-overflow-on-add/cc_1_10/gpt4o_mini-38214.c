//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

#define MAX_SIZE 256

void print_ram_usage() {
    struct sysinfo memInfo;
    
    if (sysinfo(&memInfo) != 0) {  
        perror("sysinfo");
        return;
    }

    long totalVirtualMem = memInfo.totalram;
    totalVirtualMem += memInfo.totalswap; 
    totalVirtualMem *= memInfo.mem_unit;

    long virtualMemUsed = memInfo.totalram - memInfo.freeram;
    virtualMemUsed += memInfo.totalswap - memInfo.freeswap; 
    virtualMemUsed *= memInfo.mem_unit;

    // Convert bytes to megabytes
    double totalVirtualMemMB = totalVirtualMem / (1024.0 * 1024.0);
    double virtualMemUsedMB = virtualMemUsed / (1024.0 * 1024.0);

    double memoryUsagePercentage = (virtualMemUsedMB / totalVirtualMemMB) * 100;

    printf("Total RAM: %.2f MB\n", totalVirtualMemMB);
    printf("Used RAM: %.2f MB\n", virtualMemUsedMB);
    printf("Memory Usage: %.2f%%\n", memoryUsagePercentage);
}

void print_graph(double usage) {
    int i, width = 50;
    int used = (int)(usage / 100 * width);

    printf("Memory Usage Graph:\n[");
    for (i = 0; i < width; i++) {
        if (i < used) {
            printf("█");
        } else {
            printf(" ");
        }
    }
    printf("] %.2f%%\n", usage);
}

int main() {
    int interval = 2; // update interval in seconds
    char input[MAX_SIZE];

    printf("Welcome to the RAM Usage Monitor!\n");
    printf("This program will display the RAM usage of the system.\n");
    printf("Press Ctrl+C to exit at any time.\n\n");

    while(1) {
        print_ram_usage();
        double usage;
        struct sysinfo memInfo;
        
        if (sysinfo(&memInfo) == 0) {
            long totalram = memInfo.totalram;
            long freeram = memInfo.freeram;
            long usedram = totalram - freeram;

            usage = ((double)usedram / totalram) * 100;
            print_graph(usage);
        }

        sleep(interval);
        printf("\n");
    }

    return 0;
}