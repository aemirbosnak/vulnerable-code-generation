//Falcon2-11B DATASET v1.0 Category: Temperature monitor ; Style: authentic
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <signal.h>

int main() {
    int i, j, k;
    char str[20];
    FILE *fp;
    char file_name[100];

    // Read the CPU temperature
    fp = fopen("/proc/acpi/thermal_zone/THM/temperature", "r");
    fscanf(fp, "%s", str);
    printf("CPU Temperature: %s\n", str);

    // Read the CPU fan speed
    fp = fopen("/proc/acpi/thermal_zone/THM/fan", "r");
    fscanf(fp, "%s", str);
    printf("CPU Fan Speed: %s\n", str);

    // Read the system temperature
    fp = fopen("/proc/acpi/thermal_zone/THM/temperature", "r");
    fscanf(fp, "%s", str);
    printf("System Temperature: %s\n", str);

    // Read the system fan speed
    fp = fopen("/proc/acpi/thermal_zone/THM/fan", "r");
    fscanf(fp, "%s", str);
    printf("System Fan Speed: %s\n", str);

    // Read the system load
    getloadavg(&i, &j, &k);
    printf("System Load: %d %d %d\n", i, j, k);

    // Read the system uptime
    fp = fopen("/proc/uptime", "r");
    fscanf(fp, "%s", str);
    printf("System Uptime: %s\n", str);

    // Read the system information
    fp = fopen("/proc/cpuinfo", "r");
    while (fscanf(fp, "%s", str)!= EOF) {
        printf("%s\n", str);
    }

    // Read the system information
    fp = fopen("/proc/meminfo", "r");
    while (fscanf(fp, "%s", str)!= EOF) {
        printf("%s\n", str);
    }

    // Read the system information
    fp = fopen("/proc/diskstats", "r");
    while (fscanf(fp, "%s", str)!= EOF) {
        printf("%s\n", str);
    }

    // Read the system information
    fp = fopen("/proc/swaps", "r");
    while (fscanf(fp, "%s", str)!= EOF) {
        printf("%s\n", str);
    }

    // Read the system information
    fp = fopen("/proc/uptime", "r");
    fscanf(fp, "%s", str);
    printf("System Uptime: %s\n", str);

    // Read the system information
    fp = fopen("/proc/loadavg", "r");
    fscanf(fp, "%s", str);
    printf("System Load: %s\n", str);

    return 0;
}