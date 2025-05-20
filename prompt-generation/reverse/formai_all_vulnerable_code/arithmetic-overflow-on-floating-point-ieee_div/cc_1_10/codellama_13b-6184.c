//Code Llama-13B DATASET v1.0 Category: CPU usage monitor ; Style: statistical
// CPU Usage Monitor
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

// Function to get the CPU usage in percentage
double get_cpu_usage(int pid) {
    FILE *fp;
    char str[1024];
    char *result;
    int total_cpu, total_time, seconds;
    double cpu_usage;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Error: Could not open /proc/stat file\n");
        return -1;
    }

    fgets(str, sizeof(str), fp);
    fclose(fp);

    result = strtok(str, " ");
    while (result != NULL) {
        if (strcmp(result, "cpu") == 0) {
            result = strtok(NULL, " ");
            total_cpu = atoi(result);
            result = strtok(NULL, " ");
            total_cpu += atoi(result);
            result = strtok(NULL, " ");
            total_cpu += atoi(result);
            result = strtok(NULL, " ");
            total_cpu += atoi(result);
            break;
        }
        result = strtok(NULL, " ");
    }

    fp = fopen("/proc/uptime", "r");
    if (fp == NULL) {
        perror("Error: Could not open /proc/uptime file\n");
        return -1;
    }

    fgets(str, sizeof(str), fp);
    fclose(fp);

    result = strtok(str, " ");
    seconds = atoi(result);

    cpu_usage = (double)total_cpu / (double)seconds;

    return cpu_usage;
}

int main() {
    int pid = getpid();
    double cpu_usage;

    while (1) {
        cpu_usage = get_cpu_usage(pid);
        printf("CPU Usage: %.2f%%\n", cpu_usage);
        sleep(1);
    }

    return 0;
}