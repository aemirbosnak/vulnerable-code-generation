//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/sysinfo.h>

#define SECONDS_TO_MONITOR 5

void draw_progress_bar(int percentage) {
    int barWidth = 50;
    int pos = barWidth * percentage / 100;

    printf("[");
    for (int i = 0; i < barWidth; i++) {
        if (i < pos) {
            printf("=");
        } else {
            printf(" ");
        }
    }
    printf("] %d%%\n", percentage);
}

void print_cpu_usage(float usage) {
    printf("\n~~~~~~~~~~~ CPU Usage Monitor ~~~~~~~~~~~\n");
    printf("Current CPU Usage: ");
    draw_progress_bar((int) usage);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

float calculate_cpu_usage() {
    FILE *fp;
    char buffer[1024];
    long double a[4], idle, nonidle, total, prev_total, prev_idle;
    
    fp = fopen("/proc/stat", "r");
    fgets(buffer, sizeof(buffer) - 1, fp);
    sscanf(buffer, "cpu  %Lf %Lf %Lf %Lf", &a[0], &a[1], &a[2], &idle);
    
    nonidle = a[0] + a[1] + a[2];
    total = nonidle + idle;

    fclose(fp);
    
    static long double last_total = 0, last_idle = 0;
    float usage = 0;

    if (last_total == 0 && last_idle == 0) {
        last_total = total;
        last_idle = idle;
        return 0; // First run, no calculation
    }

    long double total_delta = total - last_total;
    long double idle_delta = idle - last_idle;
    
    last_total = total;
    last_idle = idle;

    usage = (total_delta - idle_delta) / total_delta * 100;
    return usage;
}

int main() {
    printf("Starting CPU Usage Monitor...\n");
    printf("Monitoring for %d seconds...\n", SECONDS_TO_MONITOR);

    for (int i = 0; i < SECONDS_TO_MONITOR; i++) {
        float usage = calculate_cpu_usage();
        print_cpu_usage(usage);
        sleep(1);
    }

    printf("Monitoring complete!\n");
    return 0;
}