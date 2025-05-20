//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/sysinfo.h>

void printCPUUsage(long double user, long double nice, long double system, long double idle, long double iowait, long double irq, long double softirq, long double total) {
    long double total_usage = user + nice + system + idle + iowait + irq + softirq;
    long double usage_percentage = (total_usage - idle) / total_usage * 100;
    
    printf("CPU Usage: %.2Lf%%\n", usage_percentage);
}

void getCPUStats(long double *user, long double *nice, long double *system, long double *idle, long double *iowait, long double *irq, long double *softirq) {
    FILE *fp = fopen("/proc/stat", "r");
    if (!fp) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    char line[256];
    fgets(line, sizeof(line), fp);
    fclose(fp);

    sscanf(line, "cpu  %Lf %Lf %Lf %Lf %Lf %Lf %Lf",
           user, nice, system, idle, iowait, irq, softirq);
}

int main() {
    long double user = 0.0, nice = 0.0, system = 0.0, idle = 0.0, iowait = 0.0, irq = 0.0, softirq = 0.0;
    
    printf("Simple CPU Usage Monitor\n");
    printf("=========================\n");

    while (1) {
        long double user_prev = user, nice_prev = nice, system_prev = system, idle_prev = idle, iowait_prev = iowait, irq_prev = irq, softirq_prev = softirq;
        
        getCPUStats(&user, &nice, &system, &idle, &iowait, &irq, &softirq);
        long double total = user + nice + system + idle + iowait + irq + softirq;

        if (user_prev || nice_prev || system_prev || idle_prev || iowait_prev || irq_prev || softirq_prev) {
            long double diff_user = user - user_prev;
            long double diff_nice = nice - nice_prev;
            long double diff_system = system - system_prev;
            long double diff_idle = idle - idle_prev;
            long double diff_iowait = iowait - iowait_prev;
            long double diff_irq = irq - irq_prev;
            long double diff_softirq = softirq - softirq_prev;
            
            long double total_diff = diff_user + diff_nice + diff_system + diff_idle + diff_iowait + diff_irq + diff_softirq;

            printCPUUsage(diff_user, diff_nice, diff_system, diff_idle, diff_iowait, diff_irq, diff_softirq, total_diff);
        } else {
            printf("Calculating... Please wait...\n");
        }

        sleep(1); // Update every second
    }

    return 0;
}