//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    double cpuUsage;
    FILE *fPtr;
    char buffer[1024];
    int coreCount;
    long idle;
    long total;
    long prevIdle[8] = {0};
    long prevTotal[8] = {0};
    int i, j;

    fPtr = fopen("/proc/stat", "r");
    if (!fPtr) {
        fprintf(stderr, "Error: Unable to open /proc/stat\n");
        return EXIT_FAILURE;
    }

    fgets(buffer, sizeof buffer, fPtr);
    fclose(fPtr);

    sscanf(buffer, "cpu %ld %ld %ld %ld %ld %ld %ld %ld\n", &prevTotal[0],
           &prevTotal[1], &prevTotal[2], &prevTotal[3], &prevTotal[4],
           &prevTotal[5], &prevTotal[6], &prevTotal[7]);

    coreCount = 0;
    while (prevTotal[coreCount] != 0 && coreCount < 8) {
        coreCount++;
    }

    printf("%d cores detected\n", coreCount);

    while (1) {
        fPtr = fopen("/proc/stat", "r");
        if (!fPtr) {
            fprintf(stderr, "Error: Unable to open /proc/stat\n");
            return EXIT_FAILURE;
        }

        fgets(buffer, sizeof buffer, fPtr);
        fclose(fPtr);

        sscanf(buffer, "cpu %ld %*ld %ld %*ld %*ld %*ld %*ld %*ld\n",
               &idle, &total);

        for (i = 0; i < coreCount; i++) {
            fPtr = fopen("/proc/stat", "r");
            if (!fPtr) {
                fprintf(stderr, "Error: Unable to open /proc/stat\n");
                return EXIT_FAILURE;
            }

            for (j = 0; j <= i; j++) {
                fgets(buffer, sizeof buffer, fPtr);
            }

            fclose(fPtr);

            sscanf(buffer, "cpu%*d %ld %*ld %ld %*ld %*ld %*ld %*ld %*ld\n",
                   &prevIdle[i], &prevTotal[i]);
        }

        idle -= prevIdle[0];
        total -= prevTotal[0];

        cpuUsage = 1.0 - ((double)idle / (double)total);

        printf("CPU Usage: %.2f%%\n", cpuUsage * 100);

        sleep(1);
    }

    return EXIT_SUCCESS;
}