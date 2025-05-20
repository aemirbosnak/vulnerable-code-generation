//Gemma-7B DATASET v1.0 Category: RAM usage monitor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

#define RAM_SIZE 8
#define MONITOR_INTERVAL 5

typedef struct RAMUsage {
    int used;
    int free;
    int total;
} RAMUsageStruct;

RAMUsageStruct ramUsage;

void calculateRAMUsage() {
    FILE *filePtr;
    char buffer[256];
    int i, totalMemory = 0, usedMemory = 0;

    filePtr = fopen("/proc/meminfo", "r");
    if (filePtr == NULL) {
        return;
    }

    fgets(buffer, 256, filePtr);

    for (i = 0; i < RAM_SIZE; i++) {
        int value = atoi(buffer[i * 4 - 1] + buffer[i * 4] * 10 + buffer[i * 4 + 1] * 100) * 1024;
        totalMemory += value;
        usedMemory += value;
    }

    fclose(filePtr);

    ramUsage.used = usedMemory;
    ramUsage.free = totalMemory - usedMemory;
    ramUsage.total = totalMemory;
}

int main() {
    while (1) {
        calculateRAMUsage();

        printf("RAM Usage:\n");
        printf("  - Used: %.2f MB\n", (float)ramUsage.used / 1024);
        printf("  - Free: %.2f MB\n", (float)ramUsage.free / 1024);
        printf("  - Total: %.2f MB\n", (float)ramUsage.total / 1024);

        sleep(MONITOR_INTERVAL);
    }
}