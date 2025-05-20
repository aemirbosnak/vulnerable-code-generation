//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

int main()
{
    int total_ram_size;
    FILE* fp = fopen("/proc/meminfo", "r");
    char line[256];

    if (fp) {
        fgets(line, sizeof(line), fp);
        sscanf(line, "MemTotal: %d", &total_ram_size);
        fclose(fp);
    }

    while(1) {
        fp = fopen("/proc/meminfo", "r");
        int free_ram;
        int used_ram;
        int buffers;
        int cached;
        int slab;

        if (fp) {
            fgets(line, sizeof(line), fp);
            sscanf(line, "MemFree: %d", &free_ram);
            fgets(line, sizeof(line), fp);
            sscanf(line, "Buffers: %d", &buffers);
            fgets(line, sizeof(line), fp);
            sscanf(line, "Cached: %d", &cached);
            fgets(line, sizeof(line), fp);
            sscanf(line, "Slab: %d", &slab);
            fclose(fp);
        }

        used_ram = total_ram_size - free_ram - buffers - cached - slab;

        printf("-------------------\n");
        printf("Total RAM size: %d\n", total_ram_size);
        printf("Used RAM: %d\n", used_ram);
        printf("Free RAM: %d\n", free_ram);
        printf("Buffers: %d\n", buffers);
        printf("Cached: %d\n", cached);
        printf("Slab: %d\n", slab);

        sleep(1);
    }

    return 0;
}