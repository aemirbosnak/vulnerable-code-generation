//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN_WEATHER 7 // Length of weather conditions
#define LEN_CITY 20 // Length of city names

// Weather conditions
char weather_conditions[LEN_WEATHER][LEN_CITY] = {
    {"Sunny"},
    {"Cloudy"},
    {"Rainy"},
    {"Thunderstorm"},
    {"Snowy"},
    {"Hail"},
    {"Tornado"}
};

// City names
char city_names[LEN_CITY][LEN_CITY] = {
    {"New York"},
    {"Los Angeles"},
    {"Chicago"},
    {"Houston"},
    {"Philadelphia"},
    {"Phoenix"},
    {"San Antonio"},
    {"San Diego"},
    {"Dallas"},
    {"San Jose"},
    {"Austin"},
    {"Jacksonville"},
    {"Fort Worth"},
    {"Columbus"},
    {"San Francisco"},
    {"Charlotte"},
    {"Indianapolis"},
    {"Seattle"},
    {"Denver"},
    {"Washington"}
};

int main() {
    int i, j, k;
    int num_cities = 20;
    int num_days = 7;
    char city_name[LEN_CITY];
    char weather_condition[LEN_WEATHER][LEN_CITY];

    // Initialize random seed
    srand(time(NULL));

    // Get user input for number of cities
    printf("Enter the number of cities (1-20): ");
    scanf("%d", &num_cities);

    // Get user input for number of days
    printf("Enter the number of days (1-7): ");
    scanf("%d", &num_days);

    // Generate random city names
    for (i = 0; i < num_cities; i++) {
        for (j = 0; j < LEN_CITY; j++) {
            city_name[j] = city_names[i][j];
        }
        city_name[LEN_CITY-1] = '\0';
        printf("City %d: %s\n", i+1, city_name);
    }

    // Generate random weather conditions for each day
    for (i = 0; i < num_days; i++) {
        for (j = 0; j < num_cities; j++) {
            k = rand() % LEN_WEATHER;
            strcpy(weather_condition[i][j], weather_conditions[k]);
        }
    }

    // Print weather forecast for each day
    for (i = 0; i < num_days; i++) {
        printf("Day %d:\n", i+1);
        for (j = 0; j < num_cities; j++) {
            printf("%s: %s\n", city_names[j], weather_condition[i][j]);
        }
    }

    return 0;
}