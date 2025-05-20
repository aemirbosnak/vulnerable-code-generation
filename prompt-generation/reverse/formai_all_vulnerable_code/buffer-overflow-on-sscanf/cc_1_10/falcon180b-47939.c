//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM_SAMPLES 1000
#define SAMPLE_INTERVAL_MS 100

double get_cpu_temp() {
    FILE *fp;
    char line[512];
    double temp = 0;

    fp = popen("vcgencmd measure_temp", "r");
    if (fp!= NULL) {
        while (fgets(line, sizeof(line), fp)!= NULL) {
            sscanf(line, "%lf", &temp);
        }
        pclose(fp);
    }

    return temp / 1000;
}

int main() {
    double temps[NUM_SAMPLES];
    int i, j;
    double avg_temp = 0;
    double max_temp = 0;
    double min_temp = 1000;
    time_t start_time, end_time;

    srand(time(NULL));

    start_time = time(NULL);

    for (i = 0; i < NUM_SAMPLES; i++) {
        temps[i] = get_cpu_temp();
        avg_temp += temps[i];

        if (temps[i] > max_temp) {
            max_temp = temps[i];
        }

        if (temps[i] < min_temp) {
            min_temp = temps[i];
        }

        usleep(SAMPLE_INTERVAL_MS * 1000);
    }

    end_time = time(NULL);

    avg_temp /= NUM_SAMPLES;

    printf("CPU temperature monitor\n");
    printf("Samples: %d\n", NUM_SAMPLES);
    printf("Interval: %d ms\n", SAMPLE_INTERVAL_MS);
    printf("Total time: %ld s\n", end_time - start_time);
    printf("Average temperature: %.2lf °C\n", avg_temp);
    printf("Max temperature: %.2lf °C\n", max_temp);
    printf("Min temperature: %.2lf °C\n", min_temp);

    return 0;
}