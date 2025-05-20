//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/sysinfo.h>

void displayHeader() {
    printf("\n");
    printf("**********************************\n");
    printf("*        CPU Usage Monitor       *\n");
    printf("**********************************\n");
    printf("       [Press Ctrl+C to Exit]    \n");
    printf("**********************************\n\n");
}

float calculateCpuUsage(long long prevIdle, long long prevTotal, long long idle, long long total) {
    long long totalDiff = total - prevTotal;
    long long idleDiff = idle - prevIdle;
    
    if (totalDiff == 0) {
        return 0.0;
    }
    
    return (1.0 - ((float) idleDiff / totalDiff)) * 100.0;
}

void parseCpuUsage(long long *idle, long long *total) {
    FILE *fp = fopen("/proc/stat", "r");
    if (!fp) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    char buffer[256];
    fgets(buffer, sizeof(buffer), fp);
    fclose(fp);

    char *token;
    long long user, nice, system, irq, softirq, steal, idleTime;
    
    token = strtok(buffer, " ");
    for (int i = 0; i < 8; i++) {
        token = strtok(NULL, " ");
        if (token == NULL) {
            break;
        }
        if (i == 0) continue; // Skip the "cpu" prefix
        
        switch(i) {
            case 1: user = atoll(token); break;
            case 2: nice = atoll(token); break;
            case 3: system = atoll(token); break;
            case 4: irq = atoll(token); break;
            case 5: softirq = atoll(token); break;
            case 6: steal = atoll(token); break;
            case 7: idleTime = atoll(token); break;
        }
    }

    *idle = idleTime;
    *total = user + nice + system + irq + softirq + steal + idleTime;
}

int main() {
    long long prevIdle = 0, prevTotal = 0;
    long long idle, total;

    displayHeader();

    while (1) {
        parseCpuUsage(&idle, &total);

        float cpuUsage = calculateCpuUsage(prevIdle, prevTotal, idle, total);
        printf("\rCurrent CPU Usage: %.2f%%    ", cpuUsage);

        prevIdle = idle;
        prevTotal = total;

        sleep(1);
    }

    return 0;
}