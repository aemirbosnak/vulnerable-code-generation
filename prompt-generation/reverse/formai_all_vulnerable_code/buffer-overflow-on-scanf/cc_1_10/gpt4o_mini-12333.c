//GPT-4o-mini DATASET v1.0 Category: Weather simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DAYS 7
#define WEATHER_TYPES 4

enum Weather {
    SUNNY,
    CLOUDY,
    RAINY,
    SNOWY
};

const char *weather_strings[] = {
    "Sunny",
    "Cloudy",
    "Rainy",
    "Snowy"
};

void generate_forecast(int forecast[DAYS]) {
    for (int i = 0; i < DAYS; ++i) {
        forecast[i] = rand() % WEATHER_TYPES;
    }
}

void display_forecast(int forecast[DAYS]) {
    printf("7-Day Weather Forecast:\n");
    printf("-----------------------\n");
    for (int i = 0; i < DAYS; ++i) {
        printf("Day %d: %s\n", i + 1, weather_strings[forecast[i]]);
    }
}

void suggest_activity(int weather) {
    switch (weather) {
        case SUNNY:
            printf("It's a sunny day! Perfect for a picnic in the park.\n");
            break;
        case CLOUDY:
            printf("A cloudy day! A good time to read a book at home.\n");
            break;
        case RAINY:
            printf("Rain is coming down! You may want to watch a movie indoors.\n");
            break;
        case SNOWY:
            printf("Snow has fallen! How about building a snowman outside?\n");
            break;
        default:
            printf("Unknown weather! Hmmm... What to do?\n");
    }
}

void interactive_weather_activity(int forecast[DAYS]) {
    int day_choice;
    
    printf("\nChoose a day (1-%d) to get activity suggestions: ", DAYS);
    scanf("%d", &day_choice);
    
    if (day_choice < 1 || day_choice > DAYS) {
        printf("Please choose a valid day between 1 and %d.\n", DAYS);
    } else {
        int weather = forecast[day_choice - 1];
        suggest_activity(weather);
    }
}

int main() {
    srand(time(NULL));

    int forecast[DAYS];
    
    generate_forecast(forecast);
    display_forecast(forecast);

    interactive_weather_activity(forecast);

    return 0;
}