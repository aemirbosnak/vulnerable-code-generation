//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <time.h>

#define LOG_FILE "system_monitor.log"
#define BUFFER_SIZE 256

void log_system_metrics(double cpu_usage, long mem_total, long mem_used) {
    FILE *log_file = fopen(LOG_FILE, "a");
    if (!log_file) {
        perror("Failed to open log file");
        return;
    }

    time_t now;
    time(&now);
    char *time_str = ctime(&now);
    time_str[strlen(time_str) - 1] = '\0'; // Remove newline

    fprintf(log_file, "[%s] CPU Usage: %.2f%%, Memory Total: %ld kB, Memory Used: %ld kB\n",
            time_str, cpu_usage, mem_total, mem_used);
    fclose(log_file);
}

double calculate_cpu_usage(void) {
    static long prev_idle_time = 0, prev_total_time = 0;
    FILE *fp;
    long user_time, nice_time, system_time, idle_time, total_time;

    fp = fopen("/proc/stat", "r");
    if (!fp) {
        perror("Could not open /proc/stat");
        return -1;
    }

    fscanf(fp, "cpu %ld %ld %ld %ld", &user_time, &nice_time, &system_time, &idle_time);
    fclose(fp);

    total_time = user_time + nice_time + system_time + idle_time;
    long idle_time_delta = idle_time - prev_idle_time;
    long total_time_delta = total_time - prev_total_time;

    double cpu_usage = 100.0 * (1.0 - (double)idle_time_delta / total_time_delta);
    
    prev_idle_time = idle_time;
    prev_total_time = total_time;

    return cpu_usage;
}

void get_memory_usage(long *mem_total, long *mem_used) {
    struct sysinfo info;
    sysinfo(&info);
    *mem_total = info.totalram / 1024; // Convert to kB
    *mem_used = (info.totalram - info.freeram) / 1024; // Convert to kB
}

void display_metrics(double cpu_usage, long mem_total, long mem_used) {
    printf("CPU Usage: %.2f%%\n", cpu_usage);
    printf("Memory Total: %ld kB\n", mem_total);
    printf("Memory Used: %ld kB\n", mem_used);
}

void monitor_system(int interval_seconds) {
    while (1) {
        double cpu_usage = calculate_cpu_usage();
        long mem_total, mem_used;
        get_memory_usage(&mem_total, &mem_used);

        display_metrics(cpu_usage, mem_total, mem_used);
        log_system_metrics(cpu_usage, mem_total, mem_used);

        sleep(interval_seconds);
    }
}

int main(int argc, char *argv[]) {
    int interval_seconds = 5; // Default interval

    if (argc > 1) {
        interval_seconds = atoi(argv[1]);
        if (interval_seconds <= 0) {
            fprintf(stderr, "Invalid interval. Using default value of 5 seconds.\n");
            interval_seconds = 5;
        }
    }

    printf("Starting system monitoring every %d seconds...\n", interval_seconds);
    monitor_system(interval_seconds);

    return 0;
}