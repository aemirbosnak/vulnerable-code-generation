//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <time.h>

#define MAX_SAMPLES 10

typedef struct {
    time_t timestamp;
    double cpu_usage;
} CpUUsageRecord;

void get_cpu_usage(double *usage) {
    FILE *fp;
    long total_user, total_user_nice, total_system, total_idle, total_iowait, total_steal, total_virt;
    long total;

    fp = fopen("/proc/stat", "r");
    if (!fp) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    fscanf(fp, "cpu %ld %ld %ld %ld %ld %ld %ld %ld %ld",
           &total_user, &total_user_nice, &total_system, &total_idle,
           &total_iowait, &total_steal, &total_virt, &total, &total);
    fclose(fp);

    total = total_user + total_user_nice + total_system + total_idle + total_iowait + total_steal;
    *usage = (total == 0) ? 0.0 : 100.0 * (1.0 - ((double)total_idle / total));
}

void display_usage_records(CpUUsageRecord records[], int count) {
    printf("\nTimestamp\t\tCPU Usage\n");
    printf("-------------------------------------\n");
    for (int i = 0; i < count; i++) {
        char time_buffer[80];
        struct tm *tm_info = localtime(&records[i].timestamp);
        strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M:%S", tm_info);
        printf("%s\t%.2f%%\n", time_buffer, records[i].cpu_usage);
    }
}

int main() {
    CpUUsageRecord records[MAX_SAMPLES];
    int record_count = 0;
    double current_usage;
    time_t current_time;

    printf("CPU Usage Monitor\n");
    printf("===================\n");

    while (1) {
        if (record_count < MAX_SAMPLES) {
            get_cpu_usage(&current_usage);
            current_time = time(NULL);
            records[record_count].timestamp = current_time;
            records[record_count].cpu_usage = current_usage;
            record_count++;
        } else {
            // Shift the records to free up space for new one
            for (int i = 1; i < MAX_SAMPLES; i++) {
                records[i-1] = records[i];
            }
            get_cpu_usage(&current_usage);
            current_time = time(NULL);
            records[MAX_SAMPLES - 1].timestamp = current_time;
            records[MAX_SAMPLES - 1].cpu_usage = current_usage;
        }

        display_usage_records(records, record_count);

        printf("-------------------------------------\n");
        printf("Press Ctrl+C to exit...\n");
        sleep(2); // Pause for a while before the next measurement
    }

    return 0;
}