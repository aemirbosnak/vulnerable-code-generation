//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/sysinfo.h>

#define TOTAL_RAM_MB (double)get_total_ram()/(1024*1024)

double get_total_ram()
{
    struct sysinfo sys_info;
    if(sysinfo(&sys_info) != 0)
    {
        printf("Error: Failed to retrieve system information.\n");
        exit(1);
    }
    return (double)sys_info.totalram;
}

void print_header()
{
    printf("-----------------------------------------------------------\n");
    printf("|             C RAM USAGE MONITOR - SYNC VERSION           |\n");
    printf("-----------------------------------------------------------\n");
    printf("| %-20s | %-18s | %-18s |\n", "PROCESS NAME", "RAM USAGE (MB)", "RAM USAGE (%)");
    printf("-----------------------------------------------------------\n");
}

bool process_exists(char* process_name)
{
    char command[100];
    snprintf(command, sizeof(command), "pidof %s > /dev/null", process_name);
    return system(command) == 0;
}

double get_process_ram(char* process_name)
{
    char command[100];
    snprintf(command, sizeof(command), "cat /proc/$(pidof %s)/status | grep VmRSS | sed 's/[VmRSS:]//g'", process_name);
    FILE* pipe = popen(command, "r");
    if(pipe == NULL)
    {
        printf("Error: Failed to retrieve process memory usage.\n");
        exit(1);
    }
    double ram_usage;
    fscanf(pipe, "%lf", &ram_usage);
    pclose(pipe);
    return ram_usage/1024;
}

void monitor_ram_usage(char* process_name, double threshold)
{
    bool flag = true;
    while(flag)
    {
        if(process_exists(process_name))
        {
            double process_ram_usage = get_process_ram(process_name);
            double ram_usage_percent = (process_ram_usage/TOTAL_RAM_MB)*100;
            if(process_ram_usage > threshold)
            {
                printf("| %-20s | %-18.2lf | %-18.2lf |\n", process_name, process_ram_usage, ram_usage_percent);
            }
            sleep(1);
        }
        else
        {
            flag = false;
        }
    }
}

int main(int argc, char** argv)
{
    if(argc < 3)
    {
        printf("Error: Please specify process name and threshold value.\n");
        exit(1);
    }
    char* process_name = argv[1];
    double threshold = atoi(argv[2]);

    print_header();
    monitor_ram_usage(process_name, threshold);

    return 0;
}