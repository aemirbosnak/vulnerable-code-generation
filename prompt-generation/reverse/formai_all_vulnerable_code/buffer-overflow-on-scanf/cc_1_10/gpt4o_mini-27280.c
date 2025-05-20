//GPT-4o-mini DATASET v1.0 Category: Weather simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_DAYS 7

typedef struct {
    char *description; // Weather description
} Weather;

Weather generate_random_weather() {
    Weather weather;
    int random_num = rand() % 4; // Generating a random number between 0 and 3

    switch (random_num) {
        case 0:
            weather.description = "Sunny";
            break;
        case 1:
            weather.description = "Rainy";
            break;
        case 2:
            weather.description = "Snowy";
            break;
        case 3:
            weather.description = "Windy";
            break;
        default:
            weather.description = "Unknown";
            break;
    }
    return weather;
}

void print_forecast(Weather *forecast, int days) {
    printf("\n----- Weather Forecast for the Next %d Days -----\n", days);
    for (int i = 0; i < days; i++) {
        printf("Day %d: %s\n", i + 1, forecast[i].description);
    }
    printf("--------------------------------------------------\n");
}

int main() {
    srand(time(NULL)); // Seed for random number generation

    Weather forecast[MAX_DAYS]; // Array to hold the weather for the week
    char choice[10];
    
    // Generate weather forecast for the week
    for (int i = 0; i < MAX_DAYS; i++) {
        forecast[i] = generate_random_weather();
    }

    printf("Welcome to the Weather Simulation Program!\n");
    
    do {
        printf("\nPlease choose an option:\n");
        printf("1. Check today's weather\n");
        printf("2. View the 7-day weather forecast\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        scanf("%s", choice);

        if (strcmp(choice, "1") == 0) {
            printf("Today's weather is: %s\n", forecast[0].description);
        } else if (strcmp(choice, "2") == 0) {
            print_forecast(forecast, MAX_DAYS);
        } else if (strcmp(choice, "3") == 0) {
            printf("Thank you for using the Weather Simulation Program. Goodbye!\n");
        } else {
            printf("Invalid choice, please try again.\n");
        }
    } while (strcmp(choice, "3") != 0);

    return 0;
}