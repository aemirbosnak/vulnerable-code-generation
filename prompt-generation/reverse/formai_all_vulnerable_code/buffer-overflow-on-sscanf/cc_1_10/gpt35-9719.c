//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// Function to calculate CPU usage %
float getCpuUsage() {
    char buffer[BUFFER_SIZE];
    static long lastTotalUser = 0, lastTotalUserLow = 0, lastTotalSys = 0, lastTotalIdle = 0;

    long totalUser, totalUserLow, totalSys, totalIdle, total;

    FILE* file = fopen("/proc/stat", "r");
    if (file == NULL) {
        fprintf(stderr, "Failed to open /proc/stat file.\n");
        exit(EXIT_FAILURE);
    }

    fgets(buffer, BUFFER_SIZE, file);
    sscanf(buffer, "cpu %ld %ld %ld %ld", &totalUser, &totalUserLow, &totalSys, &totalIdle);
    fclose(file);

    if (totalUser < lastTotalUser || totalUserLow < lastTotalUserLow ||
            totalSys < lastTotalSys || totalIdle < lastTotalIdle) {
        // Overflow detected
        total = -1;
    } else {
        total = (totalUser - lastTotalUser) + (totalUserLow - lastTotalUserLow) +
                (totalSys - lastTotalSys);
    }

    lastTotalUser = totalUser;
    lastTotalUserLow = totalUserLow;
    lastTotalSys = totalSys;
    lastTotalIdle = totalIdle;

    return ((float)total / (float)(total + totalIdle)) * 100.0;
}

int main() {
    struct timeval tv;
    float cpuUsage;
    int i;

    for (i = 0; i < 10; i++) {
        gettimeofday(&tv, NULL);
        cpuUsage = getCpuUsage();
        printf("CPU Usage = %.2f%%\n", cpuUsage);

        // Sleep for 1 second
        sleep(1);
    }

    return 0;
}