//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/statvfs.h>

#define BUF_SIZE 1024

int main() {
    char buffer[BUF_SIZE];
    struct statvfs stat_info;
    int i;
    double free_mem, total_mem;

    statvfs("/", &stat_info);
    total_mem = (double)stat_info.f_blocks * (double)stat_info.f_frsize;
    free_mem = (double)stat_info.f_bfree * (double)stat_info.f_frsize;

    printf("Total memory: %.2f MB\n", total_mem / (1024 * 1024));
    printf("Free memory:  %.2f MB\n", free_mem / (1024 * 1024));
    printf("Used memory:  %.2f MB\n", (total_mem - free_mem) / (1024 * 1024));
    printf("\n");

    while (1) {
        printf("Enter PID of process to monitor (0 to exit): ");
        scanf("%d", &i);

        if (i == 0) {
            break;
        }

        sprintf(buffer, "/proc/%d/status", i);
        FILE *fp = fopen(buffer, "r");

        if (fp == NULL) {
            printf("Process not found.\n");
            continue;
        }

        char line[100];
        while (fgets(line, sizeof(line), fp)!= NULL) {
            if (strstr(line, "VmSize:")!= NULL) {
                sscanf(line, "VmSize: %*s %*s %lu kB", &free_mem);
                break;
            }
        }

        fclose(fp);

        printf("PID: %d\n", i);
        printf("Free memory: %.2f MB\n", free_mem / (1024 * 1024));
        printf("\n");
    }

    return 0;
}