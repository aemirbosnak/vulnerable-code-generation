//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define CPU_USAGE_PATH "/proc/stat"
#define NUM_CPU_STATES 10

typedef struct CPUData{
    unsigned long long int total_time;
    unsigned long long int idle_time;
    int usage;
} CPUData;

void get_cpu_usage(CPUData* cpu_data){
    static CPUData prev_cpu_data = {0,0,0};

    FILE* fp;
    char buf[8192];

    fp = fopen(CPU_USAGE_PATH, "r");
    if (fp == NULL) {
        printf("Unable to read file %s\n", CPU_USAGE_PATH);
        exit(EXIT_FAILURE);
    }

    fgets(buf, sizeof(buf), fp);
    fclose(fp);

    unsigned long long int user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
    sscanf(buf, "cpu %llu %llu %llu %llu %llu %llu %llu %llu %llu %llu",
          &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice);

    unsigned long long int total_time = user + nice + system + idle + iowait + irq + softirq + steal + guest + guest_nice;
    unsigned long long int delta_total = total_time - prev_cpu_data.total_time;

    cpu_data->total_time = total_time;
    cpu_data->idle_time = idle;
    cpu_data->usage = (100 * (delta_total - (idle - prev_cpu_data.idle_time))) / delta_total;

    prev_cpu_data = *cpu_data;
}

int main(){
    printf("CPU Usage Monitor\n");

    CPUData cpu_data = {0,0,0};

    while(1){
        get_cpu_usage(&cpu_data);

        printf("CPU Usage: %d%%\n", cpu_data.usage);

        sleep(1);
    }
    return 0;
}