//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#define CPU_INFO_LINE 1

void parse_cpu_usage(long *total, long *idle) {
    FILE *file = fopen("/proc/stat", "r");
    if (!file) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    char buffer[256];
    fgets(buffer, sizeof(buffer), file);

    // Parsing the /proc/stat line for CPU information
    long user, nice, system, idleTime, iowait, irq, softirq, steal, guest, guest_nice;
    sscanf(buffer, "cpu %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld",
           &user, &nice, &system, &idleTime, &iowait, &irq, &softirq, &steal, &guest, &guest_nice);
    
    *total = user + nice + system + idleTime + iowait + irq + softirq + steal + guest + guest_nice;
    *idle = idleTime + iowait;

    fclose(file);
}

int main() {
    long total1, idle1, total2, idle2;
    double cpu_usage;

    parse_cpu_usage(&total1, &idle1);
    sleep(1); // Wait a second to get a second reading
    parse_cpu_usage(&total2, &idle2);

    // Calculate CPU usage
    cpu_usage = (double)(total2 - total1 - (idle2 - idle1)) / (total2 - total1) * 100.0;

    printf("CPU Usage: %.2f%%\n", cpu_usage);

    while (1) {
        sleep(1);
        parse_cpu_usage(&total1, &idle1);
        sleep(1);
        parse_cpu_usage(&total2, &idle2);

        cpu_usage = (double)(total2 - total1 - (idle2 - idle1)) / (total2 - total1) * 100.0;

        // Display CPU usage
        printf("CPU Usage: %.2f%%\r", cpu_usage);
        fflush(stdout);
    }
    
    return 0;
}