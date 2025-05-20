//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

void print_header() {
    printf("=========================================\n");
    printf("         CPU Usage Monitor              \n");
    printf("=========================================\n");
    printf("     CPU Usage (%) in intervals         \n");
    printf("=========================================\n");
}

void read_cpu_times(unsigned long long* idle, unsigned long long* total) {
    FILE* file = fopen("/proc/stat", "r");
    if (!file) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }
    
    char buffer[256];
    fgets(buffer, sizeof(buffer), file);
    fclose(file);
    
    unsigned long long user, nice, system, irq, softirq, iowait, steal, guest, guest_nice;
    sscanf(buffer, "cpu %llu %llu %llu %llu %llu %llu %llu %llu %llu",
           &user, &nice, &system, &irq, &softirq, &iowait, &steal, &guest, &guest_nice);
    
    *total = user + nice + system + irq + softirq + iowait + steal + guest + guest_nice;
    *idle = *total - (user + nice + system + irq + softirq + iowait + steal);
}

double calculate_cpu_usage(unsigned long long idle1, unsigned long long total1, 
                            unsigned long long idle2, unsigned long long total2) {
    unsigned long long total_diff = total2 - total1;
    unsigned long long idle_diff = idle2 - idle1;

    return 100.0 * (1.0 - (double)idle_diff / total_diff);
}

int main() {
    unsigned long long idle1, total1;
    unsigned long long idle2, total2;

    print_header();

    // Initial readings
    read_cpu_times(&idle1, &total1);
    sleep(1); // Wait for 1 second
    read_cpu_times(&idle2, &total2);

    double usage = calculate_cpu_usage(idle1, total1, idle2, total2);

    printf("Current CPU Usage: %.2f%%\n", usage);
    printf("=========================================\n");

    // Monitor indefinitely
    while (1) {
        read_cpu_times(&idle1, &total1);
        sleep(1); // Monitor every second
        read_cpu_times(&idle2, &total2);
        
        usage = calculate_cpu_usage(idle1, total1, idle2, total2);
        printf("Current CPU Usage: %.2f%%\r", usage);
        fflush(stdout);
    }

    return 0;
}