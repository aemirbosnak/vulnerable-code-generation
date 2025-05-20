//GPT-4o-mini DATASET v1.0 Category: Weather simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TEMPERATURE_THRESHOLD 30
#define HUMIDITY_THRESHOLD 70
#define WIND_SPEED_THRESHOLD 20
#define MONITOR_LIMIT 5

typedef struct Weather {
    float temperature;
    float humidity;
    float wind_speed;
} Weather;

typedef struct WeatherHistory {
    Weather records[MONITOR_LIMIT];
    int index;
} WeatherHistory;

void init_weather_history(WeatherHistory *history) {
    history->index = 0;
    for (int i = 0; i < MONITOR_LIMIT; i++) {
        history->records[i].temperature = 0;
        history->records[i].humidity = 0;
        history->records[i].wind_speed = 0;
    }
}

void record_weather(WeatherHistory *history, Weather new_weather) {
    history->records[history->index] = new_weather;
    history->index = (history->index + 1) % MONITOR_LIMIT;
}

void display_weather(const Weather *weather) {
    printf("Current Weather:\n");
    printf("Temperature: %.2f °C\n", weather->temperature);
    printf("Humidity: %.2f %%\n", weather->humidity);
    printf("Wind Speed: %.2f m/s\n", weather->wind_speed);
}

void display_history(const WeatherHistory *history) {
    printf("\nWeather History:\n");
    for (int i = 0; i < MONITOR_LIMIT; i++) {
        Weather w = history->records[i];
        printf("Record %d -> Temp: %.2f °C, Humidity: %.2f %%, Wind Speed: %.2f m/s\n",
               i, w.temperature, w.humidity, w.wind_speed);
    }
}

void check_weather_alerts(const Weather *weather) {
    if (weather->temperature > TEMPERATURE_THRESHOLD) {
        printf("Alert: Temperature exceeds %d °C!\n", TEMPERATURE_THRESHOLD);
    }
    
    if (weather->humidity > HUMIDITY_THRESHOLD) {
        printf("Alert: Humidity exceeds %d %%!\n", HUMIDITY_THRESHOLD);
    }
    
    if (weather->wind_speed > WIND_SPEED_THRESHOLD) {
        printf("Alert: Wind speed exceeds %d m/s!\n", WIND_SPEED_THRESHOLD);
    }
}

Weather generate_random_weather() {
    Weather weather;
    weather.temperature = (rand() % 50); // Random temperature between 0 and 49
    weather.humidity = (rand() % 101);   // Random humidity between 0 and 100
    weather.wind_speed = (rand() % 50);   // Random wind speed between 0 and 49
    return weather;
}

int main() {
    srand(time(NULL));  // Seed for random number generation
    WeatherHistory history;
    init_weather_history(&history);
    
    char command[10];
    
    printf("Weather Simulation Program. Type 'exit' to quit.\n");
    
    while (1) {
        printf("\nType 'generate' to simulate new weather or 'history' to view history: ");
        scanf("%s", command);
        
        if (strcmp(command, "generate") == 0) {
            Weather new_weather = generate_random_weather();
            record_weather(&history, new_weather);
            display_weather(&new_weather);
            check_weather_alerts(&new_weather);
            
        } else if (strcmp(command, "history") == 0) {
            display_history(&history);
            
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting simulation... \n");
            break;
        } else {
            printf("Invalid command! Please type 'generate', 'history', or 'exit'.\n");
        }
    }
    
    return 0;
}