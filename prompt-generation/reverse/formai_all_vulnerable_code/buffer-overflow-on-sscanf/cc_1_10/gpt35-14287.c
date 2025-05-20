//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

int main() {
    struct sysinfo info;
    unsigned long mem_free;
    unsigned long mem_total;

    while (1) {
        if (sysinfo(&info) == -1) {
            printf("Error during systinfo call.\n");
            exit(1);
        }

        mem_total = info.totalram;
        mem_free = info.freeram;

        printf("CPU usage: %d%%\n", get_cpu_usage());
        printf("Memory usage: %lu/%lu MB\n", (mem_total - mem_free) / 1024 / 1024, mem_total / 1024 / 1024);

        sleep(1);
    }

    return 0;
}

int get_cpu_usage() {
    static unsigned long long last_total = 0, last_idle = 0;
    static int init = 1;

    FILE* fp = fopen("/proc/stat","r");
    if (fp == NULL) {
        printf("Error opening /proc/stat.\n");
        exit(1);
    }

    char buf[1024];
    fgets(buf, sizeof(buf), fp);

    unsigned long long user, nice, sys, idle, iowait, irq, softirq, steal, guest, guest_nice;
    sscanf(buf, "cpu %llu %llu %llu %llu %llu %llu %llu %llu %llu %llu", &user, &nice, &sys, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice);

    if (init) {
        init = 0;
    } else {
        unsigned long long total = user + nice + sys + idle + iowait + irq + softirq + steal;
        unsigned long long diff_total = total - last_total;
        unsigned long long diff_idle = idle - last_idle;
        last_total = total;
        last_idle = idle;

        fclose(fp);
        return (int)((1000 * (diff_total - diff_idle) / diff_total + 5) / 10);
    }

    fclose(fp);
    return 0;
}