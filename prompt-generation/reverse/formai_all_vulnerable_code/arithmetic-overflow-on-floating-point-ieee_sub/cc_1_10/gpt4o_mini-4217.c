//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define CPU_INFO_FILE "/proc/stat"
#define INTERVAL 1

void get_cpu_usage(float *user, float *nice, float *system, float *idle, float *iowait, float *irq, float *softirq, float *steal, float *guest, float *guest_nice) {
    FILE *file = fopen(CPU_INFO_FILE, "r");
    if (!file) {
        printf("Error: Unable to open CPU info file.\n");
        exit(EXIT_FAILURE);
    }

    char buffer[256];
    fgets(buffer, sizeof(buffer), file);
    
    sscanf(buffer, "cpu %f %f %f %f %f %f %f %f %f %f",
           user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice);
    
    fclose(file);
}

float calculate_cpu_usage(float prev_idle, float prev_total, float current_idle, float current_total) {
    float idle_delta = current_idle - prev_idle;
    float total_delta = current_total - prev_total;
    return (1.0 - (idle_delta / total_delta)) * 100.0; // Return CPU usage percentage
}

void display_cpu_usage(float usage) {
    printf("\rCPU Usage: %.2f%%   ", usage);
    fflush(stdout);
}

int main() {
    float user1, nice1, system1, idle1, iowait1, irq1, softirq1, steal1, guest1, guest_nice1;
    float user2, nice2, system2, idle2, iowait2, irq2, softirq2, steal2, guest2, guest_nice2;

    get_cpu_usage(&user1, &nice1, &system1, &idle1, &iowait1, &irq1, &softirq1, &steal1, &guest1, &guest_nice1);
    sleep(INTERVAL);
    get_cpu_usage(&user2, &nice2, &system2, &idle2, &iowait2, &irq2, &softirq2, &steal2, &guest2, &guest_nice2);

    float prev_idle = idle1 + iowait1;
    float prev_total = user1 + nice1 + system1 + idle1 + iowait1 + irq1 + softirq1 + steal1;
    
    float current_idle = user2 + nice2 + system2 + idle2 + iowait2 + irq2 + softirq2 + steal2;
    float current_total = user2 + nice2 + system2 + idle2 + iowait2 + irq2 + softirq2 + steal2;

    float cpu_usage = calculate_cpu_usage(prev_idle, prev_total, current_idle, current_total);
    
    display_cpu_usage(cpu_usage);

    while (1) {
        user1 = user2; nice1 = nice2; system1 = system2; idle1 = idle2; 
        iowait1 = iowait2; irq1 = irq2; softirq1 = softirq2; steal1 = steal2;
        guest1 = guest2; guest_nice1 = guest_nice2;

        sleep(INTERVAL);
        
        get_cpu_usage(&user2, &nice2, &system2, &idle2, &iowait2, &irq2, &softirq2, &steal2, &guest2, &guest_nice2);
        
        prev_idle = idle1 + iowait1;
        prev_total = user1 + nice1 + system1 + idle1 + iowait1 + irq1 + softirq1 + steal1;
        
        current_idle = user2 + nice2 + system2 + idle2 + iowait2 + irq2 + softirq2 + steal2;
        current_total = user2 + nice2 + system2 + idle2 + iowait2 + irq2 + softirq2 + steal2;
        
        cpu_usage = calculate_cpu_usage(prev_idle, prev_total, current_idle, current_total);
        
        display_cpu_usage(cpu_usage);
    }

    return 0;
}