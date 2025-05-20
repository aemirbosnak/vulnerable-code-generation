//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<sys/statvfs.h>
#include<sys/time.h>
#include<unistd.h>
#include<string.h>

//Function to get the current CPU usage
float getCPUUsage()
{
    FILE* file = fopen("/proc/stat", "r");
    char line[1024];
    float idle = 0.0, total = 0.0;
    fgets(line, sizeof(line), file);
    sscanf(line, "cpu %*s %*s %*s %*s %*s %*s %d %d", &idle, &total);
    fclose(file);
    return (total - idle) / total * 100.0;
}

//Function to print the CPU usage
void printCPUUsage(int current, int max)
{
    int i;
    for (i = 0; i < current; i++)
    {
        printf("#");
    }
    for (; i < max; i++)
    {
        printf(" ");
    }
    printf("\r");
}

//Recursive function to monitor CPU usage
void monitorCPUUsage(int max)
{
    int current = 0;
    float cpuUsage = getCPUUsage();
    printCPUUsage(current, max);
    current++;
    if (cpuUsage < 50.0)
    {
        printf("CPU usage is low\n");
    }
    else if (cpuUsage < 75.0)
    {
        printf("CPU usage is moderate\n");
    }
    else
    {
        printf("CPU usage is high\n");
    }
    if (current < max)
    {
        monitorCPUUsage(max);
    }
}

int main()
{
    int max = 50;
    monitorCPUUsage(max);
    return 0;
}