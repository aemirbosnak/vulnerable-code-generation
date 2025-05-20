//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>

#define CPUINFO_PATH "/proc/stat" // path to CPU info file
#define INTERVAL 1 // interval in seconds between CPU usage checks

// function to read CPU usage from CPU info file
double read_cpu_usage() {
    FILE* cpuinfo = fopen(CPUINFO_PATH, "r");
    if (cpuinfo == NULL) {
        printf("Error: could not open %s\n", CPUINFO_PATH);
        exit(1);
    }

    char line[BUFSIZ];
    fgets(line, BUFSIZ, cpuinfo); // skip first line

    int user, nice, system, idle;
    if (fscanf(cpuinfo, "cpu %d %d %d %d", &user, &nice, &system, &idle) != 4) {
        printf("Error: could not read CPU usage from %s\n", CPUINFO_PATH);
        exit(1);
    }

    fclose(cpuinfo);

    return (double)(user + nice + system) / (user + nice + system + idle);
}

int main() {
    double old_usage = read_cpu_usage();
    time_t start_time = time(NULL);

    while (1) {
        double new_usage = read_cpu_usage();
        time_t now = time(NULL);

        double delta_usage = new_usage - old_usage;
        double delta_time = difftime(now, start_time);

        double usage_percent = delta_usage / delta_time * 100;

        printf("CPU Usage: %.2f%%\n", usage_percent);

        old_usage = new_usage;
        start_time = now;

        sleep(INTERVAL);
    }

    return 0;
}