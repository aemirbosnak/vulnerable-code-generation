//Falcon2-11B DATASET v1.0 Category: Temperature monitor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(void) {
    char cpuinfo[512];
    FILE *fp;
    float celsius, fahrenheit;

    fp = fopen("/proc/cpuinfo", "r");
    if (fp == NULL) {
        printf("Could not open /proc/cpuinfo\n");
        return 1;
    }

    fgets(cpuinfo, sizeof(cpuinfo), fp);
    fclose(fp);

    fp = fopen("/proc/cpuinfo", "r");
    fgets(cpuinfo, sizeof(cpuinfo), fp);
    fclose(fp);

    sscanf(cpuinfo, "model name : %s", &cpuinfo);
    sscanf(cpuinfo, "cpu MHz : %d", &cpuinfo);

    fp = fopen("/proc/cpuinfo", "r");
    fgets(cpuinfo, sizeof(cpuinfo), fp);
    fclose(fp);

    sscanf(cpuinfo, "core id : %d", &cpuinfo);

    printf("CPU Temperature: %.2f C\n", 0.0);

    fp = fopen("/sys/class/thermal/thermal_zone0/temp", "r");
    if (fp == NULL) {
        printf("Could not open /sys/class/thermal/thermal_zone0/temp\n");
        return 1;
    }

    fscanf(fp, "%f", &celsius);
    fclose(fp);

    printf("CPU Temperature: %.2f C\n", celsius);

    fahrenheit = (celsius * 9.0/5.0) + 32.0;
    printf("CPU Temperature: %.2f F\n", fahrenheit);

    return 0;
}