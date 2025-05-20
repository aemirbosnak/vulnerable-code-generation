//LLAMA2-13B DATASET v1.0 Category: CPU usage monitor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>
#include <math.h>

#define SAMPLING_RATE 1000
#define HISTORY_SIZE 60

struct histogram {
    int values[HISTORY_SIZE];
    int count;
};

void init_histogram(struct histogram *hist) {
    memset(hist->values, 0, sizeof(hist->values));
    hist->count = 0;
}

void update_histogram(struct histogram *hist, int value) {
    int index = value / 10;
    hist->values[index]++;
    hist->count++;
}

void print_histogram(struct histogram *hist) {
    int i;
    for (i = 0; i < HISTORY_SIZE; i++) {
        printf("%3d: %5d (%.2f%%)\n", i * 10, hist->values[i],
               (hist->values[i] * 100) / hist->count);
    }
}

int main(void) {
    struct histogram hist;
    init_histogram(&hist);

    while (1) {
        int current_usage = get_cpu_usage();
        update_histogram(&hist, current_usage);
        print_histogram(&hist);

        // Print the average CPU usage over the last second
        printf("Average CPU usage over the last second: %.2f%%\n",
               (hist.count > 0 ? hist.values[hist.count - 1] / hist.count * 100 : 0));

        // Sleep for the sampling rate
        usleep(SAMPLING_RATE * 1000);
    }

    return 0;
}

// Get the current CPU usage
int get_cpu_usage(void) {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    return usage.ru_utime.tv_sec * 100 + usage.ru_utime.tv_usec / 100000;
}