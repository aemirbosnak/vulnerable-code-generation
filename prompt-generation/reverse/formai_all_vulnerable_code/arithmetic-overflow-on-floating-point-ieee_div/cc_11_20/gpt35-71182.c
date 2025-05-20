//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

int main() {
    for(int i=0; i<10; i++) {
        struct sysinfo info;
        if(sysinfo(&info) != 0) {
            printf("Error: failed to get system info.\n");
            exit(1);
        }
        long int total_ram = info.totalram / 1024 / 1024;
        long int free_ram = info.freeram / 1024 / 1024;
        double cpu_usage = 0;
        FILE* file = fopen("/proc/stat", "r");
        if(file == NULL) {
            printf("Error: failed to open /proc/stat.\n");
            continue;
        }
        char buffer[1024];
        fgets(buffer, 1024, file);
        fclose(file);
        char* token = strtok(buffer, " ");
        if(token == NULL || strncmp(token, "cpu", 3) != 0) {
            printf("Error: /proc/stat does not begin with 'cpu'.\n");
            continue;
        }
        unsigned long long int user, nice, system, idle, iowait, irq, softirq, steal;
        if(sscanf(token + 3, "%llu %llu %llu %llu %llu %llu %llu %llu", &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal) != 8) {
            printf("Error: failed to parse /proc/stat.\n");
            continue;
        }
        usleep(1000000);
        file = fopen("/proc/stat", "r");
        if(file == NULL) {
            printf("Error: failed to open /proc/stat.\n");
            continue;
        }
        fgets(buffer, 1024, file);
        fclose(file);
        token = strtok(buffer, " ");
        if(token == NULL || strncmp(token, "cpu", 3) != 0) {
            printf("Error: /proc/stat does not begin with 'cpu'.\n");
            continue;
        }
        unsigned long long int user2, nice2, system2, idle2, iowait2, irq2, softirq2, steal2;
        if(sscanf(token + 3, "%llu %llu %llu %llu %llu %llu %llu %llu", &user2, &nice2, &system2, &idle2, &iowait2, &irq2, &softirq2, &steal2) != 8) {
            printf("Error: failed to parse /proc/stat.\n");
            continue;
        }
        unsigned long long int work = (user2 + nice2 + system2 + irq2 + softirq2 + steal2) - (user + nice + system + irq + softirq + steal);
        unsigned long long int total = work + idle2 - idle;
        cpu_usage = ((double)work / (double)total) * 100;
        printf("Total RAM: %ld MB\n", total_ram);
        printf("Free RAM: %ld MB\n", free_ram);
        printf("CPU Usage: %.2f%%\n", cpu_usage);
    }
    return 0;
}