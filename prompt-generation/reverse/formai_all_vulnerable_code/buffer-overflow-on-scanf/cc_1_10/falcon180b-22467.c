//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_TEMPERATURES 100

struct temperature {
    time_t timestamp;
    float value;
};

int main() {
    struct temperature temperatures[MAX_TEMPERATURES];
    int num_temperatures = 0;
    float average_temperature = 0;
    float max_temperature = -100;
    float min_temperature = 100;
    float current_temperature = 0;

    printf("Starting temperature monitor...\n");

    while (1) {
        if (num_temperatures >= MAX_TEMPERATURES) {
            printf("Maximum number of temperatures reached.\n");
            break;
        }

        if (scanf("%f", &current_temperature)!= 1) {
            printf("Invalid input. Exiting program.\n");
            exit(1);
        }

        temperatures[num_temperatures].timestamp = time(NULL);
        temperatures[num_temperatures].value = current_temperature;
        num_temperatures++;

        average_temperature = 0;
        max_temperature = -100;
        min_temperature = 100;

        for (int i = 0; i < num_temperatures; i++) {
            average_temperature += temperatures[i].value;

            if (temperatures[i].value > max_temperature) {
                max_temperature = temperatures[i].value;
            }

            if (temperatures[i].value < min_temperature) {
                min_temperature = temperatures[i].value;
            }
        }

        average_temperature /= num_temperatures;

        printf("Current temperature: %.2f\n", current_temperature);
        printf("Average temperature: %.2f\n", average_temperature);
        printf("Maximum temperature: %.2f\n", max_temperature);
        printf("Minimum temperature: %.2f\n", min_temperature);
        printf("\n");
    }

    return 0;
}