//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SAMPLES 1000
#define SAMPLE_INTERVAL 1 // in seconds

typedef struct {
    time_t timestamp;
    size_t ram_usage;
} sample_t;

void add_sample(sample_t *samples, size_t ram_usage) {
    if (samples->timestamp == 0) {
        samples->timestamp = time(NULL);
    } else if (difftime(time(NULL), samples->timestamp) >= SAMPLE_INTERVAL) {
        samples->timestamp += SAMPLE_INTERVAL;
    }

    samples->ram_usage = ram_usage;
}

void print_samples(sample_t samples[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%ld: %zu bytes\n", samples[i].timestamp, samples[i].ram_usage);
    }
}

int main() {
    sample_t samples[MAX_SAMPLES];
    int sample_count = 0;

    while (1) {
        size_t ram_usage = 0;
#ifdef _WIN32
        MEMORYSTATUSEX status;
        status.dwLength = sizeof(status);
        GlobalMemoryStatusEx(&status);
        ram_usage = status.dwTotalPhys - status.dwAvailPhys;
#else
        FILE *meminfo = fopen("/proc/meminfo", "r");
        char line[64];
        while (fgets(line, sizeof(line), meminfo)) {
            if (sscanf(line, "MemTotal: %*s %zu kB", &ram_usage) == 1) {
                break;
            }
        }
        fclose(meminfo);
#endif
        add_sample(samples, ram_usage);

        if (++sample_count >= MAX_SAMPLES) {
            sample_count = 0;
            print_samples(samples, MAX_SAMPLES);
        }

        sleep(SAMPLE_INTERVAL);
    }

    return 0;
}