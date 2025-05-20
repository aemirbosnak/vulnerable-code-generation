//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DAYS 365
#define MIN_TEMP -50
#define MAX_TEMP 50

struct day {
    int temperature;
    char weather[20];
};

void generate_weather(struct day *weather_data, int num_days) {
    int i;
    for (i = 0; i < num_days; i++) {
        weather_data[i].temperature = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
        if (weather_data[i].temperature >= 0 && weather_data[i].temperature <= 15) {
            strcpy(weather_data[i].weather, "Freezing");
        } else if (weather_data[i].temperature >= 16 && weather_data[i].temperature <= 25) {
            strcpy(weather_data[i].weather, "Cold");
        } else if (weather_data[i].temperature >= 26 && weather_data[i].temperature <= 35) {
            strcpy(weather_data[i].weather, "Mild");
        } else if (weather_data[i].temperature >= 36 && weather_data[i].temperature <= 45) {
            strcpy(weather_data[i].weather, "Warm");
        } else {
            strcpy(weather_data[i].weather, "Hot");
        }
    }
}

void print_weather_data(struct day *weather_data, int num_days) {
    int i;
    for (i = 0; i < num_days; i++) {
        printf("%d: %s - %d degrees Celsius\n", i + 1, weather_data[i].weather, weather_data[i].temperature);
    }
}

int main() {
    srand(time(NULL));
    struct day weather_data[MAX_DAYS];
    int num_days;

    printf("Enter the number of days to generate weather data for: ");
    scanf("%d", &num_days);

    if (num_days > MAX_DAYS || num_days < 1) {
        printf("Invalid number of days.\n");
        return 1;
    }

    generate_weather(weather_data, num_days);
    print_weather_data(weather_data, num_days);

    return 0;
}