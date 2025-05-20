//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_LOADAVG 100
#define UPDATE_DELAY 1 /* in seconds */

int main()
{
    double loadavg;
    FILE *fp = fopen("/proc/loadavg", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening /proc/loadavg\n");
        exit(1);
    }
    char buf[128];
    fgets(buf, sizeof(buf), fp);
    fclose(fp);

    sscanf(buf, "%lf", &loadavg);

    printf("CPU Usage Monitor\n");
    printf("==================\n");

    // Main loop to keep displaying CPU usage
    while(1) {
        fp = fopen("/proc/loadavg", "r");
        if (fp == NULL) {
            fprintf(stderr, "Error opening /proc/loadavg\n");
            exit(1);
        }
        fgets(buf, sizeof(buf), fp);
        fclose(fp);

        sscanf(buf, "%lf", &loadavg);
        int usage = (int)(loadavg * 100 / MAX_LOADAVG);

        printf("\rCPU Usage: [");
        for (int i = 0; i < usage; i++)
            printf("=");
        for (int i = usage; i < 100; i++)
            printf(" ");
        printf("] %d%%", usage);

        fflush(stdout);

        sleep(UPDATE_DELAY);
    }
    return 0;
}