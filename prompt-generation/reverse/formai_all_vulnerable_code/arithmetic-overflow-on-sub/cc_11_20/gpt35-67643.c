//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

// function to get CPU usage in percentage
float get_cpu_usage() {
    FILE *fp = fopen("/proc/stat", "r");
    if (!fp) {
        fprintf(stderr, "Error opening /proc/stat: %s\n", strerror(errno));
        return -1;
    }
    char line[512];
    fgets(line, sizeof(line), fp);  // read first line
    fclose(fp);
    char *tok = strtok(line, " ");  // tokenize first line
    long long user, nice, system, idle, iowait, irq, softirq, steal;
    if (sscanf(strtok(NULL, " "), "%lld", &user) != 1 || sscanf(strtok(NULL, " "), "%lld", &nice) != 1 || sscanf(strtok(NULL, " "), "%lld", &system) != 1 || sscanf(strtok(NULL, " "), "%lld", &idle) != 1 || sscanf(strtok(NULL, " "), "%lld", &iowait) != 1 || sscanf(strtok(NULL, " "), "%lld", &irq) != 1 || sscanf(strtok(NULL, " "), "%lld", &softirq) != 1 || sscanf(strtok(NULL, " "), "%lld", &steal) != 1) {
        fprintf(stderr, "Error parsing /proc/stat\n");
        return -1;
    }
    long long prev_idle = idle, prev_total = user + nice + system + idle + iowait + irq + softirq + steal;
    usleep(100000);  // sleep for 100ms
    fp = fopen("/proc/stat", "r");
    if (!fp) {
        fprintf(stderr, "Error opening /proc/stat: %s\n", strerror(errno));
        return -1;
    }
    fgets(line, sizeof(line), fp);  // read first line again
    fclose(fp);
    tok = strtok(line, " ");  // tokenize first line again
    if (sscanf(strtok(NULL, " "), "%lld", &user) != 1 || sscanf(strtok(NULL, " "), "%lld", &nice) != 1 || sscanf(strtok(NULL, " "), "%lld", &system) != 1 || sscanf(strtok(NULL, " "), "%lld", &idle) != 1 || sscanf(strtok(NULL, " "), "%lld", &iowait) != 1 || sscanf(strtok(NULL, " "), "%lld", &irq) != 1 || sscanf(strtok(NULL, " "), "%lld", &softirq) != 1 || sscanf(strtok(NULL, " "), "%lld", &steal) != 1) {
        fprintf(stderr, "Error parsing /proc/stat\n");
        return -1;
    }
    long long curr_idle = idle, curr_total = user + nice + system + idle + iowait + irq + softirq + steal;
    float cpu_usage = 100.0 - ((curr_idle - prev_idle) * 100.0) / (curr_total - prev_total);
    return cpu_usage;
}

int main() {
    float cpu_usage;
    while (1) {  // infinite loop to monitor CPU usage
        cpu_usage = get_cpu_usage();
        if (cpu_usage < 0) {
            fprintf(stderr, "Error getting CPU usage\n");
            break;
        }
        printf("CPU usage: %.2f%%\n", cpu_usage);
        sleep(1);
    }
    return 0;
}