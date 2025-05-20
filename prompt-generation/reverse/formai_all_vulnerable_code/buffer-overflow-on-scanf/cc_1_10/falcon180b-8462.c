//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_DAYS 365
#define MIN_TEMP -50
#define MAX_TEMP 50
#define MIN_HUMIDITY 0
#define MAX_HUMIDITY 100
#define MIN_WIND_SPEED 0
#define MAX_WIND_SPEED 100
#define MIN_PRESSURE 0
#define MAX_PRESSURE 2000

struct weather_data {
    int day;
    int temperature;
    int humidity;
    int wind_speed;
    int pressure;
};

void generate_weather_data(struct weather_data *data, int num_days) {
    time_t start_time = time(NULL);
    srand(start_time);

    for (int i = 0; i < num_days; i++) {
        data[i].day = i + 1;
        data[i].temperature = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
        data[i].humidity = rand() % (MAX_HUMIDITY - MIN_HUMIDITY + 1) + MIN_HUMIDITY;
        data[i].wind_speed = rand() % (MAX_WIND_SPEED - MIN_WIND_SPEED + 1) + MIN_WIND_SPEED;
        data[i].pressure = rand() % (MAX_PRESSURE - MIN_PRESSURE + 1) + MIN_PRESSURE;
    }
}

void print_weather_data(struct weather_data *data, int num_days) {
    for (int i = 0; i < num_days; i++) {
        printf("%d: Temperature = %d, Humidity = %d, Wind Speed = %d, Pressure = %d\n",
               data[i].day, data[i].temperature, data[i].humidity, data[i].wind_speed, data[i].pressure);
    }
}

int main() {
    int num_days;
    printf("Enter the number of days for which you want to generate weather data: ");
    scanf("%d", &num_days);

    struct weather_data weather_data[MAX_DAYS];
    generate_weather_data(weather_data, num_days);
    print_weather_data(weather_data, num_days);

    return 0;
}