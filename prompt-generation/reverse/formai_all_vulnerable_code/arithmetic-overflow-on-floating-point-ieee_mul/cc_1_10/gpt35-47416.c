//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>

#define TOTAL_RAM    (double)get_total_ram()
#define MB           (double)(1024 * 1024)

double get_total_ram()
{
    struct sysinfo info;
    sysinfo(&info);
    return info.totalram / MB;
}

double get_used_ram()
{
    FILE *fp;
    double used_ram;
    char buffer[1024];
    fp = fopen("/proc/meminfo", "r");
    fgets(buffer, 1024, fp);
    sscanf(buffer, "MemTotal: %lf kB", &used_ram);
    used_ram /= MB;
    fclose(fp);
    return used_ram;
}

double get_ram_usage_percentage()
{
    double total_ram = TOTAL_RAM;
    if (total_ram <= 0)
        return 0;

    double used_ram = get_used_ram();
    double usage_percentage = used_ram / total_ram * 100.0;
    return usage_percentage;
}

void display_ram_usage()
{
    double total_ram = TOTAL_RAM;
    if (total_ram <= 0)
        return;

    double used_ram = get_used_ram();
    double usage_percentage = get_ram_usage_percentage();

    printf("Total RAM: %.2f MB\n", total_ram);
    printf("Used RAM: %.2f MB\n", used_ram);
    printf("RAM Usage: %.2f%%\n", usage_percentage);
}

int main()
{
    while (1) {
        system("clear"); // clear the console
        display_ram_usage();
        sleep(1); // wait for 1 second
    }
    return 0;
}