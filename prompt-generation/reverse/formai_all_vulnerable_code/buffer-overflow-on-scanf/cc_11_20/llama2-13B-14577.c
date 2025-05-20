//LLAMA2-13B DATASET v1.0 Category: Weather simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TEMP 40
#define MIN_TEMP -20
#define MAX_HUM 100
#define MIN_HUM 20
#define DAY_LENGTH 24

typedef struct {
    int temperature;
    int humidity;
} weather_data_t;

weather_data_t get_weather_data(int day, int month, int year) {
    weather_data_t data;
    data.temperature = get_temperature(day, month, year);
    data.humidity = get_humidity(day, month, year);
    return data;
}

int get_temperature(int day, int month, int year) {
    int temperature;
    switch (month) {
        case 1:
            temperature = (day == 1) ? 20 : 15;
            break;
        case 2:
            temperature = (day == 1) ? 25 : 20;
            break;
        case 3:
            temperature = (day == 1) ? 28 : 25;
            break;
        case 4:
            temperature = (day == 1) ? 22 : 25;
            break;
        case 5:
            temperature = (day == 1) ? 25 : 22;
            break;
        case 6:
            temperature = (day == 1) ? 28 : 25;
            break;
        case 7:
            temperature = (day == 1) ? 30 : 28;
            break;
        case 8:
            temperature = (day == 1) ? 25 : 30;
            break;
        case 9:
            temperature = (day == 1) ? 22 : 25;
            break;
        case 10:
            temperature = (day == 1) ? 18 : 22;
            break;
        case 11:
            temperature = (day == 1) ? 15 : 18;
            break;
        case 12:
            temperature = (day == 1) ? 12 : 15;
            break;
        default:
            temperature = 0;
            break;
    }
    return temperature;
}

int get_humidity(int day, int month, int year) {
    int humidity;
    switch (month) {
        case 1:
            humidity = (day == 1) ? 60 : 80;
            break;
        case 2:
            humidity = (day == 1) ? 70 : 80;
            break;
        case 3:
            humidity = (day == 1) ? 80 : 70;
            break;
        case 4:
            humidity = (day == 1) ? 70 : 80;
            break;
        case 5:
            humidity = (day == 1) ? 80 : 70;
            break;
        case 6:
            humidity = (day == 1) ? 80 : 70;
            break;
        case 7:
            humidity = (day == 1) ? 70 : 80;
            break;
        case 8:
            humidity = (day == 1) ? 60 : 70;
            break;
        case 9:
            humidity = (day == 1) ? 50 : 60;
            break;
        case 10:
            humidity = (day == 1) ? 40 : 50;
            break;
        case 11:
            humidity = (day == 1) ? 30 : 40;
            break;
        case 12:
            humidity = (day == 1) ? 20 : 30;
            break;
        default:
            humidity = 0;
            break;
    }
    return humidity;
}

int main() {
    int day, month, year;
    weather_data_t data;

    printf("Enter the date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &day, &month, &year);

    data = get_weather_data(day, month, year);

    printf("Weather for %d/%d/%d\n", day, month, year);
    printf("Temperature: %d degrees Celsius\n", data.temperature);
    printf("Humidity: %d percent\n", data.humidity);

    return 0;
}