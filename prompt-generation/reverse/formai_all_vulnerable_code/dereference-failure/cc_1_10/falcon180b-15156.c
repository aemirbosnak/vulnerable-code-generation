//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/statvfs.h>
#include <unistd.h>

#define MEM_USAGE_PERIOD 10 // seconds

typedef struct {
    char name[50];
    unsigned long long total;
    unsigned long long used;
    unsigned long long free;
    unsigned long long shared;
    unsigned long long buffers;
    unsigned long long cached;
} memory_usage_t;

void get_memory_usage(memory_usage_t *usage) {
    struct statvfs stat;
    if (statvfs("/", &stat) == 0) {
        usage->total = stat.f_blocks * stat.f_frsize;
        usage->used = stat.f_blocks - stat.f_bfree;
        usage->free = stat.f_bfree * stat.f_frsize;
    } else {
        printf("Error: cannot get memory usage\n");
        exit(1);
    }
}

void print_memory_usage(const memory_usage_t *usage) {
    printf("Total: %10llu bytes\n", usage->total);
    printf("Used:  %10llu bytes\n", usage->used);
    printf("Free:  %10llu bytes\n", usage->free);
    printf("Shared: %10llu bytes\n", usage->shared);
    printf("Buffers: %10llu bytes\n", usage->buffers);
    printf("Cached: %10llu bytes\n", usage->cached);
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <interval_seconds>\n", argv[0]);
        return 1;
    }

    unsigned int interval = atoi(argv[1]);
    if (interval == 0) {
        printf("Error: interval cannot be zero\n");
        return 1;
    }

    memory_usage_t prev_usage, cur_usage;
    get_memory_usage(&prev_usage);

    while (1) {
        sleep(interval);
        get_memory_usage(&cur_usage);

        printf("Interval %u seconds:\n", interval);
        print_memory_usage(&cur_usage);

        unsigned long long delta_total = cur_usage.total - prev_usage.total;
        unsigned long long delta_used = cur_usage.used - prev_usage.used;
        unsigned long long delta_free = cur_usage.free - prev_usage.free;

        printf("Delta Total: %10llu bytes\n", delta_total);
        printf("Delta Used:  %10llu bytes\n", delta_used);
        printf("Delta Free:  %10llu bytes\n", delta_free);
        printf("\n");

        memcpy(&prev_usage, &cur_usage, sizeof(memory_usage_t));
    }

    return 0;
}