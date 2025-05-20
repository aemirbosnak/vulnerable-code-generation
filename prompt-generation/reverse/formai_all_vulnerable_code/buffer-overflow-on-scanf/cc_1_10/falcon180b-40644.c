//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_TEMPERATURES 100
#define MAX_SAMPLES 50

struct Temperature {
    time_t timestamp;
    double value;
};

void add_temperature(struct Temperature *temperatures, int *num_temperatures, double temperature) {
    if (*num_temperatures >= MAX_TEMPERATURES) {
        printf("Error: Maximum number of temperatures reached.\n");
        return;
    }

    temperatures[*num_temperatures].timestamp = time(NULL);
    temperatures[*num_temperatures].value = temperature;
    (*num_temperatures)++;
}

void print_temperatures(struct Temperature *temperatures, int num_temperatures) {
    printf("Temperature history:\n");
    printf("--------------------\n");

    for (int i = 0; i < num_temperatures; i++) {
        printf("%s: %.2f\n", ctime(&temperatures[i].timestamp), temperatures[i].value);
    }
}

void calculate_average(struct Temperature *temperatures, int num_temperatures, double *average) {
    *average = 0;

    for (int i = 0; i < num_temperatures; i++) {
        *average += temperatures[i].value;
    }

    *average /= num_temperatures;
}

int main() {
    struct Temperature temperatures[MAX_TEMPERATURES];
    int num_temperatures = 0;
    double average_temperature = 0;

    while (1) {
        double temperature;

        printf("Enter temperature (in Celsius): ");
        scanf("%lf", &temperature);

        add_temperature(temperatures, &num_temperatures, temperature);

        if (num_temperatures >= MAX_SAMPLES) {
            calculate_average(temperatures, num_temperatures, &average_temperature);
            printf("Average temperature over the last %d readings: %.2f\n", MAX_SAMPLES, average_temperature);
            num_temperatures = 0;
        }

        if (num_temperatures >= MAX_TEMPERATURES) {
            printf("Error: Maximum number of temperatures reached.\n");
            break;
        }
    }

    print_temperatures(temperatures, num_temperatures);

    return 0;
}