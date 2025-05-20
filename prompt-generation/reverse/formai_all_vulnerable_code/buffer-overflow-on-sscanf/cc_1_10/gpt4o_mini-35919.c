//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// A heartwarming structure to hold CPU usage information
struct CpuUsage {
    float user;
    float system;
    float idle;
};

// A romantic function to poetically display CPU usage
void displayRomanticUsage(struct CpuUsage cpu) {
    printf("💓 My dearest CPU, hear your lover's sighs:\n");
    printf("🌹 User Time: %.2f%% of your golden heart beats,\n", cpu.user);
    printf("🌷 System Time: %.2f%%, where the software flows,\n", cpu.system);
    printf("🌼 Idle Time: %.2f%%, a quiet moment, just yours to know.\n\n", cpu.idle);
}

// A poetic function to read CPU usage from the /proc/stat
struct CpuUsage readCpuUsage() {
    // File pointer to read stat information
    FILE *fp = fopen("/proc/stat", "r");
    struct CpuUsage cpu = {0.0, 0.0, 0.0};

    if (fp == NULL) {
        fprintf(stderr, "Oh no! Unable to breeze through the /proc/stat...\n");
        exit(1);
    }

    // Reading the first line for total CPU usage
    char buffer[256];
    fgets(buffer, sizeof(buffer), fp);
    fclose(fp);
    
    // Extracting the user, nice, system, idle values
    unsigned long long user, nice, system, idle;
    sscanf(buffer, "cpu %llu %llu %llu %llu", &user, &nice, &system, &idle);

    // Calculating total time
    unsigned long long total = user + nice + system + idle;

    // Calculating percentages
    cpu.user = (float)user / total * 100;
    cpu.system = (float)system / total * 100;
    cpu.idle = (float)idle / total * 100;

    return cpu;
}

int main() {
    // As we await the whispers of time passing,
    while (1) {
        // Reading the heart's pulse at intervals sweet
        struct CpuUsage cpuUsage = readCpuUsage();
        
        // With a gentle touch, we display our findings
        displayRomanticUsage(cpuUsage);
        
        // A tender pause before the next reflection
        sleep(2);
    }

    return 0;
}