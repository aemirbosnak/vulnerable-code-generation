//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <sys/statvfs.h>
#include <time.h>

void display_cpu_usage() {
    printf("=== CPU Usage ===\n");
    FILE *fp;
    char line[128];
    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/stat");
        return;
    }
    
    fgets(line, sizeof(line), fp);
    fclose(fp);

    char cpu[5];
    long user, nice, system, idle;
    sscanf(line, "%s %ld %ld %ld %ld", cpu, &user, &nice, &system, &idle);

    long total = user + nice + system + idle;
    double usage = (double)(total - idle) / total * 100.0;

    printf("CPU Usage: %.2f%%\n", usage);
}

void display_disk_usage(const char *path) {
    printf("=== Disk Usage for: %s ===\n", path);
    struct statvfs stat;

    if (statvfs(path, &stat) != 0) {
        perror("Failed to get disk usage");
        return;
    }

    unsigned long total = stat.f_blocks * stat.f_frsize;
    unsigned long free = stat.f_bfree * stat.f_frsize;
    unsigned long used = total - free;

    printf("Disk Total: %.2f GB\n", total / (1024.0 * 1024 * 1024));
    printf("Disk Used: %.2f GB\n", used / (1024.0 * 1024 * 1024));
    printf("Disk Free: %.2f GB\n", free / (1024.0 * 1024 * 1024));
}

void display_uptime() {
    printf("=== System Uptime ===\n");
    struct sysinfo info;
    if (sysinfo(&info) == -1) {
        perror("sysinfo");
        return;
    }
    
    printf("Uptime: %ld days, %ld hours, %ld minutes\n", 
           info.uptime / 86400, 
           (info.uptime % 86400) / 3600, 
           (info.uptime % 3600) / 60);
}

void display_memory_usage() {
    printf("=== Memory Usage ===\n");
    struct sysinfo info;
    if (sysinfo(&info) == -1) {
        perror("sysinfo");
        return;
    }

    printf("Total RAM: %.2f GB\n", info.totalram / (1024.0 * 1024 * 1024));
    printf("Free RAM: %.2f GB\n", info.freeram / (1024.0 * 1024 * 1024));
    printf("Used RAM: %.2f GB\n", (info.totalram - info.freeram) / (1024.0 * 1024 * 1024));
}

void log_system_info(const char* log_file) {
    FILE *fp = fopen(log_file, "a");
    if (fp == NULL) {
        perror("Failed to open log file");
        return;
    }

    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    char buffer[26];
    strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
    fprintf(fp, "Log Time: %s\n", buffer);
    fclose(fp);
}

int main() {
    display_cpu_usage();
    display_disk_usage("/");
    display_memory_usage();
    display_uptime();
    
    log_system_info("system_log.txt");
    printf("System information logged to 'system_log.txt'.\n");

    return 0;
}