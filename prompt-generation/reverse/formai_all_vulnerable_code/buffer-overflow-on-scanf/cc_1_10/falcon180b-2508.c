//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846
#define MIN_TEMP -273.15
#define MAX_TEMP 1000.0

typedef struct {
    char name[20];
    float temp;
    float humidity;
    float pressure;
    float wind_speed;
    float wind_direction;
    time_t timestamp;
} weather_data;

int main() {
    int i;
    float temp;
    char input[20];
    time_t current_time;
    struct tm *time_info;
    weather_data data;

    // Initialize the data structure
    data.temp = MIN_TEMP;
    data.humidity = 0.0;
    data.pressure = 0.0;
    data.wind_speed = 0.0;
    data.wind_direction = 0.0;

    // Get the current time
    time(&current_time);
    time_info = localtime(&current_time);
    strftime(input, 20, "%Y-%m-%d %H:%M:%S", time_info);

    // Get the user input
    printf("Enter the temperature in Celsius: ");
    scanf("%f", &temp);

    // Convert Celsius to Fahrenheit
    data.temp = (temp * 9.0 / 5.0) + 32.0;

    // Get the current weather conditions
    printf("Enter the humidity: ");
    scanf("%f", &data.humidity);
    printf("Enter the air pressure: ");
    scanf("%f", &data.pressure);
    printf("Enter the wind speed: ");
    scanf("%f", &data.wind_speed);
    printf("Enter the wind direction: ");
    scanf("%f", &data.wind_direction);

    // Print the current weather data
    printf("Current weather data:\n");
    printf("Temperature: %.2f C\n", temp);
    printf("Temperature: %.2f F\n", data.temp);
    printf("Humidity: %.2f %%\n", data.humidity);
    printf("Air pressure: %.2f hPa\n", data.pressure);
    printf("Wind speed: %.2f m/s\n", data.wind_speed);
    printf("Wind direction: %.2f degrees\n", data.wind_direction);

    // Store the weather data in a file
    FILE *file = fopen("weather_data.txt", "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fprintf(file, "%s,%.2f,%.2f,%.2f,%.2f,%.2f\n", input, temp, data.temp, data.humidity, data.pressure, data.wind_speed);

    fclose(file);

    return 0;
}