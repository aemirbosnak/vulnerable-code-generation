//GPT-4o-mini DATASET v1.0 Category: Weather simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMP 40
#define MIN_TEMP -10
#define MAX_HUMIDITY 100
#define MIN_HUMIDITY 0
#define MAX_WIND_SPEED 40
#define MIN_WIND_SPEED 0

typedef struct {
    int temperature; // in degrees Celsius
    int humidity;    // in percentage
    int wind_speed;  // in km/h
    char condition[20]; // e.g., sunny, rainy, cloudy
} Weather;

Weather generate_weather() {
    Weather weather;
    
    // Randomly generate weather properties
    weather.temperature = (rand() % (MAX_TEMP - MIN_TEMP + 1)) + MIN_TEMP;
    weather.humidity = (rand() % (MAX_HUMIDITY - MIN_HUMIDITY + 1)) + MIN_HUMIDITY;
    weather.wind_speed = (rand() % (MAX_WIND_SPEED - MIN_WIND_SPEED + 1)) + MIN_WIND_SPEED;

    // Determine weather condition based on randomness
    int condition = rand() % 4;
    switch (condition) {
        case 0:
            snprintf(weather.condition, sizeof(weather.condition), "Sunny");
            break;
        case 1:
            snprintf(weather.condition, sizeof(weather.condition), "Rainy");
            break;
        case 2:
            snprintf(weather.condition, sizeof(weather.condition), "Cloudy");
            break;
        case 3:
            snprintf(weather.condition, sizeof(weather.condition), "Windy");
            break;
        default:
            snprintf(weather.condition, sizeof(weather.condition), "Unknown");
            break;
    }

    return weather;
}

void display_weather(Weather weather) {
    printf("\nWeather Report:\n");
    printf("Temperature: %d°C\n", weather.temperature);
    printf("Humidity: %d%%\n", weather.humidity);
    printf("Wind Speed: %d km/h\n", weather.wind_speed);
    printf("Condition: %s\n", weather.condition);
}

void save_weather_report(Weather weather) {
    FILE *file = fopen("weather_report.txt", "a");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }
    
    fprintf(file, "Temperature: %d°C\n", weather.temperature);
    fprintf(file, "Humidity: %d%%\n", weather.humidity);
    fprintf(file, "Wind Speed: %d km/h\n", weather.wind_speed);
    fprintf(file, "Condition: %s\n\n", weather.condition);

    fclose(file);
    printf("Weather report saved to weather_report.txt\n");
}

int main() {
    srand(time(NULL)); // Seed for random number generation

    int days;
    printf("Enter the number of days to simulate weather data: ");
    scanf("%d", &days);

    for (int i = 1; i <= days; i++) {
        printf("\nDay %d:\n", i);
        Weather weather = generate_weather();
        display_weather(weather);
        save_weather_report(weather);
    }

    printf("\nWeather simulation completed for %d days.\n", days);
    return 0;
}