//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/statvfs.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MAX_SAMPLES 100

typedef struct {
    time_t timestamp;
    size_t ram_usage;
} sample_t;

sample_t samples[MAX_SAMPLES];
size_t sample_count = 0;

size_t get_ram_usage() {
    struct statvfs statvfs_info;
    statvfs("/", &statvfs_info);
    return (size_t) statvfs_info.f_blocks * statvfs_info.f_frsize;
}

void add_sample() {
    if (sample_count == MAX_SAMPLES) {
        sample_count = 0;
    }
    samples[sample_count++] = (sample_t) {
       .timestamp = time(NULL),
       .ram_usage = get_ram_usage()
    };
}

void print_samples() {
    if (sample_count == 0) {
        printf("No samples collected.\n");
        return;
    }

    double total_ram_usage = 0;
    for (size_t i = 0; i < sample_count; i++) {
        double elapsed_time = difftime(samples[i].timestamp, samples[0].timestamp);
        double ram_usage_per_second = ((double) samples[i].ram_usage - (double) samples[0].ram_usage) / elapsed_time;
        total_ram_usage += ram_usage_per_second;
        printf("%.2f seconds elapsed, %.2f MB/s RAM usage\n", elapsed_time, ram_usage_per_second / (1024 * 1024));
    }

    double average_ram_usage = total_ram_usage / (double) sample_count;
    printf("Average RAM usage: %.2f MB/s\n", average_ram_usage / (1024 * 1024));
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <seconds>\n", argv[0]);
        return 1;
    }

    size_t seconds = strtoul(argv[1], NULL, 10);

    add_sample();

    while (sample_count < 2 || difftime(time(NULL), samples[sample_count - 1].timestamp) < seconds) {
        sleep(1);
        add_sample();
    }

    print_samples();

    return 0;
}