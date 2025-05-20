//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define DAY_IN_SECONDS (24 * 60 * 60)
#define HOUR_IN_SECONDS (60 * 60)
#define MINUTE_IN_SECONDS (60)
#define MAX_SAMPLES 100

struct sample {
    time_t timestamp;
    int steps;
};

int main() {
    FILE *fp;
    struct sample samples[MAX_SAMPLES];
    int num_samples = 0;
    double steps_per_hour, steps_per_day;

    fp = fopen("fitness_data.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open fitness_data.txt\n");
        return 1;
    }

    while (fscanf(fp, "%ld %d", &samples[num_samples].timestamp, &samples[num_samples].steps) == 2) {
        num_samples++;
        if (num_samples == MAX_SAMPLES) {
            break;
        }
    }

    fclose(fp);

    printf("Fitness data:\n");
    printf("-----------------\n");

    for (int i = 0; i < num_samples; i++) {
        printf("%s: %d steps\n", ctime(&samples[i].timestamp), samples[i].steps);
    }

    steps_per_hour = (double)num_samples / HOUR_IN_SECONDS;
    steps_per_day = (double)num_samples / DAY_IN_SECONDS;

    printf("\nAverage steps per hour: %.2f\n", steps_per_hour);
    printf("Average steps per day: %.2f\n", steps_per_day);

    return 0;
}