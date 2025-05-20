//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_TEMPERATURES 10
#define DELTA_T 0.5

struct Temperature {
    time_t timestamp;
    double value;
};

int main() {
    int i;
    double current_temperature = 0.0;
    struct Temperature temperatures[MAX_TEMPERATURES];

    printf("Starting temperature monitor...\n");

    for (i = 0; i < MAX_TEMPERATURES; i++) {
        temperatures[i].timestamp = time(NULL);
        temperatures[i].value = current_temperature;
        current_temperature += DELTA_T;
    }

    while (1) {
        time_t current_time = time(NULL);
        double average_temperature = 0.0;
        int temperature_count = 0;

        printf("\nCurrent temperature: %.2f\n", current_temperature);

        for (i = 0; i < MAX_TEMPERATURES; i++) {
            if (temperatures[i].timestamp + 60 > current_time) {
                average_temperature += temperatures[i].value;
                temperature_count++;
            }
        }

        if (temperature_count > 0) {
            average_temperature /= temperature_count;
            printf("Average temperature over the last minute: %.2f\n", average_temperature);
        } else {
            printf("No temperature data available.\n");
        }

        current_temperature += DELTA_T;
        temperatures[MAX_TEMPERATURES - 1].timestamp = current_time;
        temperatures[MAX_TEMPERATURES - 1].value = current_temperature;
    }

    return 0;
}