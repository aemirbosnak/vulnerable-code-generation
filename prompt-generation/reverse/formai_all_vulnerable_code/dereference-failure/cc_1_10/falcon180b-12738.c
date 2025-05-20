//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>

#define MAX_SAMPLES 100
#define SAMPLE_INTERVAL_SECONDS 1

struct sample {
    time_t timestamp;
    unsigned long total_memory;
    unsigned long free_memory;
    unsigned long used_memory;
};

void print_usage(char* program_name) {
    printf("Usage: %s [options]\n", program_name);
    printf("Options:\n");
    printf("  -h, --help      Print this help message\n");
}

int main(int argc, char** argv) {
    bool print_help = false;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            print_help = true;
            break;
        }
    }

    if (print_help) {
        print_usage(argv[0]);
        return 0;
    }

    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);

    unsigned long total_memory = usage.ru_maxrss;
    unsigned long free_memory = usage.ru_idrss;
    unsigned long used_memory = total_memory - free_memory;

    struct sample samples[MAX_SAMPLES];
    int sample_count = 0;

    while (true) {
        time_t current_time = time(NULL);

        if (sample_count >= MAX_SAMPLES) {
            sample_count = 0;
        }

        samples[sample_count].timestamp = current_time;
        samples[sample_count].total_memory = total_memory;
        samples[sample_count].free_memory = free_memory;
        samples[sample_count].used_memory = used_memory;

        sample_count++;

        sleep(SAMPLE_INTERVAL_SECONDS);
    }

    return 0;
}