//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/statvfs.h>
#include <sys/types.h>
#include <unistd.h>

/* CPU usage structure */
struct CpuStats {
    unsigned long long user;
    unsigned long long nice;
    unsigned long long system;
    unsigned long long idle;
    unsigned long long iowait;
    unsigned long long irq;
    unsigned long long softirq;
};

/* Parse CPU usage from /proc/stat */
void get_cpu_stats(struct CpuStats* stats) {
    FILE* fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Error: Failed to read /proc/stat\n");
        exit(EXIT_FAILURE);
    }
    
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), fp)) {
        if (strncmp(buffer, "cpu ", 4) == 0) {
            sscanf(buffer + 4, "%llu %llu %llu %llu %llu %llu %llu",
                   &stats->user, &stats->nice, &stats->system,
                   &stats->idle, &stats->iowait, &stats->irq, &stats->softirq);
            break;
        }
    }
    
    fclose(fp);
}

/* Calculate CPU usage percentage */
double calc_cpu_usage(struct CpuStats* current, struct CpuStats* previous) {
    const unsigned long long total = (current->user + current->nice +
                                      current->system + current->idle +
                                      current->iowait + current->irq + current->softirq) -
                                     (previous->user + previous->nice +
                                      previous->system + previous->idle +
                                      previous->iowait + previous->irq + previous->softirq);
    const double percent = (double)(100 * (total - (current->idle - previous->idle)) / total);
    return percent;
}

/* Main program */
int main() {
    struct CpuStats current_stats;
    struct CpuStats previous_stats;
    memset(&current_stats, 0, sizeof(current_stats));
    memset(&previous_stats, 0, sizeof(previous_stats));
    
    /* Get initial CPU stats */
    get_cpu_stats(&previous_stats);
    
    printf("Monitoring CPU Usage\n");
    printf("---------------------\n");
    printf("Time\t\tCPU Usage\n");
    
    while (1) {
        /* Get current CPU stats */
        get_cpu_stats(&current_stats);
        
        /* Calculate CPU usage since last measurement */
        const double usage = calc_cpu_usage(&current_stats, &previous_stats);
        
        /* Print current time and CPU usage */
        const time_t now = time(NULL);
        printf("%s\t%.2lf%%\n", ctime(&now), usage);
        
        /* Sleep for one second */
        sleep(1);
        
        /* Update previous stats */
        memcpy(&previous_stats, &current_stats, sizeof(previous_stats));
    }
    
    return 0;
}