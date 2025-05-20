//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: future-proof
#include <stdio.h>
#include <unistd.h>

#define CPU_USAGE_REFRESH_INTERVAL 200000 // 200ms
#define BUFFER_SIZE 1024

double calculate_cpu_usage(long long idle_ticks, long long total_ticks);

int main() {
    long long previous_idle_ticks = 0, previous_total_ticks = 0;
    char buffer[BUFFER_SIZE];
    
    while(1) {
        FILE* file = fopen("/proc/stat", "r");
        if(file == NULL) {
            fprintf(stderr, "Error opening the file\n");
            return -1;
        }
        
        fgets(buffer, BUFFER_SIZE, file);
        fclose(file);
        
        // Find the first line which starts with "cpu"
        char* cpu_line = buffer;
        while(*cpu_line != 'c') cpu_line++;
        
        long long user_ticks, nice_ticks, system_ticks, idle_ticks, iowait_ticks, irq_ticks, softirq_ticks, total_ticks;
        sscanf(cpu_line, "cpu %lld %lld %lld %lld %lld %lld %lld", &user_ticks, &nice_ticks, &system_ticks, &idle_ticks, &iowait_ticks, &irq_ticks, &softirq_ticks);
        total_ticks = user_ticks + nice_ticks + system_ticks + idle_ticks + iowait_ticks + irq_ticks + softirq_ticks;
        
        double cpu_usage;
        if(previous_idle_ticks != 0 && previous_total_ticks != 0) {
            double total_ticks_diff = total_ticks - previous_total_ticks;
            double idle_ticks_diff = idle_ticks - previous_idle_ticks;
            cpu_usage = calculate_cpu_usage(idle_ticks_diff, total_ticks_diff);
            printf("CPU Usage: %f%%\n", cpu_usage);
        }
        
        previous_idle_ticks = idle_ticks;
        previous_total_ticks = total_ticks;
        
        usleep(CPU_USAGE_REFRESH_INTERVAL);
    }
}

double calculate_cpu_usage(long long idle_ticks, long long total_ticks) {
    static double previous_cpu_usage = 0.0;
    double cpu_usage = 100.0 - ((double)idle_ticks * 100.0) / (double)total_ticks;
    
    if(cpu_usage < 0.0) cpu_usage = 0.0;
    if(cpu_usage > 100.0) cpu_usage = 100.0;
    
    double cpu_usage_diff = cpu_usage - previous_cpu_usage;
    previous_cpu_usage = cpu_usage;
    
    if(cpu_usage_diff < 0.0) cpu_usage_diff = 0.0;
    
    return cpu_usage_diff;
}