//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void getCPUusage()
{
    FILE *fp;
    int idle1, idle2;
    int cpu1[10], cpu2[10];
    char buf[1024] = {0};

    fp = fopen("/proc/stat", "r");

    if (!fp)
    {
        printf("Error: Failed to open file /proc/stat!\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_SET);
    fgets(buf, 1024, fp);
    sscanf(buf, "%*s %d %d %d %d %d %d %d %d %d %d",
           &cpu1[0], &cpu1[1], &cpu1[2], &cpu1[3],
           &cpu1[4], &cpu1[5], &cpu1[6], &cpu1[7], &cpu1[8], &cpu1[9]);
    idle1 = cpu1[3];
    fclose(fp);

    sleep(1);

    fp = fopen("/proc/stat", "r");

    if (!fp)
    {
        printf("Error: Failed to open file /proc/stat!\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_SET);
    fgets(buf, 1024, fp);
    sscanf(buf, "%*s %d %d %d %d %d %d %d %d %d %d",
           &cpu2[0], &cpu2[1], &cpu2[2], &cpu2[3],
           &cpu2[4], &cpu2[5], &cpu2[6], &cpu2[7], &cpu2[8], &cpu2[9]);
    idle2 = cpu2[3];
    fclose(fp);

    float usage = ((float)(idle2 - idle1) / (float)(cpu2[0] + cpu2[1] + cpu2[2] + cpu2[3] + cpu2[4] + cpu2[5] + cpu2[6] + cpu2[7] + cpu2[8] + cpu2[9] - (cpu1[0] + cpu1[1] + cpu1[2] + cpu1[3] + cpu1[4] + cpu1[5] + cpu1[6] + cpu1[7] + cpu1[8] + cpu1[9]))) * 100;

    printf("CPU Usage: %.2f%%\n", usage);
}

int main()
{
    printf("Monitoring CPU usage...\n\n");

    while (1)
    {
        getCPUusage();
        sleep(1);
    }

    return 0;
}