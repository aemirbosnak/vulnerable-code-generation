//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SAMPLES 100
#define SAMPLE_INTERVAL 1000 // in milliseconds

struct sample {
    time_t timestamp;
    int packet_count;
    int packet_loss_percentage;
    int bandwidth_usage;
};

void init_sample(struct sample* sample) {
    sample->timestamp = time(NULL);
    sample->packet_count = 0;
    sample->packet_loss_percentage = 0;
    sample->bandwidth_usage = 0;
}

void update_sample(struct sample* sample, int packet_count, int packet_loss_percentage, int bandwidth_usage) {
    sample->packet_count += packet_count;
    sample->packet_loss_percentage = (int)((float)packet_loss_percentage / packet_count * 100);
    sample->bandwidth_usage = (int)((float)bandwidth_usage / packet_count);
}

void print_sample(struct sample* sample) {
    printf("Timestamp: %s\n", ctime(&sample->timestamp));
    printf("Packet Count: %d\n", sample->packet_count);
    printf("Packet Loss Percentage: %d%%\n", sample->packet_loss_percentage);
    printf("Bandwidth Usage: %d\n", sample->bandwidth_usage);
}

void start_monitor() {
    struct sample samples[MAX_SAMPLES];
    int sample_index = 0;

    while (1) {
        sleep(SAMPLE_INTERVAL);

        int packet_count = rand() % 100;
        int packet_loss_percentage = rand() % 100;
        int bandwidth_usage = rand() % 100;

        if (sample_index >= MAX_SAMPLES) {
            sample_index = 0;
        }

        init_sample(&samples[sample_index]);
        update_sample(&samples[sample_index], packet_count, packet_loss_percentage, bandwidth_usage);
        print_sample(&samples[sample_index]);

        sample_index++;
    }
}

int main() {
    start_monitor();

    return 0;
}