//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Define the data structure for a RAM usage sample
typedef struct {
    uint64_t timestamp;      // The timestamp of the sample in milliseconds
    uint64_t free_ram;       // The amount of free RAM in bytes
    uint64_t used_ram;       // The amount of used RAM in bytes
} ram_usage_sample_t;

// Define the function to get the RAM usage samples
int get_ram_usage_samples(ram_usage_sample_t **samples, uint64_t *num_samples) {
    // Get the current time
    uint64_t timestamp = time(NULL);

    // Open the /proc/meminfo file
    FILE *meminfo = fopen("/proc/meminfo", "r");
    if (meminfo == NULL) {
        return -1;
    }

    // Read the MemTotal and MemFree lines
    uint64_t mem_total = 0;
    uint64_t mem_free = 0;
    char line[1024];
    while (fgets(line, sizeof(line), meminfo) != NULL) {
        if (sscanf(line, "MemTotal: %lu kB", &mem_total) == 1) {
            mem_total *= 1024;
        } else if (sscanf(line, "MemFree: %lu kB", &mem_free) == 1) {
            mem_free *= 1024;
        }
    }

    // Close the /proc/meminfo file
    fclose(meminfo);

    // Calculate the used RAM
    uint64_t used_ram = mem_total - mem_free;

    // Create a new RAM usage sample
    ram_usage_sample_t *sample = malloc(sizeof(ram_usage_sample_t));
    if (sample == NULL) {
        return -1;
    }
    sample->timestamp = timestamp;
    sample->free_ram = mem_free;
    sample->used_ram = used_ram;

    // Add the sample to the array of samples
    *samples = realloc(*samples, (*num_samples + 1) * sizeof(ram_usage_sample_t));
    if (*samples == NULL) {
        free(sample);
        return -1;
    }
    (*samples)[*num_samples] = *sample;

    // Increment the number of samples
    (*num_samples)++;

    return 0;
}

// Define the function to print the RAM usage samples
void print_ram_usage_samples(ram_usage_sample_t *samples, uint64_t num_samples) {
    printf("Timestamp\tFree RAM\tUsed RAM\n");
    for (uint64_t i = 0; i < num_samples; i++) {
        printf("%lu\t%lu\t%lu\n",
               samples[i].timestamp, samples[i].free_ram, samples[i].used_ram);
    }
}

int main() {
    // Get the RAM usage samples
    ram_usage_sample_t *samples = NULL;
    uint64_t num_samples = 0;
    while (get_ram_usage_samples(&samples, &num_samples) == 0) {
        // Print the RAM usage samples
        print_ram_usage_samples(samples, num_samples);

        // Sleep for one second
        sleep(1);
    }

    // Free the RAM usage samples
    free(samples);

    return 0;
}