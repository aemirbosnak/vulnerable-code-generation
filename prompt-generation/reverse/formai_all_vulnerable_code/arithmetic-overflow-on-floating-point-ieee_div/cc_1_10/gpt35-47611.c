//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SAMPLE_TIME 1 //sampling time in seconds
#define MAX_CPUS 8 //maximum number of CPUs
#define CPUS_BASE_PATH "/sys/devices/system/cpu/"

int main() {
    int i, cpus = 0;
    char file_path[256], buffer[1024];
    long long total_time[MAX_CPUS], idle_time[MAX_CPUS], prev_total[MAX_CPUS], prev_idle[MAX_CPUS];
    float cpu_usage[MAX_CPUS];

    //count the number of CPUs
    for(i=0; i<MAX_CPUS; i++) {
        sprintf(file_path, "%s/cpu%d", CPUS_BASE_PATH, i);
        if(access(file_path, F_OK) != -1) {
            cpus++;
        } else {
            break;
        }
    }
    printf("%d CPUs detected.\n", cpus);

    //initialize the time counters
    for(i=0; i<cpus; i++) {
        prev_total[i] = prev_idle[i] = 0;
    }

    while(1) {
        //read the CPU time values
        for(i=0; i<cpus; i++) {
            sprintf(file_path, "%s/cpu%d/stat", CPUS_BASE_PATH, i);
            FILE* stat_file = fopen(file_path, "r");
            if(stat_file == NULL) {
                printf("Error opening file %s.\n", file_path);
                continue;
            }
            fgets(buffer, sizeof(buffer), stat_file);
            fclose(stat_file);
            sscanf(buffer, "cpu %lld %*d %lld %*d %lld %*d %*d %*d %*d\n", &total_time[i], &idle_time[i]);
        }

        //calculate CPU usage in percent
        for(i=0; i<cpus; i++) {
            long long total_diff = total_time[i] - prev_total[i];
            long long idle_diff = idle_time[i] - prev_idle[i];
            cpu_usage[i] = 100.0 * (float)(total_diff - idle_diff) / (float)total_diff;
            prev_total[i] = total_time[i];
            prev_idle[i] = idle_time[i];
        }

        //print the results
        for(i=0; i<cpus; i++) {
            printf("CPU%d usage: %.2f%%\n", i, cpu_usage[i]);
        }

        //wait for the next sampling
        sleep(SAMPLE_TIME);
    }

    return 0;
}