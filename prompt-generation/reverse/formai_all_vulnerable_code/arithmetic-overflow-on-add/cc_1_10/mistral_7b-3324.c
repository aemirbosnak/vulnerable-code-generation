//MISTRAL-7B DATASET v1.0 Category: Weather simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define MONTH_LENGTH 30 // Assuming an average month length of 30 days
#define MIN_TEMP -20.0 // Minimum temperature in Celsius
#define MAX_TEMP 40.0  // Maximum temperature in Celsius
#define NUM_SIMULATIONS 1000000

typedef struct {
    double temperature;
    time_t date;
} WeatherData;

void generate_random_date(WeatherData *data) {
    data->date = time(NULL) + rand() % (31 * 24 * 3600);
}

void generate_random_temperature(WeatherData *data) {
    data->temperature = MIN_TEMP + (rand() % ((int)(MAX_TEMP - MIN_TEMP + 1))) / (double)RAND_MAX * (MAX_TEMP - MIN_TEMP);
}

void print_weather_data(WeatherData data) {
    char month[10], day[10];
    struct tm *tm = localtime(&data.date);

    strftime(month, sizeof(month), "%B", tm);
    strftime(day, sizeof(day), "%d", tm);

    printf("%s %s: Temperature = %.2f°C\n", month, day, data.temperature);
}

int main() {
    srand(time(NULL));
    WeatherData weather_data[NUM_SIMULATIONS];
    double total_temperature = 0.0;

    for (int i = 0; i < NUM_SIMULATIONS; i++) {
        generate_random_date(&weather_data[i]);
        generate_random_temperature(&weather_data[i]);
        total_temperature += weather_data[i].temperature;
        if (i % 1000 == 0)
            print_weather_data(weather_data[i]);
    }

    double average_temperature = total_temperature / NUM_SIMULATIONS;
    printf("\nAverage temperature for the month: %.2f°C\n", average_temperature);

    return 0;
}