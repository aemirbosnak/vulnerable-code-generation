//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_SAMPLES 1000
#define SAMPLE_INTERVAL 1000 // in milliseconds

struct sample {
    int timestamp;
    double throughput;
    double latency;
};

int main() {
    struct sample samples[MAX_SAMPLES];
    int num_samples = 0;
    double total_throughput = 0.0;
    double total_latency = 0.0;
    double avg_throughput = 0.0;
    double avg_latency = 0.0;
    double min_latency = 1000000.0;
    double max_latency = 0.0;
    double stddev_latency = 0.0;

    srand(time(NULL));

    while (1) {
        struct sample sample;
        sample.timestamp = time(NULL) * 1000; // in milliseconds

        double throughput = rand() % 1000;
        sample.throughput = throughput;
        total_throughput += throughput;

        double latency = (double)rand() / RAND_MAX * 1000;
        sample.latency = latency;
        total_latency += latency;

        if (num_samples >= MAX_SAMPLES) {
            break;
        }

        samples[num_samples++] = sample;
    }

    avg_throughput = total_throughput / num_samples;
    avg_latency = total_latency / num_samples;

    for (int i = 0; i < num_samples; i++) {
        if (samples[i].latency < min_latency) {
            min_latency = samples[i].latency;
        }
        if (samples[i].latency > max_latency) {
            max_latency = samples[i].latency;
        }
    }

    stddev_latency = sqrt(pow(avg_latency - avg_throughput, 2.0) / num_samples);

    printf("Total samples: %d\n", num_samples);
    printf("Average throughput: %.2f kbps\n", avg_throughput / 8.0);
    printf("Average latency: %.2f ms\n", avg_latency);
    printf("Minimum latency: %.2f ms\n", min_latency);
    printf("Maximum latency: %.2f ms\n", max_latency);
    printf("Latency standard deviation: %.2f ms\n", stddev_latency);

    return 0;
}