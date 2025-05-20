//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 10
#define MAX_DAYS 365

struct city {
    char name[20];
    int temperature;
};

void generate_weather(struct city *cities, int num_cities, int days) {
    srand(time(NULL));
    for (int i = 0; i < num_cities; i++) {
        cities[i].temperature = rand() % 50 + 10;
    }

    for (int i = 0; i < days; i++) {
        for (int j = 0; j < num_cities; j++) {
            // Generate random weather for each city
            int weather = rand() % 4;
            switch (weather) {
                case 0:
                    cities[j].temperature += rand() % 5 - 2;
                    break;
                case 1:
                    cities[j].temperature += rand() % 5 - 2;
                    break;
                case 2:
                    cities[j].temperature -= rand() % 5 - 2;
                    break;
                case 3:
                    cities[j].temperature -= rand() % 5 - 2;
                    break;
            }
        }
        // Print weather report for the day
        printf("Weather Report for Day %d:\n", i + 1);
        for (int j = 0; j < num_cities; j++) {
            printf("In %s, the temperature is %d degrees Celsius.\n", cities[j].name, cities[j].temperature);
        }
    }
}

int main() {
    struct city cities[MAX_CITIES];
    int num_cities = 0;

    // Get user input for number of cities
    printf("How many cities do you want to simulate weather for? (Max %d): ", MAX_CITIES);
    scanf("%d", &num_cities);

    // Get user input for city names and temperatures
    for (int i = 0; i < num_cities; i++) {
        printf("Enter city name for city %d: ", i + 1);
        scanf("%s", cities[i].name);
        printf("Enter initial temperature for %s: ", cities[i].name);
        scanf("%d", &cities[i].temperature);
    }

    // Simulate weather for a year
    generate_weather(cities, num_cities, MAX_DAYS);

    return 0;
}