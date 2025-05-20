//GPT-4o-mini DATASET v1.0 Category: Weather simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define NUM_DAYS 10
#define CLEAR 0
#define CLOUDY 1
#define RAINY 2
#define SNOWY 3

const char *weather_conditions[] = {
    "Clear",
    "Cloudy",
    "Rainy",
    "Snowy"
};

void generate_weather(int *weather_forecast, int days);
void display_forecast(int *weather_forecast, int days);
void display_weather(int condition);

int main() {
    srand(time(NULL)); // Seed the random number generator
    int weather_forecast[NUM_DAYS];
    
    generate_weather(weather_forecast, NUM_DAYS);
    display_forecast(weather_forecast, NUM_DAYS);
    
    return 0;
}

void generate_weather(int *weather_forecast, int days) {
    for (int i = 0; i < days; i++) {
        weather_forecast[i] = rand() % 4; // Generate weather condition
    }
}

void display_forecast(int *weather_forecast, int days) {
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    
    printf("Weather Forecast for the next %d days:\n", days);
    printf("Date\t\tWeather Condition\n");
    printf("=====================================\n");
    
    for (int i = 0; i < days; i++) {
        // Increase the date by i days
        tm_info->tm_mday += 1; 
        mktime(tm_info); // normalize the structure after changing the day
        char date_string[11];
        strftime(date_string, sizeof(date_string), "%Y-%m-%d", tm_info);
        
        printf("%s\t", date_string);
        display_weather(weather_forecast[i]);
    }
}

void display_weather(int condition) {
    switch (condition) {
        case CLEAR:
            printf("%s\n", weather_conditions[CLEAR]);
            break;
        case CLOUDY:
            printf("%s\n", weather_conditions[CLOUDY]);
            break;
        case RAINY:
            printf("%s\n", weather_conditions[RAINY]);
            break;
        case SNOWY:
            printf("%s\n", weather_conditions[SNOWY]);
            break;
    }
    sleep(1); // Simulate a delay for realism
}