//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#define MAX_SAMPLES 100
#define SAMPLE_INTERVAL_SECONDS 1

typedef struct sample {
    time_t timestamp;
    size_t ram_usage;
} Sample;

void log_sample(Sample* sample) {
    FILE* log_file = fopen("ram_usage.log", "a");
    if (log_file == NULL) {
        printf("Error opening log file.\n");
        return;
    }

    fprintf(log_file, "%ld,%zu\n", sample->timestamp, sample->ram_usage);
    fclose(log_file);
}

int main() {
    bool quit = false;
    Sample samples[MAX_SAMPLES];
    int sample_index = 0;
    time_t last_timestamp = 0;

    while (!quit) {
        time_t current_timestamp = time(NULL);
        if (current_timestamp - last_timestamp >= SAMPLE_INTERVAL_SECONDS) {
            size_t ram_usage = malloc_usable_size(NULL) / (1024 * 1024); // RAM usage in megabytes

            samples[sample_index].timestamp = current_timestamp;
            samples[sample_index].ram_usage = ram_usage;

            log_sample(&samples[sample_index]);

            sample_index = (sample_index + 1) % MAX_SAMPLES;
            last_timestamp = current_timestamp;
        }

        int key = getchar();
        if (key == 'q' || key == 'Q') {
            quit = true;
        }
    }

    return 0;
}