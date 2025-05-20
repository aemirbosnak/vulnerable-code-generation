//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/statvfs.h>
#include <unistd.h>

#define MEM_SIZE (1024 * 1024) // 1 MB

typedef struct {
    char name[32];
    unsigned long long total;
    unsigned long long used;
    float percent;
} Process;

void get_process_info(Process *process) {
    FILE *file = fopen("/proc/self/statm", "r");
    if (file == NULL) {
        printf("Error reading process info\n");
        exit(1);
    }

    fscanf(file, "%*d %*d %*d %*d %*d %*d %lu", &process->total);
    fclose(file);

    file = fopen("/proc/self/status", "r");
    if (file == NULL) {
        printf("Error reading process info\n");
        exit(1);
    }

    char line[128];
    while (fgets(line, sizeof(line), file)!= NULL) {
        if (strstr(line, "VmRSS:")!= NULL) {
            sscanf(line, "VmRSS: %lu kB", &process->used);
            break;
        }
    }

    fclose(file);

    process->percent = ((float) process->used / process->total) * 100;
}

int main() {
    Process process;
    get_process_info(&process);

    printf("Process RAM usage:\n");
    printf("Total: %llu bytes\n", process.total);
    printf("Used: %llu bytes\n", process.used);
    printf("Percent: %.2f%%\n\n", process.percent);

    char device[64];
    snprintf(device, sizeof(device), "/dev/shm");

    struct statvfs buf;
    if (statvfs(device, &buf) == -1) {
        printf("Error getting shared memory info\n");
        exit(1);
    }

    printf("Shared memory usage:\n");
    printf("Total: %llu bytes\n", buf.f_blocks * buf.f_frsize);
    printf("Used: %llu bytes\n", buf.f_blocks - buf.f_bfree * buf.f_frsize);
    printf("Free: %llu bytes\n\n", buf.f_bfree * buf.f_frsize);

    printf("Total system RAM: %llu bytes\n", buf.f_blocks * buf.f_frsize);

    return 0;
}