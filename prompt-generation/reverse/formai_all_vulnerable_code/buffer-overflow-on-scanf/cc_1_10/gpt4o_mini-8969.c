//GPT-4o-mini DATASET v1.0 Category: Weather simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DAYS_IN_WEEK 7
#define TEMP_MIN -10
#define TEMP_MAX 35
#define HUMIDITY_MIN 20
#define HUMIDITY_MAX 100
#define WIND_MIN 0
#define WIND_MAX 20

const char* weather_types[] = {
    "Sunny",
    "Cloudy",
    "Rainy",
    "Snowy",
    "Windy",
    "Foggy"
};

typedef struct {
    int temperature;
    int humidity;
    int wind_speed;
    const char* weather_type;
} Weather;

Weather generateWeather() {
    Weather w;
    w.temperature = rand() % (TEMP_MAX - TEMP_MIN + 1) + TEMP_MIN;
    w.humidity = rand() % (HUMIDITY_MAX - HUMIDITY_MIN + 1) + HUMIDITY_MIN;
    w.wind_speed = rand() % (WIND_MAX - WIND_MIN + 1) + WIND_MIN;
    w.weather_type = weather_types[rand() % (sizeof(weather_types) / sizeof(weather_types[0]))];
    return w;
}

void displayWeather(const Weather* w, int day) {
    printf("Weather Report for Day %d:\n", day + 1);
    printf("Temperature: %d°C\n", w->temperature);
    printf("Humidity: %d%%\n", w->humidity);
    printf("Wind Speed: %d km/h\n", w->wind_speed);
    printf("Weather Type: %s\n", w->weather_type);
    printf("---------------------------\n");
}

void displayWeeklyWeather(Weather week[]) {
    for(int i = 0; i < DAYS_IN_WEEK; i++) {
        displayWeather(&week[i], i);
    }
}

int main() {
    srand(time(NULL)); // Seed for random number generation

    Weather week[DAYS_IN_WEEK];
    
    // Generate weather data for a week
    for(int i = 0; i < DAYS_IN_WEEK; i++) {
        week[i] = generateWeather();
    }

    int choice;
    do {
        printf("Weather Simulation Menu:\n");
        printf("1. View Weather for the Week\n");
        printf("2. View Individual Day Weather\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                displayWeeklyWeather(week);
                break;
            case 2:
                {
                    int day;
                    printf("Enter a day (1 to %d): ", DAYS_IN_WEEK);
                    scanf("%d", &day);
                    if(day < 1 || day > DAYS_IN_WEEK) {
                        printf("Invalid day! Please enter a number between 1 and %d.\n", DAYS_IN_WEEK);
                    } else {
                        displayWeather(&week[day - 1], day - 1);
                    }
                }
                break;
            case 3:
                printf("Exiting the Weather Simulation.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 3);
    
    return 0;
}