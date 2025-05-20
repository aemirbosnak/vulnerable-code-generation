//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void printColored(const char *text, const char *color) {
    printf("%s%s\033[0m", color, text);  // Reset color after printing
}

void displayHeader() {
    printColored("=====================================\n", "\033[1;36m"); // Cyan
    printColored("       SYSTEM MONITORING TOOL       \n", "\033[1;35m"); // Magenta
    printColored("=====================================\n", "\033[1;36m");
}

void displayFooter() {
    printColored("\n=====================================\n", "\033[1;36m");
}

void displayUsage() {
    displayHeader();
    char cpuUsage[128];
    FILE *cpuFile = fopen("/proc/stat", "r");
    if (cpuFile) {
        fgets(cpuUsage, sizeof(cpuUsage), cpuFile);
        fclose(cpuFile);
        
        long long user, nice, system, idle;
        sscanf(cpuUsage, "cpu %lld %lld %lld %lld", &user, &nice, &system, &idle);
        long long total = user + nice + system + idle;
        double percentage = (double)(total - idle) / total * 100;

        printColored("CPU Usage: ", "\033[1;32m");  // Green
        printf("%.2f%%\n", percentage);
    } else {
        printColored("Error reading CPU file\n", "\033[1;31m"); // Red
    }

    char memInfo[256];
    FILE *memFile = fopen("/proc/meminfo", "r");
    if (memFile) {
        fgets(memInfo, sizeof(memInfo), memFile);
        printf("%s", memInfo);
        fclose(memFile);
        
        long totalMem, freeMem;
        sscanf(memInfo, "MemTotal: %ld kB\nMemFree: %ld kB", &totalMem, &freeMem);
        double usedMem = totalMem - freeMem;
        double memUsagePercentage = (usedMem / totalMem) * 100;

        printColored("Memory Usage: ", "\033[1;32m");  // Green
        printf("%.2f%% of %ld kB\n", memUsagePercentage, totalMem);
    } else {
        printColored("Error reading memory file\n", "\033[1;31m"); // Red
    }

    displayFooter();
}

int main() {
    // Infinite loop to continuously display system usage
    while (1) {
        // Clear the terminal
        printf("\033[H\033[J");
        displayUsage();
        
        // Sleep for 2 seconds before updating
        sleep(2);
    }
    
    return 0;
}