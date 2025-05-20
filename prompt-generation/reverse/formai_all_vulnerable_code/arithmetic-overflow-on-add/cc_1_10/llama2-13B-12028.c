//LLAMA2-13B DATASET v1.0 Category: Weather simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define WEATHER_REPORT_LENGTH 200
#define DAY_LENGTH 86400
#define WEATHER_TYPES 5

typedef struct weather_data {
    char day[3];
    char month[3];
    int year;
    int temperature_high;
    int temperature_low;
    int humidity;
    char weather_type[3];
} weather_data_t;

weather_data_t get_weather_data(int day, int month, int year) {
    weather_data_t data;
    data.day[0] = (day + '0') % 10;
    data.day[1] = (day / 10) % 10;
    data.day[2] = day / 100;
    data.month[0] = (month + '0') % 10;
    data.month[1] = (month / 10) % 10;
    data.month[2] = month / 100;
    data.year = year;
    data.temperature_high = (rand() % 30) + 20;
    data.temperature_low = (rand() % 30) + 10;
    data.humidity = (rand() % 100) + 50;
    data.weather_type[0] = (rand() % WEATHER_TYPES) + 'A';
    data.weather_type[1] = data.weather_type[0];
    data.weather_type[2] = ' ';
    return data;
}

void print_weather_report(weather_data_t data) {
    printf("Weather Report for %s, %s %d\n", data.day, data.month, data.year);
    printf("High: %d°C, Low: %d°C, Humidity: %d%%\n", data.temperature_high, data.temperature_low, data.humidity);
    printf("Weather Type: %c%c%c\n", data.weather_type[0], data.weather_type[1], data.weather_type[2]);
}

int main() {
    int day, month, year;
    weather_data_t data;

    do {
        printf("Enter date (DD/MM/YYYY): ");
        scanf("%d/%d/%d", &day, &month, &year);
        data = get_weather_data(day, month, year);
        print_weather_report(data);
    } while (1);

    return 0;
}