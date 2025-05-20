//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/sysinfo.h>
#include <time.h>

#define MAX_BUFFER_SIZE 1024

void get_current_time(char *time_str) {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    strftime(time_str, MAX_BUFFER_SIZE, "%Y-%m-%d %H:%M:%S", tm);
}

double get_cpu_usage() {
    double usage = 0.0;
    FILE* fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open /proc/stat file.\n");
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_BUFFER_SIZE];
    unsigned long long user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
    fgets(buffer, sizeof(buffer), fp);
    sscanf(buffer, "cpu %llu %llu %llu %llu %llu %llu %llu %llu %llu %llu",
            &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice);
    unsigned long long total_idle = idle + iowait;
    unsigned long long total = user + nice + system + idle + iowait + irq + softirq + steal;
    fclose(fp);

    static unsigned long long prev_total = 0;
    static unsigned long long prev_idle = 0;
    if (prev_total != 0) {
        unsigned long long total_diff = total - prev_total;
        unsigned long long idle_diff = total_idle - prev_idle;
        usage = (total_diff - idle_diff) * 100.0 / total_diff;
    }
    prev_total = total;
    prev_idle = total_idle;

    return usage;
}

void print_cpu_usage() {
    char time_str[MAX_BUFFER_SIZE];
    get_current_time(time_str);
    printf("[%s] CPU usage: %.2f%%\n", time_str, get_cpu_usage());
}

int main(int argc, char *argv[]) {
    printf("Press Q to exit.\n");
    while(1) {
        print_cpu_usage();

        char c = getchar();
        if (c == 'Q' || c == 'q') {
            printf("Exiting...\n");
            exit(EXIT_SUCCESS);
        }

        usleep(500000);
    }
    return 0;
}