//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: complete
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <time.h>

#define INTERVAL 1

void print_cpu_usage() {
    static long double prev_idle_time = 0, prev_total_time = 0;
    long double idle_time = 0, total_time = 0, diff_idle_time, diff_total_time, cpu_usage;
    char command[50];
    FILE* stream = NULL;
    struct sysinfo sys_info;
    time_t time_now;
    struct tm* time_tm;
    
    // Get system uptime
    if(sysinfo(&sys_info) != 0)
        printf("Failed to get system uptime.\n");
    
    // Get current time
    time(&time_now);
    time_tm = localtime(&time_now);
    
    // Get CPU idle and total time
    stream = fopen("/proc/stat", "r");
    fscanf(stream, "%*s %Lf %Lf %Lf %Lf", &total_time, &total_time, &total_time, &idle_time);
    fclose(stream);
    
    diff_idle_time = idle_time - prev_idle_time;
    diff_total_time = total_time - prev_total_time;
    cpu_usage = 100 * (1 - (diff_idle_time / diff_total_time));
    
    prev_idle_time = idle_time;
    prev_total_time = total_time;
    
    // Print CPU usage
    printf("[%d-%02d-%02d %02d:%02d:%02d] CPU Usage: %.2Lf%%\n",
           time_tm->tm_year + 1900,
           time_tm->tm_mon + 1,
           time_tm->tm_mday,
           time_tm->tm_hour,
           time_tm->tm_min,
           time_tm->tm_sec,
           cpu_usage
    );
}

int main(int argc, char **argv) {
    int i = 0;
    while(i <= 10) {
        print_cpu_usage();
        sleep(INTERVAL);
        i++;
    }
    return 0;
}